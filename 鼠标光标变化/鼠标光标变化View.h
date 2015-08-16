// �����仯View.h : interface of the CMyView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEW_H__B0B766B9_C584_4EDC_96DF_C65E7C6138AD__INCLUDED_)
#define AFX_VIEW_H__B0B766B9_C584_4EDC_96DF_C65E7C6138AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyView : public CView
{
protected: // create from serialization only
	CMyView();
	DECLARE_DYNCREATE(CMyView)

// Attributes
public:
	CMyDoc* GetDocument();
	HCURSOR m_hCursor;
	int m_hClick;
	void LoadCur(UINT CurName);
	void GetCur(int ID_NO);


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in �����仯View.cpp
inline CMyDoc* CMyView::GetDocument()
   { return (CMyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEW_H__B0B766B9_C584_4EDC_96DF_C65E7C6138AD__INCLUDED_)
