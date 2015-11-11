var argscheck = require('cordova/argscheck'),
        exec = require('cordova/exec');
    
    var wtpExport = {};
    
    /**
     * set options: 
     * {
     *   siteId: (integer),
     *   zoneId: (integer),
     *   host: (string),
     *   customPath: (string|null),
     *   customParameters: (object|null),
     *   useIpTracking: (true|false)
     * }
     */
    
    
    wtpExport.conversionPing = function(options) {
        
        var successCallback = function(winParam) {
            
        };
        var failureCallback = function(error) {
            
        };
        
        cordova.exec(successCallback, failureCallback, 'WeboramaPlugin', 'conversionPing', [options]);
    };
    
    wtpExport.repeatableConversionPing = function(options) {
        
        var successCallback = function(winParam) {
            
        };
        var failureCallback = function(error) {
            
        };
        
        cordova.exec(successCallback, failureCallback, 'WeboramaPlugin', 'repeatableConversionPing', [options]);
    };
    
    wtpExport.trackerPing = function(options) {
        
        var successCallback = function(winParam) {
            
        };
        var failureCallback = function(error) {
            
        };
        
        cordova.exec(successCallback, failureCallback, 'WeboramaPlugin', 'trackerPing', [options]);
    };
    
    wtpExport.trackerPingUnique = function(options) {
        
        var successCallback = function(winParam) {
            
        };
        var failureCallback = function(error) {
            
        };
        
        cordova.exec(successCallback, failureCallback, 'WeboramaPlugin', 'trackerPingUnique', [options]);
    };
    
    module.exports = wtpExport;