#pragma once
#include<afxwin.h>
#include "resource.h"
class CMainFrame :	public CFrameWnd
{

public:
	CMainFrame();
	~CMainFrame();

	HACCEL m_Haccel;
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnShowWindow(BOOL bShow,UINT nStatus);
	afx_msg void OnActivate(UINT nState, CWnd * pWndOther, BOOL bMinimised);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType,int cx,int cy);
	afx_msg void OnSizing(UINT nSide,LPRECT lpRect);
	afx_msg void OnDestroy();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlag);
	afx_msg void OnKeyUp(UINT nChar,UINT nRepCnt,UINT nFlag);
	afx_msg void OnLButtonDown(UINT nFlag, CPoint points);
	afx_msg void OnRButtonDown(UINT nFlag, CPoint points);
	afx_msg void OnMButtonDown(UINT nFlag, CPoint points);
	afx_msg void OnLButtonDblClk(UINT nFlag, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlag, CPoint point);
	afx_msg void OnMouseMove(UINT nFlag,CPoint points);
	DECLARE_MESSAGE_MAP()
};

