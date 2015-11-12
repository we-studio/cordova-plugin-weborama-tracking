![Cordova+Weborama](https://raw.githubusercontent.com/we-studio/cordova-plugin-weborama-tracking/master/logo.jpg)

Cordova plugin for [Weborama tracking](http://www.weborama.com).

## Installation

Add the following plugin to your Cordova/Ionic project:

    cordova plugin add https://github.com/we-studio/cordova-plugin-weborama-tracking.git

  
## Usage

```javascript
var options = {
    siteId: <your site id>,
    zoneId: <your zone id>,
    host: <your host>,
    customPath: <your custom path>
};
WeboramaTrackingPlugin.trackerPing(options);

// other methods
WeboramaTrackingPlugin.trackerPingUnique(options);
WeboramaTrackingPlugin.conversionPing(options);
WeboramaTrackingPlugin.repeatableConversionPing(options);
```

## TODO ##
- [x] iOS support
- [x] Android support
- [ ] available in Cordova plugins list


## Credits ##

This Cordova plugin is developed by [Westudio](http://westud.io) team empowered by [Wemanity](http://www.wemanity.com).

