//
//  WeboramaPlugin.h
//  WeboramaPlugin
//
//  Created by Ludovic Riviere on 11/11/2015.
//  Copyright (c) 2015 Ludovic Riviere. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Cordova/CDVPlugin.h>

@interface WeboramaPlugin : CDVPlugin

- (void)conversionPing:(CDVInvokedUrlCommand *)command;
- (void)repeatableConversionPing:(CDVInvokedUrlCommand *)command;

- (void)trackerPing:(CDVInvokedUrlCommand *)command;
- (void)trackerPingUnique:(CDVInvokedUrlCommand *)command;

@end