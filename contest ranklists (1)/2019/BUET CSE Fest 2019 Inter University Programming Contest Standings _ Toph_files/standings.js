!function(t){function e(e){for(var o,a,l=e[0],s=e[1],f=e[2],c=0,u=[];c<l.length;c++)a=l[c],r[a]&&u.push(r[a][0]),r[a]=0;for(o in s)Object.prototype.hasOwnProperty.call(s,o)&&(t[o]=s[o]);for(d&&d(e);u.length;)u.shift()();return i.push.apply(i,f||[]),n()}function n(){for(var t,e=0;e<i.length;e++){for(var n=i[e],o=!0,l=1;l<n.length;l++){var s=n[l];0!==r[s]&&(o=!1)}o&&(i.splice(e--,1),t=a(a.s=n[0]))}return t}var o={},r={9:0},i=[];function a(e){if(o[e])return o[e].exports;var n=o[e]={i:e,l:!1,exports:{}};return t[e].call(n.exports,n,n.exports,a),n.l=!0,n.exports}a.m=t,a.c=o,a.d=function(t,e,n){a.o(t,e)||Object.defineProperty(t,e,{enumerable:!0,get:n})},a.r=function(t){"undefined"!=typeof Symbol&&Symbol.toStringTag&&Object.defineProperty(t,Symbol.toStringTag,{value:"Module"}),Object.defineProperty(t,"__esModule",{value:!0})},a.t=function(t,e){if(1&e&&(t=a(t)),8&e)return t;if(4&e&&"object"==typeof t&&t&&t.__esModule)return t;var n=Object.create(null);if(a.r(n),Object.defineProperty(n,"default",{enumerable:!0,value:t}),2&e&&"string"!=typeof t)for(var o in t)a.d(n,o,function(e){return t[e]}.bind(null,o));return n},a.n=function(t){var e=t&&t.__esModule?function(){return t.default}:function(){return t};return a.d(e,"a",e),e},a.o=function(t,e){return Object.prototype.hasOwnProperty.call(t,e)},a.p="";var l=window.webpackJsonp=window.webpackJsonp||[],s=l.push.bind(l);l.push=e,l=l.slice();for(var f=0;f<l.length;f++)e(l[f]);var d=s;i.push([198,0]),n()}({198:function(t,e,n){"use strict";n.r(e);var o=n(0),r=n.n(o),i=n(89),a=n.n(i);n(199);r()(".float-thead").floatThead(),new a.a(r()(".standings-table")[0]),toph.syncer.on("sync",function(t){return r()(".float-thead").floatThead(),new a.a(r()(".standings-table")[0])})},199:function(t,e,n){var o;
/** @preserve jQuery.floatThead 2.1.2 - https://mkoryak.github.io/floatThead/ - Copyright (c) 2012 - 2018 Misha Koryak **/
// @license MIT
!function(t){t.floatThead=t.floatThead||{},t.floatThead.defaults={headerCellSelector:"tr:visible:first>*:visible",zIndex:1001,position:"auto",top:0,bottom:0,scrollContainer:function(e){return t([])},responsiveContainer:function(e){return t([])},getSizingRow:function(t,e,n){return t.find("tbody tr:visible:first>*:visible")},floatTableClass:"floatThead-table",floatWrapperClass:"floatThead-wrapper",floatContainerClass:"floatThead-container",copyTableClass:!0,autoReflow:!1,debug:!1,support:{bootstrap:!0,datatables:!0,jqueryUI:!0,perfectScrollbar:!0},floatContainerCss:{"overflow-x":"hidden"}};var e=function(){var e={},n=Object.prototype.hasOwnProperty;e.has=function(t,e){return n.call(t,e)},e.keys=Object.keys||function(t){if(t!==Object(t))throw new TypeError("Invalid object");var n=[];for(var o in t)e.has(t,o)&&n.push(o);return n};var o=0;return e.uniqueId=function(t){var e=++o+"";return t?t+e:e},t.each(["Arguments","Function","String","Number","Date","RegExp"],function(){var t=this;e["is"+t]=function(e){return Object.prototype.toString.call(e)=="[object "+t+"]"}}),e.debounce=function(t,e,n){var o,r,i,a,l;return function(){i=this,r=arguments,a=new Date;var s=function(){var f=new Date-a;f<e?o=setTimeout(s,e-f):(o=null,n||(l=t.apply(i,r)))},f=n&&!o;return o||(o=setTimeout(s,e)),f&&(l=t.apply(i,r)),l}},e}(),n="undefined"!=typeof MutationObserver,o=function(){for(var t=3,e=document.createElement("b"),n=e.all||[];t=1+t,e.innerHTML="\x3c!--[if gt IE "+t+"]><i><![endif]--\x3e",n[0];);return 4<t?t:document.documentMode}(),r=/Gecko\//.test(navigator.userAgent),i=/WebKit\//.test(navigator.userAgent);o||r||i||(o=11);var a=function(){if(i){var e=t("<div>").css("width",0).append(t("<table>").css("max-width","100%").append(t("<tr>").append(t("<th>").append(t("<div>").css("min-width",100).text("X")))));t("body").append(e);var n=0==e.find("table").width();return e.remove(),n}return!1},l=!r&&!o,s=t(window),f=r&&window.matchMedia;if(!window.matchMedia||f){var d=window.onbeforeprint,c=window.onafterprint;window.onbeforeprint=function(){d&&d(),s.triggerHandler("beforeprint")},window.onafterprint=function(){c&&c(),s.triggerHandler("afterprint")}}function u(e){var n=e[0].parentElement;do{if("visible"!=window.getComputedStyle(n).getPropertyValue("overflow"))break}while(n=n.parentElement);return n==document.body?t([]):t(n)}function h(t){window&&window.console&&window.console.error&&window.console.error("jQuery.floatThead: "+t)}function p(t){var e=t.getBoundingClientRect();return e.width||e.right-e.left}function v(){var t=document.createElement("scrolltester");t.style.cssText="width:100px;height:100px;overflow:scroll!important;position:absolute;top:-9999px;display:block",document.body.appendChild(t);var e=t.offsetWidth-t.clientWidth;return document.body.removeChild(t),e}function b(t,e,n){var o=n?"outerWidth":"width";if(a&&t.css("max-width")){var r=0;n&&(r+=parseInt(t.css("borderLeft"),10),r+=parseInt(t.css("borderRight"),10));for(var i=0;i<e.length;i++)r+=p(e.get(i));return r}return t[o]()}t.fn.floatThead=function(r){if(r=r||{},o<8)return this;var d=null;if(e.isFunction(a)&&(a=a()),e.isString(r)){var c=r,w=Array.prototype.slice.call(arguments,1),g=this;return this.filter("table").each(function(){var n=t(this),o=n.data("floatThead-lazy");o&&n.floatThead(o);var r=n.data("floatThead-attached");if(r&&e.isFunction(r[c])){var i=r[c].apply(this,w);void 0!==i&&(g=i)}}),g}var m=t.extend({},t.floatThead.defaults||{},r);if(t.each(r,function(n,o){n in t.floatThead.defaults||!m.debug||h("Used ["+n+"] key to init plugin, but that param is not an option for the plugin. Valid options are: "+e.keys(t.floatThead.defaults).join(", "))}),m.debug){var y=t.fn.jquery.split(".");1==parseInt(y[0],10)&&parseInt(y[1],10)<=7&&h("jQuery version "+t.fn.jquery+" detected! This plugin supports 1.8 or better, or 1.7.x with jQuery UI 1.8.24 -> http://jqueryui.com/resources/download/jquery-ui-1.8.24.zip")}return this.filter(":not(."+m.floatTableClass+")").each(function(){var r=e.uniqueId(),a=t(this);if(a.data("floatThead-attached"))return!0;if(!a.is("table"))throw new Error('jQuery.floatThead must be run on a table element. ex: $("table").floatThead();');n=m.autoReflow&&n;var c=a.children("thead:first"),w=a.children("tbody:first");if(0==c.length||0==w.length)return m.debug&&(0==c.length?h("The thead element is missing."):h("The tbody element is missing.")),a.data("floatThead-lazy",m),void a.unbind("reflow").one("reflow",function(){a.floatThead(m)});a.data("floatThead-lazy")&&a.unbind("reflow"),a.data("floatThead-lazy",!1);var g,y,T=!0,x={vertical:0,horizontal:0};e.isFunction(v)&&(v=v());var C=0;!0===m.scrollContainer&&(m.scrollContainer=u);var j=m.scrollContainer(a)||t([]),S=j.length>0,L=S?t([]):m.responsiveContainer(a)||t([]),H=ct(),_=null;"auto"===m.position?_=null:"fixed"===m.position?_=!1:"absolute"===m.position?_=!0:m.debug&&h('Invalid value given to "position" option, valid is "fixed", "absolute" and "auto". You passed: ',m.position),null==_&&(_=S);var z=a.find("caption"),I=1==z.length;if(I)var O="top"===(z.css("caption-side")||z.attr("align")||"top");var W=t("<fthfoot>").css({display:"table-footer-group","border-spacing":0,height:0,"border-collapse":"collapse",visibility:"hidden"}),$=!1,M=t([]),k=o<=9&&!S&&_,q=t("<table/>"),D=t("<colgroup/>"),P=a.children("colgroup:first"),R=!0;0==P.length&&(P=t("<colgroup/>"),R=!1);var E=t("<fthtr>").css({display:"table-row","border-spacing":0,height:0,"border-collapse":"collapse"}),F=t("<div>").css(m.floatContainerCss).attr("aria-hidden","true"),A=!1,N=t("<thead/>"),Q=t('<tr class="size-row" aria-hidden="true"/>'),U=t([]),G=t([]),J=t([]),V=t([]);N.append(Q),a.prepend(P),l&&(W.append(E),a.append(W)),q.append(D),F.append(q),m.copyTableClass&&q.attr("class",a.attr("class")),q.attr({cellpadding:a.attr("cellpadding"),cellspacing:a.attr("cellspacing"),border:a.attr("border")});var X=a.css("display");if(q.css({borderCollapse:a.css("borderCollapse"),border:a.css("border"),display:X}),S||q.css("width","auto"),"none"===X&&(A=!0),q.addClass(m.floatTableClass).css({margin:0,"border-bottom-width":0}),_){var Y=function(e,n){var o=e.css("position"),r=e;if(!("relative"==o||"absolute"==o)||n){var i={paddingLeft:e.css("paddingLeft"),paddingRight:e.css("paddingRight")};F.css(i),r=e.data("floatThead-containerWrap")||e.wrap(t("<div>").addClass(m.floatWrapperClass).css({position:"relative",clear:"both"})).parent(),e.data("floatThead-containerWrap",r),$=!0}return r};S?(M=Y(j,!0)).prepend(F):(M=Y(a),a.before(F))}else a.before(F);F.css({position:_?"absolute":"fixed",marginTop:0,top:_?0:"auto",zIndex:m.zIndex,willChange:"transform"}),F.addClass(m.floatContainerClass),ot();var B={"table-layout":"fixed"},K={"table-layout":a.css("tableLayout")||"auto"},Z=a[0].style.width||"",tt=a.css("minWidth")||"";function et(t){return t+".fth-"+r+".floatTHead"}function nt(){var e=0;if(c.children("tr:visible").each(function(){e+=t(this).outerHeight(!0)}),"collapse"==a.css("border-collapse")){var n=parseInt(a.css("border-top-width"),10);n>parseInt(a.find("thead tr:first").find(">*:first").css("border-top-width"),10)&&(e-=n/2)}Q.outerHeight(e),U.outerHeight(e)}function ot(){g=(e.isFunction(m.top)?m.top(a):m.top)||0,y=(e.isFunction(m.bottom)?m.bottom(a):m.bottom)||0}function rt(){if(!T){if(T=!0,_){var t=b(a,V,!0);t>M.width()&&a.css("minWidth",t)}a.css(B),q.css(B),q.append(c),w.before(N),nt()}}function it(){T&&(T=!1,_&&a.width(Z),N.detach(),a.prepend(c),a.css(K),q.css(K),a.css("minWidth",tt),a.css("minWidth",b(a,V)))}var at=!1;function lt(t){at!=t&&(at=t,a.triggerHandler("floatThead",[t,F]))}function st(t){_!=t&&(_=t,F.css({position:_?"absolute":"fixed"}))}function ft(){var e,n=function(){var e,n=c.find(m.headerCellSelector);if(R?e=P.find("col").length:(e=0,n.each(function(){e+=parseInt(t(this).attr("colspan")||1,10)})),e!==C){C=e;for(var o,r=[],i=[],a=[],s=0;s<e;s++)o=n.eq(s).text(),r.push('<th class="floatThead-col" aria-label="'+o+'"/>'),i.push("<col/>"),a.push(t("<fthtd>").css({display:"table-cell",height:0,width:"auto"}));i=i.join(""),r=r.join(""),l&&(E.empty(),E.append(a),V=E.find("fthtd")),Q.html(r),U=Q.find("th"),R||P.html(i),G=P.find("col"),D.html(i),J=D.find("col")}return e}();return function(){var t=F.scrollLeft();G=P.find("col");var r=function(t,e,n,o){return l?n:o?m.getSizingRow(t,e,n):e}(a,G,V,o);if(r.length==n&&n>0){if(!R)for(e=0;e<n;e++)G.eq(e).css("width","");it();var i=[];for(e=0;e<n;e++)i[e]=p(r.get(e));for(e=0;e<n;e++)J.eq(e).width(i[e]),G.eq(e).width(i[e]);rt()}else q.append(c),a.css(K),q.css(K),nt();F.scrollLeft(t),a.triggerHandler("reflowed",[F])}}function dt(t){var e=j.css("border-"+t+"-width"),n=0;return e&&~e.indexOf("px")&&(n=parseInt(e,10)),n}function ct(){return"auto"==L.css("overflow-x")}function ut(){var t,e=j.scrollTop(),n=0,o=I?z.outerHeight(!0):0,r=O?o:-o,l=F.height(),f=a.offset(),d=0,c=0;if(S){var u=j.offset();n=f.top-u.top+e,I&&O&&(n+=o),d=dt("left"),c=dt("top"),n-=c}else t=f.top-g-l+y+x.horizontal;var h=s.scrollTop(),p=s.scrollLeft(),v=function(){return(ct()?L:j).scrollLeft()||0},b=v();return function(u){H=ct();var w=a[0].offsetWidth<=0&&a[0].offsetHeight<=0;if(!w&&A)return A=!1,setTimeout(function(){a.triggerHandler("reflow")},1),null;if(w&&(A=!0,!_))return null;if("windowScroll"==u)h=s.scrollTop(),p=s.scrollLeft();else if("containerScroll"==u)if(L.length){if(!H)return;b=L.scrollLeft()}else e=j.scrollTop(),b=j.scrollLeft();else"init"!=u&&(h=s.scrollTop(),p=s.scrollLeft(),e=j.scrollTop(),b=v());if(!i||!(h<0||p<0)){if(k)st("windowScrollDone"==u);else if("windowScrollDone"==u)return null;var m,y;f=a.offset(),I&&O&&(f.top+=o);var T=a.outerHeight();if(S&&_){if(n>=e){var x=n-e+c;m=x>0?x:0,lt(!1)}else m=$?c:e,lt(!0);y=d}else!S&&_?(h>t+T+r?m=T-l+r:f.top>=h+g?(m=0,it(),lt(!1)):(m=g+h-f.top+n+(O?o:0),rt(),lt(!0)),y=b):S&&!_?(n>e||e-n>T?(m=f.top-h,it(),lt(!1)):(m=f.top+e-h-n,rt(),lt(!0)),y=f.left+b-p):S||_||(h>t+T+r?m=T+g-h+t+r:f.top>h+g?(m=f.top-h,rt(),lt(!1)):(m=g,lt(!0)),y=f.left+b-p);return{top:Math.round(m),left:Math.round(y)}}}}function ht(){var t=null,e=null,n=null;return function(r,i,l){if(null!=r&&(t!=r.top||e!=r.left)){if(8===o)F.css({top:r.top,left:r.left});else{var s="translateX("+r.left+"px) translateY("+r.top+"px)",f={"-webkit-transform":s,"-moz-transform":s,"-ms-transform":s,"-o-transform":s,transform:s,top:0};f[/rtl/i.test(document.documentElement.dir||"")?"right":"left"]=0,F.css(f)}t=r.top,e=r.left}i&&function(){var t=b(a,V,!0),e=H?L:j,n=e.length?p(e[0]):t,o="hidden"!=e.css("overflow-y")?n-x.vertical:n;if(F.width(o),S){var r=100*t/o;q.css("width",r+"%")}else q.outerWidth(t)}(),l&&nt();var d=(H?L:j).scrollLeft();_&&n==d||(F.scrollLeft(d),n=d)}}function pt(){if(j.length)if(m.support&&m.support.perfectScrollbar&&j.data().perfectScrollbar)x={horizontal:0,vertical:0};else{if("scroll"==j.css("overflow-x"))x.horizontal=v;else{var t=j.width(),e=b(a,V),n=o<r?v:0;x.horizontal=t-n<e?v:0}if("scroll"==j.css("overflow-y"))x.vertical=v;else{var o=j.height(),r=a.height(),i=t<e?v:0;x.vertical=o-i<r?v:0}}}pt();var vt=function(){ft()()};vt();var bt=ut(),wt=ht();wt(bt("init"),!0);var gt=e.debounce(function(){wt(bt("windowScrollDone"),!1)},1),mt=function(){wt(bt("windowScroll"),!1),k&&gt()},yt=function(){wt(bt("containerScroll"),!1)},Tt=e.debounce(function(){a.is(":hidden")||(pt(),ot(),vt(),bt=ut(),wt(bt("reflow"),!0,!0))},1),xt=function(){it()},Ct=function(){rt()},jt=function(t){t.matches?xt():Ct()},St=null;if(window.matchMedia&&window.matchMedia("print").addListener&&!f?(St=window.matchMedia("print")).addListener(jt):(s.on("beforeprint",xt),s.on("afterprint",Ct)),S?_?j.on(et("scroll"),yt):(j.on(et("scroll"),yt),s.on(et("scroll"),mt)):(L.on(et("scroll"),yt),s.on(et("scroll"),mt)),s.on(et("load"),Tt),function(t,n){if(8==o){var r=s.width(),i=e.debounce(function(){var t=s.width();r!=t&&(r=t,n())},1);s.on(t,i)}else s.on(t,e.debounce(n,1))}(et("resize"),function(){a.is(":hidden")||(ot(),pt(),vt(),bt=ut(),(wt=ht())(bt("resize"),!0,!0))}),a.on("reflow",Tt),m.support&&m.support.datatables&&function(t){if(t.dataTableSettings)for(var e=0;e<t.dataTableSettings.length;e++){var n=t.dataTableSettings[e].nTable;if(t[0]==n)return!0}return!1}(a)&&a.on("filter",Tt).on("sort",Tt).on("page",Tt),m.support&&m.support.bootstrap&&s.on(et("shown.bs.tab"),Tt),m.support&&m.support.jqueryUI&&s.on(et("tabsactivate"),Tt),n){var Lt=null;e.isFunction(m.autoReflow)&&(Lt=m.autoReflow(a,j)),Lt||(Lt=j.length?j[0]:a[0]),(d=new MutationObserver(function(t){for(var e=function(t){return t&&t[0]&&("THEAD"==t[0].nodeName||"TD"==t[0].nodeName||"TH"==t[0].nodeName)},n=0;n<t.length;n++)if(!e(t[n].addedNodes)&&!e(t[n].removedNodes)){Tt();break}})).observe(Lt,{childList:!0,subtree:!0})}a.data("floatThead-attached",{destroy:function(){var t=".fth-"+r;return it(),a.css(K),P.remove(),l&&W.remove(),N.parent().length&&N.replaceWith(c),lt(!1),n&&(d.disconnect(),d=null),a.off("reflow reflowed"),j.off(t),L.off(t),$&&(j.length?j.unwrap():a.unwrap()),S?j.data("floatThead-containerWrap",!1):a.data("floatThead-containerWrap",!1),a.css("minWidth",tt),F.remove(),a.data("floatThead-attached",!1),s.off(t),St&&St.removeListener(jt),xt=Ct=function(){},function(){return a.floatThead(m)}},reflow:function(){Tt()},setHeaderHeight:function(){nt()},getFloatContainer:function(){return F},getRowGroups:function(){return T?F.find(">table>thead").add(a.children("tbody,tfoot")):a.children("thead,tbody,tfoot")}})}),this}}((o=window.jQuery,t.exports&&!o&&(o=n(0)),o))},89:function(t,e,n){var o,r;o=n(0),r=function(){function t(t){var e;this.el=t,this.$el=o(this.el),this.$nav=o(".standings-table__nav",this.el),this.$el.on("mousemove",(e=this,function(){return e.show()})),this.hide(!0),o(window).on("resize",function(t){return function(){if(t._detectScrollbar(),t._adjustPosition(),!t.canScroll)return t.hide()}}(this)),o(window).on("scroll",function(t){return function(){return t._adjustPosition()}}(this)),this._detectScrollbar(),this._adjustPosition(),o(".navscroll__right",this.$el).on("click",function(t){return function(e){return e.preventDefault(),t.$el.stop().animate({scrollLeft:t.$el.scrollLeft()-256})}}(this)),o(".navscroll__left",this.$el).on("click",function(t){return function(e){return e.preventDefault(),t.$el.stop().animate({scrollLeft:t.$el.scrollLeft()+256})}}(this))}return t.prototype._detectScrollbar=function(){return this.canScroll=this.el.scrollWidth>this.$el.width()},t.prototype.show=function(){return this.canScroll&&this.$nav.fadeIn(),this._hideAfterDelay()},t.prototype.hide=function(t){if(!t)return this.$nav.fadeOut();this.$nav.hide()},t.prototype._hideAfterDelay=function(){return this.hideTimer&&clearTimeout(this.hideTimer),this.hideTimer=setTimeout((t=this,function(){return t.$nav.fadeOut()}),5e3);var t},t.prototype._adjustPosition=function(){var t,e,n,r;return r=Math.max(this.$el.offset().top-o(window).scrollTop(),0),t=document.body.scrollHeight-(this.$el.offset().top+this.$el.outerHeight()),e=Math.max(o(window).innerHeight()+o(window).scrollTop()-document.body.scrollHeight+t,0),n=o(window).height()-r-e,this.$nav.css({top:n/2+r})},t}(),t.exports=r}});