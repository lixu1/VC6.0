// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__5912CB19_09DC_448C_B262_ABF1B24CA9A6__INCLUDED_)
#define AFX_MAINFRM_H__5912CB19_09DC_448C_B262_ABF1B24CA9A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	CString m_StatusPart1;
	CString info1;
	CString m_StatusPart2;
	CString info2;
	CString m_StatusPart3;
	CString info3;
	UINT m_nIDTimer;
	CStatusBar m_StatusBar;
	static void CALLBACK TimerProc(HWND hwnd,UINT uMsg,UINT uIDEvent,DWORD dwTime);
	void ShowStatusBarInfo();


// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	COLORREF m_Color;
	int m_Thickness;
	UINT m_Graph;
	UINT m_TagColor;

	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnColorBlue();
	afx_msg void OnUpdateColorBlue(CCmdUI* pCmdUI);
	afx_msg void OnColorGreen();
	afx_msg void OnUpdateColorGreen(CCmdUI* pCmdUI);
	afx_msg void OnColorRed();
	afx_msg void OnUpdateColorRed(CCmdUI* pCmdUI);
	afx_msg void OnLineFive();
	afx_msg void OnUpdateLineFive(CCmdUI* pCmdUI);
	afx_msg void OnLineSinge();
	afx_msg void OnUpdateLineSinge(CCmdUI* pCmdUI);
	afx_msg void OnLineThree();
	afx_msg void OnUpdateLineThree(CCmdUI* pCmdUI);
	afx_msg void OnGraphCircle();
	afx_msg void OnUpdateGraphCircle(CCmdUI* pCmdUI);
	afx_msg void OnGraphLine();
	afx_msg void OnUpdateGraphLine(CCmdUI* pCmdUI);
	afx_msg void OnGraphRectangle();
	afx_msg void OnUpdateGraphRectangle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTime(CCmdUI *pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__5912CB19_09DC_448C_B262_ABF1B24CA9A6__INCLUDED_)
