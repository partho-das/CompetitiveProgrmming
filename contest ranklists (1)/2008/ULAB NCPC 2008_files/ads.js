if (!window.Scribd) var Scribd = new Object();
if (!Scribd.Ads) Scribd.Ads = new Object();

Scribd.Ads.attributes = {};
Scribd.Ads.sent_attributes = [];

Scribd.Ads.addAttribute = function(name, value) {
  Scribd.Ads.attributes[name] = value;
};

Scribd.Ads.addUnit = function(name) {
  $H(Scribd.Ads.attributes).each(function(pair) {
    if (Scribd.Ads.sent_attributes.include(pair.key))
      return;
    GA_googleAddAttr(pair.key, pair.value);
    Scribd.Ads.sent_attributes.push(pair.key);
  });
  GA_googleAddSlot("ca-pub-7291399211842501", name);

  document.write('<div class="hideable_ad">');
  GA_googleFillSlot(name);
  document.write('</div>');
};

// this function is called by genserve (see templates/4gen_contents.html)
Scribd.Ads.addBetweenPageUnit = function(page_num) {
  if (Scribd.Ads.attributes['UserState'] == 'In')
    return;

  if (page_num == 1)
    Scribd.Ads.addUnit('Doc_Between_Top_FullBanner_679x90');
  else if (page_num % 2 == 1 && page_num <= 21)
    Scribd.Ads.addUnit('Doc_Between_Leaderboard_BTF_728x90_' + page_num);
};

Scribd.Ads.addRefreshUnit = function(name) {
  var attributes = $H(Scribd.Ads.attributes).map(function(pair) {
    return escape(pair.key) + '=' + escape(pair.value);
  }).join('&');
  var url_params = 'ad_unit=' + escape(name) + '&url=' + escape(window.location.href) + '&attributes=' + escape(attributes);
  var size = name.match(/.*_(\d+)x(\d+)$/);
  document.write('<div id="' + name + '_container" class="hideable_ad"></div>');
  Scribd.Ads.refreshIframe($(name + '_container'), size[1], size[2], url_params, 0);
};

Scribd.Ads.refreshIframe = function(container, width, height, url_params, skip) {
  if (Scribd.Ads.userIsActive) {
    if (container.hasChildNodes())
      container.childNodes[0].remove();

    var iframe = document.createElement('iframe');
    iframe.width = width;
    iframe.height = height;
    iframe.scrolling = 'no';
    iframe.frameBorder = 0;
    iframe.marginWidth = 0;
    iframe.marginHeight = 0;
    iframe.src = Scribd.Ads.cdn_path + 'ad_refresher.html#' + url_params + '&skip=' + skip;
    container.appendChild(iframe);
  }

  setTimeout(function() { Scribd.Ads.refreshIframe(container, width, height, url_params, skip + 1); }, Scribd.Ads.refreshInterval * 1000);
};

Scribd.Ads.userIsActive = false;
Scribd.Ads.inactivityTimer = null;
Scribd.Ads.idleTimeBeforeInactive = 60;
Scribd.Ads.refreshInterval = 60;

Scribd.Ads.onUserActivity = function() {
  Scribd.Ads.userIsActive = true;
  clearTimeout(Scribd.Ads.inactivityTimer);
  Scribd.Ads.inactivityTimer = setTimeout(Scribd.Ads.onUserInactivity, Scribd.Ads.idleTimeBeforeInactive * 1000);
};

Scribd.Ads.onUserInactivity = function() {
  Scribd.Ads.userIsActive = false;
};

Scribd.Ads.onUserActivity(); // we consider them active to start off

document.observe('mousemove', Scribd.Ads.onUserActivity);
document.observe('scroll', Scribd.Ads.onUserActivity);
