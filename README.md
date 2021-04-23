# Crony
#### Record. Share. Fix.

# What is Crony?
Crony is a pal for mobile app testers and developers. Crony brings them closer together to capture and share information in real-time.

# Record
1. On-demand or always
2. Screenshots and videos
3. Annotate screenshots
4. Network Calls, Views, Spinners
5. Logs
6. Crashes
7. Vitals (CPU, MEM, Disk, Battery)
8. On-device view of the recordings

# Share
1. Share the recordings right from the device using the apps like messenger, slack etc.
2. Send them to content management systems (sharepoint), bugtracking systems (Jira etc.) from the device

# Fix
1. Developers and app owners get all the information they need without any communication failures to fix the issues

### Usage
## XCode Intregration
1. Unzip Crony.zip file
2. Drag Crony folder and drop it into your XCode project
3. Select "Copy items if needed" and "Create groups" options
4. Select the targets and click Finish
5. Go to BUild Settings and add -ObjC as additional linker flag
6. Open your AppDelehgate.m file include BSCrony.h
7. in didFinishLaunchingWithOptions, add the following line;
   1. [BSCrony initializeCrony:nil];
8. Compile and run the app




