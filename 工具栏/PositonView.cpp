// PositonView.cpp : implementation file
//

#include "stdafx.h"
#include "¹¤¾ßÀ¸.h"
#include "PositonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPositonView

IMPLEMENT_DYNCREATE(CPositonView, CScrollView)

CPositonView::CPositonView()
{
}

CPositonView::~CPositonView()
{
}


BEGIN_MESSAGE_MAP(CPositonView, CScrollView)
	//{{AFX_MSG_MAP(CPositonView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPositonView drawing

void CPositonView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CPositonView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CPositonView diagnostics

#ifdef _DEBUG
void CPositonView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CPositonView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPositonView message handlers
