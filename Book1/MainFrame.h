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
	afx_msg void OnSize(UINT nType,int cx,int cy);
	afx_msg void OnSizing(UINT nSide,LPRECT lpRect);
	afx_msg void OnDestroy();
	DECLARE_MESSAGE_MAP()
};

