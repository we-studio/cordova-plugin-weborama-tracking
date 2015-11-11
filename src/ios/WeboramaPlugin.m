//
//  WeboramaPlugin.m
//  WeboramaPlugin
//
//  Created by Ludovic Riviere on 11/11/2015.
//  Copyright (c) 2015 Ludovic Riviere. All rights reserved.
//

#import "WeboramaPlugin.h"
#import "WeboramaTrackingPlugin.h"

@interface WeboramaPlugin ()

- (WeboramaTrackingPlugin *)pluginWithDictionary:(NSDictionary *)dictionary;

@end

@implementation WeboramaPlugin

#pragma mark - Private

- (WeboramaTrackingPlugin *)pluginWithDictionary:(NSDictionary *)dictionary
{
    NSInteger siteId = [dictionary[@"siteId"] integerValue];
    NSInteger zoneId = [dictionary[@"zoneId"] integerValue];
    NSString *host = dictionary[@"host"];
    
    WeboramaTrackingPlugin *wboTracker;
    wboTracker = [[WeboramaTrackingPlugin alloc] initWithSite:siteId
                                                      andZone:zoneId
                                                      andHost:host];
    
    NSString *customPath = dictionary[@"customPath"];
    if (customPath) {
        wboTracker.customPath = customPath;
    }
    
    NSDictionary *customParameters = dictionary[@"customParameters"];
    if (customParameters) {
        wboTracker.customParameters = customParameters;
    }
    
    BOOL useIpTracking = [dictionary[@"useIpTracking"] boolValue];
    if (useIpTracking) {
        wboTracker.useIpTracking = YES;
    }
    
    return wboTracker;
}

#pragma mark - Public

- (void)conversionPing:(CDVInvokedUrlCommand *)command
{
    NSDictionary *options = [command.arguments objectAtIndex:0];
    WeboramaTrackingPlugin *wboTracker = [self pluginWithDictionary:options];
    [wboTracker conversionPing];
}

- (void)repeatableConversionPing:(CDVInvokedUrlCommand *)command
{
    NSDictionary *options = [command.arguments objectAtIndex:0];
    WeboramaTrackingPlugin *wboTracker = [self pluginWithDictionary:options];
    [wboTracker conversionPing:YES];
}

- (void)trackerPing:(CDVInvokedUrlCommand *)command
{
    NSDictionary *options = [command.arguments objectAtIndex:0];
    WeboramaTrackingPlugin *wboTracker = [self pluginWithDictionary:options];
    [wboTracker trackerPing];
}

- (void)trackerPingUnique:(CDVInvokedUrlCommand *)command
{
    NSDictionary *options = [command.arguments objectAtIndex:0];
    WeboramaTrackingPlugin *wboTracker = [self pluginWithDictionary:options];
    [wboTracker trackerPingUnique];
}

@end