; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "通用菜单.h"
LastPage=0

ClassCount=5
Class1=CMyApp
Class2=CMyDoc
Class3=CMyView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDR_PopUpMenu
Class5=CAboutDlg
Resource3=IDD_ABOUTBOX

[CLS:CMyApp]
Type=0
HeaderFile=通用菜单.h
ImplementationFile=通用菜单.cpp
Filter=N

[CLS:CMyDoc]
Type=0
HeaderFile=通用菜单Doc.h
ImplementationFile=通用菜单Doc.cpp
Filter=N

[CLS:CMyView]
Type=0
HeaderFile=通用菜单View.h
ImplementationFile=通用菜单View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CMyView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=通用菜单.cpp
ImplementationFile=通用菜单.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_COLOR_RED
Command18=ID_COLOR_GREEN
Command19=ID_COLOR_BLUE
Command20=ID_LINE_SINGE
Command21=ID_LINE_THREE
Command22=ID_LINE_FIVE
Command23=ID_GRAPH_LINE
Command24=ID_GRAPH_CIRCLE
Command25=ID_GRAPH_RECTANGLE
CommandCount=25

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_PopUpMenu]
Type=1
Class=?
Command1=ID_COLOR_RED
Command2=ID_COLOR_GREEN
Command3=ID_COLOR_BLUE
Command4=ID_LINE_SINGE
Command5=ID_LINE_THREE
Command6=ID_LINE_FIVE
Command7=ID_GRAPH_LINE
Command8=ID_GRAPH_CIRCLE
Command9=ID_GRAPH_RECTANGLE
CommandCount=9

