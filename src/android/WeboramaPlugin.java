package io.westud.cordova.WeboramaPlugin;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;


public class WeboramaPlugin extends CordovaPlugin {

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {

        if ("conversionPing".equals(action)) {

            conversionPing(args, callbackContext);
            return true;

        } else if ("repeatableConversionPing".equals(action)) {

            repeatableConversionPing(args, callbackContext);
            return true;

        } else if ("trackerPing".equals(action)) {

            trackerPing(args, callbackContext);
            return true;

        } else if ("trackerPingUnique".equals(action)) {

            trackerPingUnique(args, callbackContext);
            return true;

        }

        return false;
    }

    private void conversionPing(JSONArray args, CallbackContext callbackContext) {
        try {
            JSONObject options = args.getJSONObject(0);

            WeboramaTrackingPlugin wboTracker = getParamsByBindingJSONObject(options);

            wboTracker.conversionPing();

            callbackContext.success();

        } catch (JSONException e) {
            callbackContext.error(e.getMessage());
        }
    }

    private void repeatableConversionPing(JSONArray args, CallbackContext callbackContext) {
        try {
            JSONObject options = args.getJSONObject(0);

            WeboramaTrackingPlugin wboTracker = getParamsByBindingJSONObject(options);

            wboTracker.conversionPing(true);

            callbackContext.success();
        } catch (JSONException e) {
            callbackContext.error(e.getMessage());
        }
    }

    private void trackerPing(JSONArray args, CallbackContext callbackContext) {
        try {
            JSONObject options = args.getJSONObject(0);

            WeboramaTrackingPlugin wboTracker = getParamsByBindingJSONObject(options);

            wboTracker.trackerPing();

            callbackContext.success();

        } catch (JSONException e) {
            callbackContext.error(e.getMessage());
        }
    }


    private void trackerPingUnique(JSONArray args, CallbackContext callbackContext) {
        try {
            JSONObject options = args.getJSONObject(0);

            WeboramaTrackingPlugin wboTracker = getParamsByBindingJSONObject(options);

            wboTracker.trackerPingUnique();

            callbackContext.success();

        } catch (JSONException e) {
            callbackContext.error(e.getMessage());
        }
    }


    private WeboramaTrackingPlugin getParamsByBindingJSONObject(JSONObject object) throws JSONException {
        int siteId = object.getInt("siteId");
        int zoneId = object.getInt("zoneId");
        String host = object.getString("host");

        WeboramaTrackingPlugin = new WeboramaTrackingPlugin(this.webView.getContext(), siteId, zoneId, host);



      //  JSONObject customParameters = object.getJSONObject("customParameters");


        /** generic parameters */
        if (object.has("customPath")) {
            String customPath = object.getString("customPath");
            wboTracker.customPath = customPath;
        }
//        if (object.has(customParameters)) {
//            wboTracker.customParameters = customParameters;
//        }
        if (object.has("useIpTracking")) {
            wboTracker.useIpTracking = object.getBoolean("useIpTracking");
        }

        return wboTracker;
    }

}