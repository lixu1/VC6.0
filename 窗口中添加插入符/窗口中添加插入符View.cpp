// 窗口中添加插入符View.cpp : implementation of the CMyView class
//

#include "stdafx.h"
#include "窗口中添加插入符.h"

#include "窗口中添加插入符Doc.h"
#include "窗口中添加插入符View.h"

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
	ON_WM_CHAR()
	ON_WM_KILLFOCUS()
	ON_WM_SETFOCUS()
	ON_WM_LBUTTONDOWN()
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
	car=false;
	m_pColor=RGB(255,0,0);

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
	if(!car)
	{
		TEXTMETRIC text;
		pDC->GetTextMetrics(&text);
		CreateSolidCaret(text.tmAveCharWidth/8,text.tmHeight);
		carep.x=carep.y=4;
		SetCaretPos(carep);
		ShowCaret();
		car=true;
	}
	//pDC->TextOut(0,4,pDoc->str);
	CSize size=pDC->GetTextExtent(pDoc->str);
	HideCaret();
	carep.x=size.cx;
	SetCaretPos(carep);
	ShowCaret();
	pDC->SetTextColor(m_pColor);
	carep.x=x+size.cx;
	carep.y=y;
	SetCaretPos(carep);
	pDC->TextOut(x,y,pDoc->str);

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

void CMyView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CMyDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->str+=nChar;
	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CMyView::OnKillFocus(CWnd* pNewWnd) 
{
	CView::OnKillFocus(pNewWnd);
	
	// TODO: Add your message handler code here
	HideCaret();//隐藏焦点
}

void CMyView::OnSetFocus(CWnd* pOldWnd) 
{
	CView::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here
	ShowCaret();//显示焦点
}

void CMyView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	x=point.x;
	y=point.y;
	CMyDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->str.Empty();
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}
