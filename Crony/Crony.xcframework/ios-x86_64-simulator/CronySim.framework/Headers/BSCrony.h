//
//  BSCrony.h
//  Crony
//
//  Created by Suman Cherukuri on 11/30/18.
//  Copyright © 2018 Suman Cherukuri. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

extern NSString * _Nonnull const CRONY_VERSION;

typedef NS_ENUM(NSInteger, BSCronyMode) {
    BSCronyModePrompt,  // Display a dialog with Record, Replay, and Cancel options
    BSCronyModeRecord,  // Crony records a session
    BSCronyModeReplay,  // Crony replays a previously recorded session
    BSCronyModeCancel   // App runs normally
};

@protocol BSCronyDataDelegate

@required

- (void) sessionPackageCreated:(NSString * _Nonnull)sessionId;
- (void) sessionPackageDeleted:(NSString * _Nonnull)sessionId;

@end

@interface BSCronySettings : NSObject

@property (atomic, assign) BOOL onStartup;                  // YES
@property (atomic, assign) BOOL urlSession;                 // YES
@property (atomic, assign) BOOL wkWebView;                  // YES
@property (atomic, assign) BOOL screenshots;                // YES
@property (atomic, assign) BOOL video;                      // YES
@property (atomic, assign) BOOL viewLoads;                  // YES
@property (atomic, assign) BOOL nsLog;                      // YES
@property (atomic, assign) CGFloat networkCallThreshold;    // 2 secs
@property (atomic, assign) CGFloat aiThreshold;             // 1 sec
@property (atomic, assign) CGFloat viewLoadThreshold;       // 0.5 sec
@property (atomic, retain) NSString * _Nullable slackAuthToken;        // Use your Slack auth token to integrate Crony with your Slack channels
@property (atomic, retain) NSString * _Nullable jiraAuthToken;         // Use your Jira auth token to automatically create Jira tickets
@property (atomic, retain) NSString * _Nullable jiraHost;              // Your Jira host URL. For ex: https://crony-us.atlassian.net

+ (BSCronySettings *_Nonnull)defaultSettings;

@end

@interface BSCrony : NSObject

+ (BSCronySettings *_Nullable)currentSettings;
+ (void)setSettings:(BSCronySettings * _Nullable)cronySettings;

+ (void)initializeCrony:(BSCronyMode)cronyMode sessionId:(NSString * _Nullable)sessionId;
+ (BSCronyMode)cronyMode;

+ (BOOL)startRecording;
+ (void)stopRecording;
+ (BOOL)isRecording;

+ (BOOL)startReplaying:(NSString * _Nullable)sessionId;
+ (void)stopReplaying;
+ (BOOL)isReplaying;
+ (NSString *_Nullable)replayingSessionId;

+ (void)showA11YDetails;
+ (void)hideA11YDetails;
+ (NSDictionary *_Nonnull)a11yDetails:(BOOL)withScreenshot;

@end
