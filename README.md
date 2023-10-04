<img width="186" alt="crony-logo" src="https://github.com/sumanc/Crony-Eval/assets/470461/1b944ed8-c4f8-44f1-9c00-6e711e82275b">
   
#### Record. Report. Resolve.

# What is Crony?
Crony is a pal for mobile app testers and developers. Crony brings them closer together to capture and share information in real-time. Please checkout our website https://crony.us for more information.

<img src="https://user-images.githubusercontent.com/470461/162629564-e2a6d777-a007-44d2-a39c-d790349009f1.png" width="25%" height="25%">

# Record
1. Crony records user experience, process execution, screen recording, and A LOT OF contextual data like:
   1. logs
   2. Views
   3. Network Calls
   4. Spinners
   5. User gestures
   6. Crash logs
   7. Performance Metrics
2. Crony allows testers to annotate and add voice memos as well
3. No Performance Impact
4. No Change In The User Experience

# Review
1. Crony Brings Observability To The Device. NO NEED TO LOGIN TO A PORTAL
2. View All The Data Ccollected In A Simple Easy To Understand Display
3. Understand The App Behavior, Resources Consumption, And Performance
4. Shift To The Left In Finding And Resolving The Bugs

<img src="https://user-images.githubusercontent.com/470461/162628937-a555f945-b3b2-4584-be5c-c950b3e39c62.png" width="20%" height="20%"> <img src="https://user-images.githubusercontent.com/470461/162628999-9d00adcb-4ad9-4383-b7ff-1bc7d0729b10.png" width="20%" height="20%"> <img src="https://user-images.githubusercontent.com/470461/162629078-49a8157c-f7ec-4a77-a202-aa261f0b2fee.png" width="20%" height="20%"> <img src="https://user-images.githubusercontent.com/470461/162629324-114fc15a-018f-406b-8d2f-29177d1c04c2.png" width="20%" height="20%">

# Replay
1. Crony Allows To Replay Any Recording
2. Replay Is At The Process Level [NOT JUST VIDEO]
3. App Executes By Itself The Same Way It Was Recorded. NO EXTERNAL DRIVERS LIKE APPIUM Are Needed
4. All The User Gestures And Interactions Are Simulated By Crony
5. Always Reproduce The Bugs And Crashes Captured On Record
6. Attach The Debugger And Step Through The Code On Replay To Determine The Cause Of The Issue
<img src="https://user-images.githubusercontent.com/470461/162629260-4fc81534-3fcc-4934-b59a-9e3e4e1769c3.png" width="25%" height="25%">

# Accessibility Auditor
1. Crony Detects Accessibility Violations And Shows Them Live On The Screen
2. When A Violation Badge Is Tapped, The Details Are Displayed
3. Allows To Share The Accessibility Violations Per Screen Or For All The Screens
<img src="https://user-images.githubusercontent.com/470461/162628673-219571cb-0a67-47bd-9175-01f46c4729a8.png" width="25%" height="25%">

# Report
1. Share the recordings right from the device using the apps like messenger, slack etc.
2. Send them to content management systems (sharepoint), bugtracking systems (Jira etc.) from the device
<img src="https://user-images.githubusercontent.com/470461/162629169-cb8c5b61-df57-423c-951c-fbb5a5861236.png" width="25%" height="25%">

# Resolve
1. Find And Fix The Bugs During The Design And Development Phase
2. Developers Receive A Comprehensive Package In The Bug Report
3. Report Includes The Recording, All The Events That Are Captured, Performance Metrics, And Additional Annotations And Voice Memos By The Tester
4. Visually See What Testers Saw And Use The Data To Quickly Find The Root Cause

### Usage
## XCode Intregration
1. Unzip Crony.zip file
2. Drag Crony folder and drop it into your XCode project
3. Select "Copy items if needed" and "Create groups" options
4. Select the targets and click Finish
5. Go to BUild Settings and add -ObjC as additional linker flag
6. Open your AppDelehgate.m file include BSCrony.h
7. [OPTIONAL] In didFinishLaunchingWithOptions, add the following line;
   ```[BSCrony initializeCrony:BSCronyModePrompt sessionId:nil];```
8. Compile and run the app

