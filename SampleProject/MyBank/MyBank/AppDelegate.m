//
//  AppDelegate.m
//  LinkDemo-ObjC
//
//  Copyright © 2017 Plaid Inc. All rights reserved.
//

#import <LinkKit/LinkKit.h>

#import "AppDelegate.h"
#import "BSCrony.h"

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [BSCrony initializeCrony:BSCronyModeUnknown sessionId:nil];
    #if USE_CUSTOM_CONFIG
        [self setupPlaidLinkWithCustomConfiguration];
    #else
        [self setupPlaidLinkWithSharedConfiguration];
    #endif
    return YES;
}

#pragma mark Plaid Link setup with shared configuration from Info.plist
- (void)setupPlaidLinkWithSharedConfiguration {
    // <!-- SMARTDOWN_SETUP_SHARED -->
    // With shared configuration from Info.plist
    [PLKPlaidLink setupWithSharedConfiguration:^(BOOL success, NSError * _Nullable error) {
        if (success) {
            // Handle success here, e.g. by posting a notification
            NSLog(@"Plaid Link setup was successful");
            [[NSNotificationCenter defaultCenter] postNotificationName:@"PLDPlaidLinkSetupFinished" object:self];
        }
        else {
            NSLog(@"Unable to setup Plaid Link due to: %@", [error localizedDescription]);
        }
    }];
    // <!-- SMARTDOWN_SETUP_SHARED -->
}


#pragma mark Plaid Link setup with custom configuration
- (void)setupPlaidLinkWithCustomConfiguration {

    // <!-- SMARTDOWN_SETUP_CUSTOM -->
    // With custom configuration
    PLKConfiguration* linkConfiguration;
    @try {
        linkConfiguration = [[PLKConfiguration alloc] initWithKey:@"<#YOUR_PLAID_PUBLIC_KEY#>"
                                                              env:PLKEnvironmentDevelopment
                                                          product:PLKProductAuth];
        linkConfiguration.clientName = @"Link Demo";
        [PLKPlaidLink setupWithConfiguration:linkConfiguration completion:^(BOOL success, NSError * _Nullable error) {
            if (success) {
                // Handle success here, e.g. by posting a notification
                NSLog(@"Plaid Link setup was successful");
                [[NSNotificationCenter defaultCenter] postNotificationName:@"PLDPlaidLinkSetupFinished" object:self];
            }
            else {
                NSLog(@"Unable to setup Plaid Link due to: %@", [error localizedDescription]);
            }
        }];
    } @catch (NSException *exception) {
        NSLog(@"Invalid configuration: %@", exception);
    }
    // <!-- SMARTDOWN_SETUP_CUSTOM -->
}

- (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window {
    return UIInterfaceOrientationMaskPortrait | UIInterfaceOrientationMaskLandscapeLeft | UIInterfaceOrientationMaskLandscapeRight;
}

@end
