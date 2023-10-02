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

/*
 * Crony Mode
 */
typedef NS_ENUM(NSInteger, BSCronyMode) {
    BSCronyModeNone,    // App runs normally
    BSCronyModePrompt,  // Display a dialog with Record, Replay, and Cancel options
    BSCronyModeRecord,  // Crony records a session
    BSCronyModeReplay   // Crony replays a previously recorded session
};

/*
 * Use this to set the action when the device is shaken
 */
typedef NS_ENUM(NSInteger, BSCronyShakeAction) {
    BSCronyShakeActionNone,     // Nothing happens
    BSCronyShakeActionSlack,    // Shows Slack dialog
    BSCronyShakeActionJira,     // Shows Jira dialog
    BSCronyShakeActionShare,    // Shows share action sheet
    BSCronyShakeActionShowCrony // Shows Crony
};

typedef NS_ENUM(NSInteger, BSCScreenRecordingStatus);

@protocol BSCronyDataDelegate

@required
- (void) sessionPackageCreated:(NSString * _Nonnull)sessionId;
- (void) sessionPackageDeleted:(NSString * _Nonnull)sessionId;

@end

@interface BSCronySettings : NSObject <NSSecureCoding>

@property (atomic, assign) BOOL onStartup;                  // YES
@property (atomic, assign) BOOL urlSession;                 // YES
@property (atomic, assign) BOOL wkWebView;                  // NO
@property (atomic, assign) BOOL screenshots;                // YES
@property (atomic, assign) BOOL video;                      // YES
@property (atomic, assign) BOOL viewLoads;                  // YES
@property (atomic, assign) BOOL nsLog;                      // YES
@property (atomic, assign) BOOL displayCrony;               // YES
@property (atomic, assign) BOOL userGestures;               // YES
@property (atomic, assign) BOOL ai;                         // YES
@property (atomic, assign) BOOL performance;                // YES
@property (atomic, assign) BOOL crashLogs;                  // YES
@property (atomic, assign) BOOL replay;                     // NO
@property (atomic, assign) BOOL uiControls;                 // YES
@property (atomic, assign) BOOL appCrawl;                      // NO


@property (atomic, assign) CGFloat networkCallThreshold;    // 2 secs
@property (atomic, assign) CGFloat aiThreshold;             // 1 sec
@property (atomic, assign) CGFloat viewLoadThreshold;       // 0.5 sec

@property (atomic, assign) BSCronyShakeAction shakeAction;  // BSCronyShakeActionNone
/*
 * Setting this to YES hides all the Crony functionality except
 * the draw controleer with Slack and Jira integratiuons
 */
@property (atomic, assign) BOOL integrationsOnly;

/*
 * Slack settings
 */
@property (atomic, retain) NSString * _Nullable slackAuthToken;
@property (atomic, retain) NSString * _Nullable slackChannel;
@property (atomic, retain) NSString * _Nullable slackReporter;

/*
 * Jira settings
 * Use your Jira auth token to automatically create Jira tickets
 * Your Jira host URL. For ex: https://crony-us.atlassian.net
 */
@property (atomic, retain) NSString * _Nullable jiraAuthToken;
@property (atomic, retain) NSString * _Nullable jiraHost;
@property (atomic, retain) NSString * _Nullable jiraProjectKey;
@property (atomic, retain) NSString * _Nullable jiraAssignee;
@property (atomic, retain) NSString * _Nullable jiraReporter;
@property (atomic, retain) NSArray<NSString *> * _Nullable jiraLabels;

+ (BSCronySettings *_Nonnull)defaultSettings;
+ (BSCronySettings *_Nonnull)currentSettings;

+ (BOOL)urlSessionEnabled;
+ (BOOL)viewLoadsEnabled;
+ (BOOL)nsLogEnabled;
+ (BOOL)userGesturesEnabled;
+ (BOOL)aiEnabled;
+ (BOOL)wkWebViewEnabled;
+ (BOOL)performanceEnabled;
+ (BOOL)crashLogsEnabled;
+ (BOOL)replayEnabled;
+ (BOOL)uiControlsEnabled;
+ (BOOL)crawlEnabled;
@end

@interface BSCrony : NSObject

+ (BSCronySettings *_Nullable)currentSettings;
+ (void)setSettings:(BSCronySettings * _Nullable)cronySettings;

+ (void)initializeCrony:(BSCronyMode)cronyMode;
+ (void)initializeCrony:(BSCronyMode)cronyMode settings:(BSCronySettings * _Nullable)settings;
+ (BSCronyMode)cronyMode;

+ (void)showCrony;
+ (void)hideCrony;

+ (BOOL)startRecording:(void (^_Nullable)(BSCScreenRecordingStatus status))completionHandler;
+ (void)stopRecording:(void (^_Nullable)(BOOL succeeded, NSURL * _Nullable recordingUrl))completionHandler;
+ (BOOL)isRecording;

+ (BOOL)startReplaying:(NSString * _Nullable)sessionId;
+ (void)stopReplaying;
+ (BOOL)isReplaying;
+ (NSString *_Nullable)replayingSessionId;

+ (void)showA11YDetails;
+ (void)hideA11YDetails;
+ (NSDictionary *_Nonnull)a11yDetails:(BOOL)withScreenshot;

// Survey
+ (void)setSurvey:(NSString *_Nonnull)name description:(NSString *_Nullable)description;
+ (NSString *_Nonnull)surveyName;
+ (NSString *_Nullable)surveyDescription;
+ (void)addSurveyQuestion:(NSString *_Nonnull)question;
+ (void)addSurveyQuestion:(NSString *_Nonnull)question with:(NSArray<NSString *> * _Nonnull)choices allow:(BOOL)multipleChoices;
+ (void)clearSurvey;
+ (void)takeSurvey:(NSString *_Nonnull)surveyId description:(NSString *_Nullable)description;


@end
