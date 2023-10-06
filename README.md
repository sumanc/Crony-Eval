<img width="186" alt="crony-logo" src="https://github.com/sumanc/Crony-Eval/assets/470461/1b944ed8-c4f8-44f1-9c00-6e711e82275b">
   
#### Record. Report. Resolve.

# What is Crony?
Crony is a pal for mobile app testers and developers. Crony brings them closer together to capture and share information in real-time. Checkout our website https://crony.us for more information.


<img src="https://github.com/sumanc/Crony-Eval/assets/470461/666370a2-6b95-4791-83da-8e5aa31ac7e1.png" width="20%" height="20%">
<img src="https://github.com/sumanc/Crony-Eval/assets/470461/1c962b38-0d48-4052-9e87-32de668c9377.png" width="20%" height="20%">


# Record
1. Crony records user experience, process execution, screen recording, and A LOT OF contextual data like:
   1. Logs
   2. Views
   3. Network Calls
   4. Spinners
   5. User gestures
   6. Crash logs
   7. Performance Metrics
2. Crony allows testers to annotate and add voice memos as well
3. No Performance Impact
4. No Change In The User Experience
   
<img src="https://github.com/sumanc/Crony-Eval/assets/470461/791255d4-d8d7-4df1-ab4b-4d15861d83f4" width="20%" height="20%">

# Review
1. Crony Brings Observability To The Device. NO NEED TO LOGIN TO A PORTAL
2. View All The Data Ccollected In A Simple Easy To Understand Display
3. Understand The App Behavior, Resources Consumption, And Performance
4. Shift To The Left In Finding And Resolving The Bugs

<img src="https://github.com/sumanc/Crony-Eval/assets/470461/76f77cc0-e7f9-4070-bf42-a34724661abe" width="20%" height="20%">
<img src="https://github.com/sumanc/Crony-Eval/assets/470461/6d1edf58-21ab-4586-beff-9307760fde92" width="20%" height="20%">
<img src="https://github.com/sumanc/Crony-Eval/assets/470461/9aaa6270-3723-45c5-9875-02693752bac0" width="20%" height="20%">
<img src="https://github.com/sumanc/Crony-Eval/assets/470461/5dfa85fc-c175-4983-bb76-9086261b76bb" width="20%" height="20%">

# Workflows
1. Crony Allows To create Workflows to test automation
2. No scripting or coding is required to create workflows
3. Workflow execution Is At The Process Level [NOT JUST VIDEO]
4. App Executes By Itself The Same Way It Was Recorded. NO EXTERNAL DRIVERS LIKE APPIUM Are Needed
5. All The User Gestures And Interactions Are Simulated By Crony
   
<img src="https://github.com/sumanc/Crony-Eval/assets/470461/eabc75ee-33e1-432f-b51b-4d01f393ba74" width="20%" height="20%">


# Accessibility Auditor
1. Crony Detects Accessibility Violations And Shows Them Live On The Screen
2. When A Violation Badge Is Tapped, The Details Are Displayed
3. Allows To Share The Accessibility Violations Per Screen Or For All The Screens
   
<img src="https://github.com/sumanc/Crony-Eval/assets/470461/09ec0917-1173-496c-a5bd-40b7ca6d9647" width="20%" height="20%">

# Report
1. Share the recordings right from the device using the apps like messenger, slack etc.
2. Send them to content management systems (sharepoint), bugtracking systems (Jira etc.) from the device
   
<img src="https://github.com/sumanc/Crony-Eval/assets/470461/51afca91-e1b1-4100-a0ed-9eea730dd7b3" width="20%" height="20%">

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

