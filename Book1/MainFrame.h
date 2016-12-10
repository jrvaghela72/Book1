#pragma once
#include<afxwin.h>
class CMainFrame :	public CFrameWnd
{

public:
	CMainFrame();
	~CMainFrame();
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnShowWindow(BOOL bShow,UINT nStatus);
	afx_msg void OnActivate(UINT nState, CWnd * pWndOther, BOOL bMinimised);
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

