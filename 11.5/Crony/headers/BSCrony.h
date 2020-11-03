//
//  BSCrony.h
//  Crony
//
//  Created by Suman Cherukuri on 11/30/18.
//  Copyright © 2018 Suman Cherukuri. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

extern NSString *const CRONY_VERSION;

@interface BSCronySettings : NSObject

@property (atomic, assign) BOOL onStartup;  //YES
@property (atomic, assign) BOOL urlSession; //YES
@property (atomic, assign) BOOL wkWebView; //YES
@property (atomic, assign) BOOL screenshots;    //NO - NOT SUPPORTED YET
@property (atomic, assign) BOOL video;  //YES
@property (atomic, assign) BOOL viewLoads;  //YES
@property (atomic, assign) BOOL nsLog;  //YES
@property (atomic, assign) CGFloat networkCallThreshold;    //2 secs
@property (atomic, assign) CGFloat aiThreshold; //1 sec
@property (atomic, assign) CGFloat viewLoadThreshold;   //0.5 sec

@property (atomic, retain) NSString *slackAuthToken;    //Use your Slack auth token to integrate Crony with your Slack channels
@property (atomic, retain) NSString *jiraAuthToken; //Use your Jira auth token to automatically create Jira tickets
@property (atomic, retain) NSString *jiraHost;      //Your Jira host URL. For ex: https://crony-us.atlassian.net

+ (BSCronySettings *)defaultSettings;

@end

@interface BSCrony : NSObject

+ (void)initializeCrony:(BSCronySettings *)cronySettings;
+ (BOOL)startRecording;
+ (void)stopRecording;
+ (BOOL)isRecording;
+ (BSCronySettings *)currentSettings;
+ (void)setSettings:(BSCronySettings *)cronySettings;

@end
