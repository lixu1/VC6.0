#if !defined(AFX_POSITONVIEW_H__7C715EC7_986E_4C34_B394_80BA5815A7DB__INCLUDED_)
#define AFX_POSITONVIEW_H__7C715EC7_986E_4C34_B394_80BA5815A7DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PositonView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPositonView view

class CPositonView : public CScrollView
{
protected:
	CPositonView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CPositonView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPositonView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CPositonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CPositonView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POSITONVIEW_H__7C715EC7_986E_4C34_B394_80BA5815A7DB__INCLUDED_)
