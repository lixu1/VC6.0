// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "通用菜单.h"

#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_COLOR_BLUE, OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, OnUpdateColorBlue)
	ON_COMMAND(ID_COLOR_GREEN, OnColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, OnUpdateColorGreen)
	ON_COMMAND(ID_COLOR_RED, OnColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, OnUpdateColorRed)
	ON_COMMAND(ID_LINE_FIVE, OnLineFive)
	ON_UPDATE_COMMAND_UI(ID_LINE_FIVE, OnUpdateLineFive)
	ON_COMMAND(ID_LINE_SINGE, OnLineSinge)
	ON_UPDATE_COMMAND_UI(ID_LINE_SINGE, OnUpdateLineSinge)
	ON_COMMAND(ID_LINE_THREE, OnLineThree)
	ON_UPDATE_COMMAND_UI(ID_LINE_THREE, OnUpdateLineThree)
	ON_COMMAND(ID_GRAPH_CIRCLE, OnGraphCircle)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_CIRCLE, OnUpdateGraphCircle)
	ON_COMMAND(ID_GRAPH_LINE, OnGraphLine)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_LINE, OnUpdateGraphLine)
	ON_COMMAND(ID_GRAPH_RECTANGLE, OnGraphRectangle)
	ON_UPDATE_COMMAND_UI(ID_GRAPH_RECTANGLE, OnUpdateGraphRectangle)
	ON_UPDATE_COMMAND_UI(IDS_STATUS_TIMER,OnUpdateTime)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_STATUSPART1,
	ID_STATUSPART2,
	ID_STATUSPART3,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
	IDS_STATUS_TIMER,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	m_Color=RGB(0,0,0);
	m_TagColor=0;
	m_Graph=0;
	m_Thickness=0;

	m_StatusPart1="ztguang";
	m_StatusPart2="ztguang";
	m_StatusPart3="ztguang";
}

CMainFrame::~CMainFrame()
{
	::KillTimer(NULL,m_nIDTimer);
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if(!m_StatusBar.Create(this)||!m_StatusBar.SetIndicators(indicators,sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;
	}
	m_nIDTimer=::SetTimer(NULL,0,1000,TimerProc);

	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

void CMainFrame::ShowStatusBarInfo()
{
	info1.Format("%s",m_StatusPart1);
	m_StatusBar.SetPaneText(m_StatusBar.CommandToIndex(ID_STATUSPART1),info1);
	info2.Format("%s",m_StatusPart2);
	m_StatusBar.SetPaneText(m_StatusBar.CommandToIndex(ID_STATUSPART2),info2);
	info1.Format("%s",m_StatusPart3);
	m_StatusBar.SetPaneText(m_StatusBar.CommandToIndex(ID_STATUSPART3),info3);
}
void CMainFrame::OnUpdateTime(CCmdUI *pCmdUI)
{
	CTime timer=CTime::GetCurrentTime();
	char szTimer[6];
	int mHour=timer.GetHour();
	int mMinute=timer.GetMinute();
	if(mHour>12)mHour=mHour-12;
	wsprintf(szTimer,"%i:%02i",mHour,mMinute);
	m_StatusBar.SetPaneText(m_StatusBar.CommandToIndex(IDS_STATUS_TIMER),LPCSTR(szTimer));
	pCmdUI->Enable();
}

void CALLBACK CMainFrame::TimerProc(HWND hwnd,UINT uMsg,UINT uIDEvent,DWORD dwTime)
{
	CMainFrame *pMainWnd=(CMainFrame *)AfxGetApp()->m_pMainWnd;
	ASSERT(uIDEvent==pMainWnd->m_nIDTimer);
	CCmdUI cui;
	cui.m_nID=IDS_STATUS_TIMER;
	cui.m_nIndex=4;
	cui.m_pMenu=NULL;
	cui.m_pOther=&pMainWnd->m_StatusBar;
	pMainWnd->OnUpdateTime(&cui);
}


/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnColorBlue() 
{
	// TODO: Add your command handler code here
	m_StatusPart1="蓝色";
	ShowStatusBarInfo();
	m_Color=RGB(0,0,255);
	m_TagColor=ID_COLOR_BLUE;
}

void CMainFrame::OnUpdateColorBlue(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_TagColor==ID_COLOR_BLUE?1:0);
}

void CMainFrame::OnColorGreen() 
{
	// TODO: Add your command handler code here
	m_StatusPart1="绿色";
	ShowStatusBarInfo();
	m_Color=RGB(0,255,0);
	m_TagColor=ID_COLOR_GREEN;
}

void CMainFrame::OnUpdateColorGreen(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_TagColor==ID_COLOR_GREEN?1:0);
}

void CMainFrame::OnColorRed() 
{
	// TODO: Add your command handler code here
	m_StatusPart1="红色";
	ShowStatusBarInfo();
	m_Color=RGB(255,0,0);
	m_TagColor=ID_COLOR_RED;
}

void CMainFrame::OnUpdateColorRed(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_TagColor==ID_COLOR_RED?1:0);
}

void CMainFrame::OnLineFive() 
{
	// TODO: Add your command handler code here
	m_StatusPart2="五线宽";
	ShowStatusBarInfo();
	m_Thickness=5;
}

void CMainFrame::OnUpdateLineFive(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_Thickness==5?1:0);
}

void CMainFrame::OnLineSinge() 
{
	// TODO: Add your command handler code here
	m_StatusPart2="单线宽";
	ShowStatusBarInfo();
	m_Thickness=1;
}

void CMainFrame::OnUpdateLineSinge(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_Thickness==1?1:0);
}

void CMainFrame::OnLineThree() 
{
	// TODO: Add your command handler code here
	m_StatusPart2="三线宽";
	ShowStatusBarInfo();
	m_Thickness=3;
}

void CMainFrame::OnUpdateLineThree(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_Thickness==3?1:0);
}

void CMainFrame::OnGraphCircle() 
{
	// TODO: Add your command handler code here
	m_StatusPart3="椭圆";
	ShowStatusBarInfo();
	m_Graph=ID_GRAPH_CIRCLE;
	CPen *oPen,nPen;
	nPen.CreatePen(PS_SOLID,m_Thickness,m_Color);
	CClientDC cdc(this);
	CRect rect;
	GetClientRect(&rect);
	cdc.FillRect(&rect,CBrush::FromHandle((HBRUSH)GetStockObject(LTGRAY_BRUSH)));
	oPen=cdc.SelectObject(&nPen);
	cdc.Ellipse(100,100,200,200);
	cdc.SelectObject(oPen);

}

void CMainFrame::OnUpdateGraphCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_Graph==ID_GRAPH_CIRCLE?1:0);
}

void CMainFrame::OnGraphLine() 
{
	// TODO: Add your command handler code here
	m_StatusPart3="直线";
	ShowStatusBarInfo();
	m_Graph=ID_GRAPH_LINE;
	CPen *oPen,nPen;
	nPen.CreatePen(PS_SOLID,m_Thickness,m_Color);
	CClientDC cdc(this);
	CRect rect;
	GetClientRect(&rect);
	cdc.FillRect(&rect,CBrush::FromHandle((HBRUSH)GetStockObject(LTGRAY_BRUSH)));
	oPen=cdc.SelectObject(&nPen);
	cdc.MoveTo(100,310);
	cdc.LineTo(500,310);
	cdc.SelectObject(oPen);
}

void CMainFrame::OnUpdateGraphLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_Graph==ID_GRAPH_LINE?1:0);
}

void CMainFrame::OnGraphRectangle() 
{
	// TODO: Add your command handler code here
	m_StatusPart3="矩形";
	ShowStatusBarInfo();
	m_Graph=ID_GRAPH_RECTANGLE;
	CPen *oPen,nPen;
	nPen.CreatePen(PS_SOLID,m_Thickness,m_Color);
	CClientDC cdc(this);
	CRect rect;
	GetClientRect(&rect);
	cdc.FillRect(&rect,CBrush::FromHandle((HBRUSH)GetStockObject(LTGRAY_BRUSH)));
	oPen=cdc.SelectObject(&nPen);
	cdc.Rectangle(350,100,450,200);
	cdc.SelectObject(oPen);
}

void CMainFrame::OnUpdateGraphRectangle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_Graph==ID_GRAPH_RECTANGLE?1:0);
}
