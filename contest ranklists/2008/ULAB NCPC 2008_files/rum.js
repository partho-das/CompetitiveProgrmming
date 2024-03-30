// Copyright 2010 Google Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//      http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// 
// See the source code here:
//      http://code.google.com/p/episodes/

// Don't overwrite pre-existing instances of the object (esp. for older browsers).
var NR_QUEUE = [];

if (typeof(window.NREUMQ) !== "undefined" ) {
  NR_QUEUE = NREUMQ;
}
else if (typeof(window.EPISODES) !== "undefined" ) {
	NR_QUEUE = EPISODES.q;
}
else if (typeof(window.NREUM) !== "undefined") {
	NR_QUEUE = NREUM.q;
}

var NREUM = NREUM || {};

NREUM.q = NR_QUEUE;

NREUM.targetOrigin = document.location.protocol + "//" + document.location.host;

// CUSTOMIZE THESE VARIABLES!!
NREUM.version = 11;      // CHANGE THIS VERSION NUMBER WHEN THIS FILE CHANGES
NREUM.autorun = ( "undefined" !== typeof(NREUM.autorun) ? NREUM.autorun : true );


NREUM.init = function() {
  NREUM.bDone = false;
  NREUM.cycle = 0;
  NREUM.logging = false;
  NREUM.contentLoadFired = false;
  NREUM.marks = {};
  NREUM.measures = {};
  NREUM.starts = {};  // We need to save the starts so that given a measure we can say the epoch times that it began and ended.
  NREUM.findStartTime();
  NREUM.load = null;
  
  // hook both beforeunload and pagehide - not all browsers support unload (like iPad Safari)
  NREUM.addEventListener("beforeunload", NREUM.beforeUnload, false);
  NREUM.addEventListener("pagehide", NREUM.beforeUnload, false);

  // NEWRELIC
  // Process any commands that have been queued up while episodes.js loaded asynchronously.
  NREUM.processQ();
	
  NREUM.beacon = null;
  NREUM.licenseKey = null;
  NREUM.applicationID = null;
  NREUM.transactionName = null;
  NREUM.txnParam = null; // parameter name for web transaction name - can be raw (t) or obfuscated (to)
  NREUM.unloaded = false; // flag indicating that the unload cookie has alreay been written

  if (document.readyState === "complete") {
    NREUM.domContentLoaded();
  }
  else {
		if ("undefined" !== typeof(document.addEventListener)) {
		  document.addEventListener("DOMContentLoaded", NREUM.domContentLoaded, false);
	  }
		else if ("undefined" !== typeof(document.attachEvent)) {
			document.attachEvent("onreadystatechange", NREUM.readyStateChange);
		}
  }
	
  if (NREUM.load || document.loaded) {
    NREUM.onload();
  }
  else {
    NREUM.addEventListener("load", NREUM.onload, false);
  }
};


// Process any commands in the queue.
// The command queue is used to store calls to the API before the full script has been loaded.
NREUM.processQ = function() {
	
	var len = NREUM.q.length;
	var aParams;
	var cmd;
	var i;
	
  for (i = 0; i < len; i++ ) {
    aParams = NREUM.q[i];
    cmd = aParams[0];
    if ( "mark" === cmd ) {
      NREUM.mark(aParams[1], aParams[2]);
    }
    else if ( "measure" === cmd ) {
      NREUM.measure(aParams[1], aParams[2], aParams[3]);
    }
    else if ( "done" === cmd ) {
      NREUM.done(aParams[1]);
    }
		else if (("nrf" === cmd) || ("nrfinish" === cmd)) {
			NREUM.nrfinish("t", aParams[1], aParams[2], aParams[3], aParams[4], aParams[5], aParams[6], aParams[7]);
		} 
		else if (("nrf2" === cmd) || ("nrfinish2" === cmd)) {
			NREUM.nrfinish("to", aParams[1], aParams[2], aParams[3], aParams[4], aParams[5], aParams[6], aParams[7]);
		}
		else if ( "load" === cmd) {
		  NREUM.load = aParams[1];
		}
		else {
      NREUM.dprint("Unknown queue command " + cmd);  
    }
  }
};



NREUM.nrfinish = function(txnParam, beaconHost, licenseKey, appID, pageName, queue_time, app_time, dom_end_time) {
	
  NREUM.dprint("NREUM: finish data received");
	
  NREUM.txnParam = txnParam;
  NREUM.beacon = beaconHost;
  NREUM.licenseKey = licenseKey;
  NREUM.applicationID = appID;
  NREUM.transactionName = pageName;

  NREUM.measures.qt = queue_time;
  NREUM.measures.ap = app_time;
  NREUM.dom_end_time = dom_end_time;
};


// Set a time marker (typically the beginning of an episode).
NREUM.mark = function(markName, markTime) {
  NREUM.dprint("NREUM.mark: " + markName + ", " + markTime);

  if ( ! markName) {
    NREUM.dprint("Error: markName is undefined in NREUM.mark.");
    return;
  }

  NREUM.marks[markName] = parseInt(markTime || new Date().getTime(), 10);

  // Special marks that we look for:
  if ( "firstbyte" === markName ) {
    NREUM.measure("be", "starttime", "firstbyte");
    NREUM.dom_start_time = NREUM.marks["firstbyte"];
  }
  else if ( "onload" === markName ) {
    NREUM.measure("fe", "firstbyte", "onload");
  }
  else if ("domContent" === markName) {
    NREUM.measure("dc", "firstbyte", "domContent");
  }
};


// Measure an episode.
NREUM.measure = function(episodeName, startNameOrTime, endNameOrTime) {
  NREUM.dprint("NREUM.measure: " + episodeName + ", " + startNameOrTime + ", " + endNameOrTime);

  if ( ! episodeName) {
    NREUM.dprint("Error: episodeName is undefined in NREUM.measure.");
    return;
  }

  var startEpochTime;
  if ( "undefined" === typeof(startNameOrTime) ) {
    if ( "number" === typeof(NREUM.marks[episodeName]) ) {
      // If no startName is specified, then use the episodeName as the start mark.
      startEpochTime = NREUM.marks[episodeName];
    }
    else {
      // Create a "measure" that is this exact point in time?
      startEpochTime = new Date().getTime();
    }
  }
  else if ( "number" === typeof(NREUM.marks[startNameOrTime]) ) {
    // If a mark with this name exists, use that.
    startEpochTime = NREUM.marks[startNameOrTime];
  }
  else if ( "number" === typeof(startNameOrTime) ) {
    // Assume a specific epoch time is provided.
    startEpochTime = startNameOrTime;
  }
  else {
    NREUM.dprint("Error: unexpected startNameOrTime in NREUM.measure: " + startNameOrTime);
    return;
  }

  var endEpochTime;
  if ( "undefined" === typeof(endNameOrTime) ) {
    endEpochTime = new Date().getTime();
  }
  else if ( "number" === typeof(NREUM.marks[endNameOrTime]) ) {
    // If a mark with this name exists, use that.
    endEpochTime = NREUM.marks[endNameOrTime];
  }
  else if ( "number" === typeof(endNameOrTime) ) {
    endEpochTime = endNameOrTime;
  }
  else {
    NREUM.dprint("NREUM: Error: unexpected endNameOrTime in NREUM.measure: " + endNameOrTime);
    return;
  }

  NREUM.starts[episodeName] = parseInt(startEpochTime, 10);
  NREUM.measures[episodeName] = parseInt(endEpochTime - startEpochTime, 10);
};


// In the case of Ajax or post-onload episodes, call done to signal the end of episodes.
NREUM.done = function(callback) {
  NREUM.bDone = true;

  NREUM.mark("done");

  if ( NREUM.autorun ) {
    NREUM.sendBeacon();
  }

  if ( "function" === typeof(callback) ) {
    callback();
  }
};


// Return an object of mark names and their corresponding times.
NREUM.getMarks = function() {
  return NREUM.marks;
};


// Return an object of episode names and their corresponding durations.
NREUM.getMeasures = function() {
  return NREUM.measures;
};


// Return an object of episode names and their corresponding start times.
// This is needed so that we can determine the start and end time of a duration.
NREUM.getStarts = function() {
  return NREUM.starts;
};


// NEWRELIC
NREUM.sendBeacon = function() {

  NREUM.processQ();
  NREUM.domContentLoaded();
	
  if ((NREUM.licenseKey === null) || (NREUM.applicationID === null)) {
      NREUM.dprint('NREUM: licenseKey or applicationID has not been set');
      return;
  }

  // This is a more accurate measure of DOM processing time, use it if it exists
  // On 9/1/2011 remove the domcontentready event listener
  if (NREUM.dom_end_time && NREUM.dom_start_time) {
    NREUM.dprint("NREUM: picking up DOM processing time from embedded JS");
    NREUM.mark("domContent", NREUM.dom_end_time);
  }


  // This is a more accurate measure of the load event
  if (NREUM.load) {
    NREUM.dprint("NREUM: picking up load event time from embedded JS");
    NREUM.mark("onload", NREUM.load);
  }
  
  var measures = NREUM.getMeasures();
  
  var sTimes = "";
	var key;
	
  for ( key in measures ) {
    sTimes += key + '=' + measures[key] + '&';
  }
	
	var url;

  if ( sTimes ) {
    url = ((("http:"===document.location.protocol)?"http:":"https:") + '//' +
               NREUM.beacon + '/1/' +                            // the protocol version
               NREUM.licenseKey);
               
    url += '?a=' + NREUM.applicationID + '&';                     // Application ID
    url += sTimes;
    
    // If the web transaction metric name is
    // known then pass it as query parameter.
    if (NREUM.transactionName !== null && NREUM.transactionName.length > 0) {
        url += (NREUM.txnParam + '=' + encodeURIComponent(NREUM.transactionName));
				url += ('&v=' + NREUM.version);
    }

    var img = new Image();
    img.src = url;
    
    NREUM.dprint('NREUM: (new) data sent', url);
  }
};

// NREUM.inlineHit(request_name, queue_time, app_time, total_be_time, dom_time, fe_time)
//
// request_name - the "web page" name or service name
// queue_time - the amount of time spent in the app tier queue
// app_time - the amount of time spent in the application code
// total_be_time - the total roundtrip time of the remote service call
// dom_time - the time spent processing the result of the service call (or user defined)
// fe_time - the time spent rendering the result of the service call (or user defined)
//
NREUM.inlineHit = function(request_name, queue_time, app_time, total_be_time, dom_time, fe_time)
{
	  NREUM.cycle += 1;
		
	  if ((NREUM.licenseKey === null) || (NREUM.applicationID === null)) {
	      NREUM.dprint('NREUM: licenseKey or applicationID has not been set');
	      return;
	  }

    img = new Image();
				
    url = ((("http:"===document.location.protocol)?"http:":"https:") + '//' +
               NREUM.beacon + '/1/' +                            // the protocol version
               NREUM.licenseKey);
               
    url += '?a=' + NREUM.applicationID + '&';                     // Application ID
    url += 't=' + request_name + "&";
    url += 'qt=' + queue_time + "&";
		url += 'ap=' + app_time + "&";
    url += 'be=' + total_be_time + "&";
    url += 'dc=' + dom_time + "&";
		url += 'fe=' + fe_time + "&";
    url += 'c=' + NREUM.cycle;
				
    img.src = url;

    NREUM.dprint('NREUM Inline: ' + url);
};


// Use various techniques to determine the time at which this page started.
NREUM.findStartTime = function() {
  var startTime = NREUM.findStartWebTiming() || NREUM.findStartGToolbar() || NREUM.findStartCookie();
  if ( startTime ) {
    NREUM.mark("starttime", startTime);
  }
	else {
		NREUM.dprint("NREUM: Error: couldn't find a start time");
	}
	
};


// Find the start time from the Web Timing "performance" object.
// http://test.w3.org/webperf/specs/NavigationTiming/
// http://blog.chromium.org/2010/07/do-you-know-how-slow-your-web-page-is.html
NREUM.findStartWebTiming = function() {
  var startTime;

  var performance = window.performance || window.mozPerformance || window.msPerformance || window.webkitPerformance;
 
  if ( "undefined" !== typeof(performance) && "undefined" !== typeof(performance.timing) && "undefined" !== typeof(performance.timing.navigationStart) ) {
    startTime = performance.timing.navigationStart;
    NREUM.dprint("NREUM.findStartWebTiming: startTime = " + startTime);
  }

  return startTime;
};


// Find the start time from the Google Toolbar.
// http://ecmanaut.blogspot.com/2010/06/google-bom-feature-ms-since-pageload.html
NREUM.findStartGToolbar = function() {
  var startTime;

  try {
  	if (window.external && window.external.pageT) {
  		startTime = (new Date().getTime()) - window.external.pageT;
  	}
  	else 
  		if (window.gtbExternal && window.gtbExternal.pageT) {
  			startTime = (new Date().getTime()) - window.gtbExternal.pageT();
  		}
  		else 
  			if (window.chrome && window.chrome.csi) {
  				startTime = (new Date().getTime()) - window.chrome.csi().pageT;
  			}
  	
  	if (startTime) {
  		NREUM.dprint("NREUM.findStartGToolbar: startTime = " + startTime);
  	}
  } catch (ex) {
  	// ignore when toolbar/GWT not installed properly
  }
  
  return startTime;
};


// Find the start time based on a cookie set by Episodes in the unload handler.
NREUM.findStartCookie = function() {
  var aCookies = document.cookie.split(' ');
	var i, j;
	
  for ( i = 0; i < aCookies.length; i++ ) {
    if ( 0 === aCookies[i].indexOf("NREUM=") ) {
	  var startPage, referrerPage;
      var aSubCookies = aCookies[i].substring("NREUM=".length).split('&');
      var startTime, bReferrerMatch;
      for ( j = 0; j < aSubCookies.length; j++ ) {
        if ( 0 === aSubCookies[j].indexOf("s=") ) {
          startTime = aSubCookies[j].substring(2);
        }
		else if ( 0 === aSubCookies[j].indexOf("p=") ) {
		  referrerPage = aSubCookies[j].substring(2);
		  // if the sub-cookie is not the last cookie it will have a trailing ';'
		  if (referrerPage.charAt(referrerPage.length - 1) === ";") {
            referrerPage = referrerPage.substr(0, referrerPage.length - 1);
          }
		}
        else if ( 0 === aSubCookies[j].indexOf("r=") ) {
          startPage = aSubCookies[j].substring(2);
		  // if the sub-cookie is not the last cookie it will have a trailing ';'
		  if (startPage.charAt(startPage.length - 1) === ";") {
            startPage = startPage.substr(0, startPage.length - 1);
          }
        }
      }
	  if (startPage) {
        var docReferrer = encodeURIComponent(document.referrer);
		bReferrerMatch = (docReferrer === startPage);
		if (!bReferrerMatch) {
		  // Navigation did not start at the page that was just exited, check for re-load
		  // (i.e. the page just exited is the current page and the referring pages match)
		  bReferrerMatch = encodeURIComponent(document.location) === startPage && docReferrer === referrerPage;
		}
      }
      if ( bReferrerMatch && startTime ) {
        NREUM.dprint("NREUM.findStartCookie: startTime = " + startTime);
        return startTime;
      }
    }
  }

  return undefined;
};



// Set a cookie when the page unloads. Consume this cookie on the next page to get a "start time".
// Doesn't work in some browsers (Opera).
NREUM.beforeUnload = function(e) {
	if (!NREUM.unloaded) {
		var exp = new Date();
		exp.setTime(exp.getTime()+60000); // expire in 60 seconds
		document.cookie = "NREUM=s=" + Number(new Date()) + "&r=" + encodeURIComponent(document.location) + "&p=" + encodeURIComponent(document.referrer) + "; expires=" + exp.toGMTString() + "; path=/";
  		NREUM.unloaded = true;
	}
};


// When the page is done do final wrap-up.
NREUM.onload = function(e) {
  NREUM.mark("onload");

  if ( NREUM.autorun ) {
    NREUM.done();
  }
};

// Mark the DOM Content loaded time
NREUM.domContentLoaded = function(e) {
  if (!NREUM.contentLoadFired) {
    NREUM.mark("domContent", new Date().getTime());
    NREUM.contentLoadFired = true;
  }
};

NREUM.readyStateChange = function(e) {	
  if (document.readyState === "complete") {
    NREUM.domContentLoaded();
  }
};

// Helper function to draw a picture of the Episodes.
// Sets the innerHTML of parent.
NREUM.drawEpisodes = function(parent, bMarks) {
  if ( ! parent ) {
    return;
  }
  if ( "undefined" === typeof(bMarks) ) {
    bMarks = 1;
  }

  // Put the episodes (and marks) in order by start time and duration.
  // Create an array that we'll sort with special function.
  var starts = NREUM.getStarts();
  var measures = NREUM.getMeasures();
  var marks = NREUM.getMarks();
  var aEpisodes = []; // each element is an array: [start, end, name]
  var episodeName;
	var start;
	
  for ( episodeName in measures ) {
    if ( measures.hasOwnProperty(episodeName) ) {
      start = starts[episodeName];
      aEpisodes.push([ start, start + measures[episodeName], episodeName ]);
    }
  }
  for ( episodeName in marks ) {
    if ( marks.hasOwnProperty(episodeName) ) {
      if ( "undefined" === typeof(measures[episodeName]) ) {
        // Only add the mark if it is NOT an episode.
        start = marks[episodeName];
        aEpisodes.push([ start, start, episodeName ]);
      }
    }
  }
  aEpisodes.sort(NREUM.sortEpisodes);

  // Find start and end of all episodes.
  var tFirst = aEpisodes[0][0];
  var tLast = aEpisodes[0][1];
  var len = aEpisodes.length;
	var i;
	
  for ( i = 1; i < len; i++ ) {
    if ( aEpisodes[i][1] > tLast ) {
      tLast = aEpisodes[i][1];
    }
  }

  // Create HTML to represent the episodes.
  var nPixels = parent.clientWidth || parent.offsetWidth;
  var PxlPerMs = nPixels / (tLast - tFirst);
  var sHtml = "";
	
  for ( i = 0; i < aEpisodes.length; i++ ) {
    start = aEpisodes[i][0];
    var end = aEpisodes[i][1];
    var delta = end - start;
    episodeName = aEpisodes[i][2];
    var leftPx = parseInt(PxlPerMs * (start - tFirst), 10) + 40;
    var widthPx = parseInt(PxlPerMs * delta, 10);
    sHtml += '<div style="font-size: 10pt; position: absolute; left: ' + leftPx + 
        'px; top: ' + (i*30) + 'px; width: ' + widthPx + 'px; height: 16px;">' +
            '<div style="background: #EEE; border: 1px solid; padding-bottom: 2px;"><nobr style="padding-left: 4px;">' + episodeName + 
      ( 0 < delta ? ' - ' + delta + 'ms' : '' ) +
      '</nobr></div></div>\n';
  }

  parent.innerHTML = sHtml;
};


NREUM.sortEpisodes = function(a, b) {
  if ( a[0] === b[0] ) {
    if ( a[1] === b[1] ) {
      return 0;
    }
    if ( a[1] > b[1] ) {
      return -1;
    }
    return 1;
  }
  if ( a[0] < b[0] ) {
    return -1;
  }

  return 1;
};



// Wrapper for addEventListener and attachEvent.
NREUM.addEventListener = function(sType, callback, bCapture) {
  if ( "undefined" !== typeof(window.attachEvent) ) {
    return window.attachEvent("on" + sType, callback);
  }
  else if ( window.addEventListener ){
    return window.addEventListener(sType, callback, bCapture);
  }
};


// Wrapper for debug log function.
// console logging disabled for GA
if ( "undefined" !== typeof(console) && "undefined" !== typeof(console.log) ) {
  NREUM.dprint = function(msg) { 
  	if (NREUM.logging) {
  	  console.log(msg);
  	}
  };
}
else {
  NREUM.dprint = function(msg) { };
}


NREUM.init();
