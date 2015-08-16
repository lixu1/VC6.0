// 顶层菜单View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "顶层菜单.h"

#include "顶层菜单Doc.h"
#include "顶层菜单View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyView

IMPLEMENT_DYNCREATE(CMyView, CView)

BEGIN_MESSAGE_MAP(CMyView, CView)
	//{{AFX_MSG_MAP(CMyView)
	ON_UPDATE_COMMAND_UI(ID_SD_TA_TS, OnUpdateSdTaTs)
	ON_UPDATE_COMMAND_UI(ID_SD_YT_NS, OnUpdateSdYtNs)
	ON_COMMAND(ID_SD_YT_PL, OnSdYtPl)
	ON_COMMAND(ID_SD_YT_NS, OnSdYtNs)
	ON_COMMAND(ID_SD_QD_LS, OnSdQdLs)
	ON_COMMAND(ID_SD_TA_TS, OnSdTaTs)
	ON_COMMAND(ID_SD_JN_BTQ, OnSdJnBtq)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyView construction/destruction

CMyView::CMyView()
{
	// TODO: add construction code here
	str="";

}

CMyView::~CMyView()
{
}

BOOL CMyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyView drawing

void CMyView::OnDraw(CDC* pDC)
{
	CMyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(50,50,str);
}

/////////////////////////////////////////////////////////////////////////////
// CMyView printing

BOOL CMyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyView diagnostics

#ifdef _DEBUG
void CMyView::AssertValid() const
{
	CView::AssertValid();
}

void CMyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDoc* CMyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDoc)));
	return (CMyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyView message handlers

void CMyView::OnUpdateSdTaTs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(false);
}

void CMyView::OnUpdateSdYtNs(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(true);
	pCmdUI->SetCheck(1);
}

void CMyView::OnSdYtPl() 
{
	// TODO: Add your command handler code here
	str="蓬莱仙境";
	Invalidate();
}

void CMyView::OnSdYtNs() 
{
	// TODO: Add your command handler code here
	str="南山大佛";
	Invalidate();
}

void CMyView::OnSdQdLs() 
{
	// TODO: Add your command handler code here
	str="崂山道士";
	Invalidate();
}


void CMyView::OnSdTaTs() 
{
	// TODO: Add your command handler code here
	str="泰山日出";
	Invalidate();
}

void CMyView::OnSdJnBtq() 
{
	// TODO: Add your command handler code here
	str="天下第一泉";
	Invalidate();
}

