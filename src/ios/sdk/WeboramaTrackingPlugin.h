//
//  WeboramaTrackingPlugin.h
//  WeboramaTrackingPlugin
//
//  Created by Weborama on 10/28/13.
//  Copyright (c) 2013 Weborama. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SystemConfiguration/SystemConfiguration.h>
#import <CommonCrypto/CommonDigest.h>
#import <AdSupport/AdSupport.h>
#include <asl.h>

@interface WeboramaTrackingPlugin : NSObject {
    NSString * _host, * _URLScheme, * _deviceId;
}

/** @name Initializing a WeboramaTrackingPlugin Object */

/** Initializes and returns a WeboramaTrackingPlugin object having the given site and zone.
 
 @param site A value that specifies the id of ad publisher site.
 @param zone A value that specifies the id of ad publisher zone (conversion page).
 @return Returns an initialized WeboramaTrackingPlugin object or nil if the object could not be successfully initialized.
 */
- (id) initWithSite:(NSInteger)siteId
            andZone:(NSInteger)zoneId;


/** Initializes and returns a WeboramaTrackingPlugin object having the given site, zone and host.
 
 @param site A value that specifies the id of ad publisher site.
 @param zone A value that specifies the id of ad publisher zone (conversion page).
 @param zone A value that specifies the hostname that should be used, defaults to: 'webo.solution.weborama.fr'
 @return Returns an initialized WeboramaTrackingPlugin object or nil if the object could not be successfully initialized.
 */
- (id) initWithSite:(NSInteger)siteId
            andZone:(NSInteger)zoneId
            andHost:(NSString*)host;


/** @name Configuring the WeboramaTrackingPlugin */

/** Id of the publisher site.
 
 Setting the value of this property determines the id of the publisher site, so switching between publisher sites is possible. This value will be supplied to you by a Weborama employee.
 */
@property NSInteger site;

/** Id of the publisher page/zone.
 
 This value determines the zone/page of your site on which this tracking action will take place. This value will be supplied to you by a Weborama employee.
 */
@property NSInteger zone;

/** Specify a custom path that will process this request on the supplied host
 
 Defaults to '/fcgi-bin/dispatch.fcgi'.
 Please only change this property when instructed to do so by a Weborama employee.
 */
@property(unsafe_unretained) NSString * customPath;

/** Use IP tracking (optional, not recommended)
 
 Set this to true to stop using the IFA for tracking purposes.
 When using this parameter, please be consistent by setting it for every tracking call.
 */
@property(unsafe_unretained) BOOL useIpTracking;

/** Invoice ID (optional) */
@property(unsafe_unretained) NSString * invoiceId;

/** Client ID (optional) */
@property(unsafe_unretained) NSString * clientId;

/** Number of items (optional)
 
 Use this parameter to indicate how many items have been purchased
 */
@property(strong) NSNumber * numberOfItems;

/** Total amount (optional)
 
 Use this parameter to set the total price of the purchase
 */
@property(strong) NSNumber * totalAmount;

/** Custom parameter (optional)
 
 This parameter gives you the possibility to add your own parameters to the conversion call.
 e.g for fixed params:
 @{
 @"N1":@1,
 @"N2":@2,
 @"N3":@3,
 @"T1":@"string value",
 @"T2":@"string value2"
 }
 
 e.g. for free params
 @{
 @"string":@"Weborama",
 @"boolean":@YES,
 @"number":@5,
 @"float":@5.50
 };
 
 */
@property(strong) NSDictionary * customParameters;


/** @name Using the WeboramaTrackingPlugin */

/** Makes a call to a prepared conversion beacon */
- (void) conversionPing;

/** Makes a call to a prepared conversion beacon with a configurable option: isRepeatable. Setting this Boolean to false (default) will cause the conversionPing to be executed only once per app install.  */
- (void) conversionPing:(BOOL)isRepeatable;

/** Makes a call to a prepared tracker beacon for analytics purposes */
- (void) trackerPing;

/** Makes a call to a prepared tracker beacon for analytics purposes. Calling this method instead of the regular `trackerPing` will ensure that this tracker will only be installed once per app install. */
- (void) trackerPingUnique;

@end