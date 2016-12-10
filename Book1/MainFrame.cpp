#include "MainFrame.h"

//constructor
CMainFrame::CMainFrame()
{
	Create(NULL, _T("Home"), WS_OVERLAPPEDWINDOW, CRect(120, 100, 700, 480), NULL);
}

//destructor no code to the destructor
CMainFrame::~CMainFrame()
{
	
}
//METHOD WILL USED FOR CREATING THE WINDOWS
int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	//CREATE WINDOWS AND MAKE SURE IT DOES'T RETURN -1
	if(CFrameWnd::OnCreate(lpCreateStruct)==0)
	{
		//IF WINDOWS CREATED SUCCESSFULLY,THEN LET USER KNOW
		//MessageBox(_T("The windows has been created successfully"));
		//IF WINDOWS WILL CREATED SUCCESSFULLY THEN IT WILL RETURN 0
		return 0;
	}
	//OTHERWISE RETURN -1 IT INDICATE THAT WINDOWS NOT CREATED SUCCESSFULLY
	return -1;
}

//IT WON'T CREATE WINDOWS IT JUST SHOW THE WINDOWS ONLY
void CMainFrame::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CFrameWnd::OnShowWindow(bShow, nStatus);
	
	ShowWindow(SW_MAXIMIZE);
	
}

//CHECKING FOR THE STATE OF THE WINDOWS
//STATE ARE
//WC_ACTIVE
//WC_INACTIVE
//WC_CLICKACTIVE
//IT WILL SHOW THE CURRENT STATE OF THE WINDWS DOES IT ACTIVATE OF MINIMISED THAT INFORMATION WILL HAS THE VARIABLE
/*
 *BOOL  bMinimised;
 */
void CMainFrame::OnActivate(UINT nState, CWnd * pWndOther, BOOL bMinimised)
{
	
	CFrameWnd::OnActivate(nState,pWndOther,bMinimised);
	switch(nState)
	{
	case WA_ACTIVE:
		//MessageBox(_T("This windows has been activated without mouse"));
		break;
	case WA_INACTIVE:
		//IT WILL CHECK FOR THE ARCHITECTURE OF THE WINDOWS SYSTEM
		#ifdef _WIN64
		//MessageBox(_T("This windows has been deactivated and cannot be changed now : 64x Architecture"));
		#else
	//	MessageBox(_T("This windows has been deactivated and cannot be changed now : 86x Architecture"));
		#endif
		
		break;
	case WA_CLICKACTIVE:
		//MessageBox(_T("This windows has been activated using mouse"));
		break;
	}
}


//IF WINDOWS STATE IS INACTIVE THEN ALSO NEED TO PAINT THE WINDOWS SO THIS METHOD WILL DO THIS THING
void CMainFrame::OnPaint()
{
	CFrameWnd::OnPaint();
	//MessageBox(_T("The windows has been printed"));
}

//THIS METHOD WILL SHOW THE WINDOWS SIZING BEHAVIOUR 
void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);
	//VARIABLE FOR HANDLING THE MESSAGEBOX TEXT
	
	CString msg;
	
	switch(nType)
	{
	case SIZE_MAXIMIZED:
		msg.Format(L"Maximized CX :%d,CY:%d",cx,cy);
		break;
	case SIZE_MINIMIZED:
		msg.Format(L"Minimized CX :%d,CY:%d", cx, cy);
		break;
	case SIZE_RESTORED:
		msg.Format(L"Restored CX :%d,CY:%d", cx, cy);
		break;
	case SIZE_MAXHIDE:
		msg.Format(L"Maximized not me CX :%d,CY:%d", cx, cy);
		break;
	case SIZE_MAXSHOW:
		msg.Format(L"Restored not me CX :%d,CY:%d", cx, cy);
		break;
	}
	//MessageBox(msg);

	
	
}
//IF WE RESIZE THE WINDOWS LIKE MAKE IT SMALL USING MOUSE DRAGING ON THE CORNER
void CMainFrame::OnSizing(UINT nSide, LPRECT lpRect)
{
	CString msg;

	long btm = lpRect->bottom;
	long tp = lpRect->top;
	long lf = lpRect->left;
	long rt = lpRect->right;

	switch(nSide)
	{ 
	case WMSZ_BOTTOM:
		msg.Format(L"Maximized bottom :%ld,top:%ld,left=%ld,right=%ld", btm, tp,lf,rt);
		break;
	case WMSZ_BOTTOMLEFT:
		msg.Format(L"Maximized bottom :%ld,top:%ld,left=%ld,right=%ld", btm, tp, lf, rt);
		break;
	case WMSZ_BOTTOMRIGHT:
		msg.Format(L"Maximized bottom :%ld,top:%ld,left=%ld,right=%ld", btm, tp, lf, rt);
		break;
	case WMSZ_RIGHT:
		msg.Format(L"Maximized bottom :%ld,top:%ld,left=%ld,right=%ld", btm, tp, lf, rt);
		break;
	case WMSZ_LEFT:
		msg.Format(L"Maximized bottom :%ld,top:%ld,left=%ld,right=%ld", btm, tp, lf, rt);
		break;
	case WMSZ_TOP:
		msg.Format(L"Maximized bottom :%ld,top:%ld,left=%ld,right=%ld", btm, tp, lf, rt);
		break;
	case WMSZ_TOPLEFT:
		msg.Format(L"Maximized bottom :%ld,top:%ld,left=%ld,right=%ld", btm, tp, lf, rt);
		break;
	case WMSZ_TOPRIGHT:
		msg.Format(L"Maximized bottom :%ld,top:%ld,left=%ld,right=%ld", btm, tp, lf, rt); 
		break;
	}
	//MessageBox(msg);
}

void CMainFrame::OnDestroy()
{
	//MessageBox(_T("Window will be destroyed"));
}

//THIS MACRO DECLARATION WILL CREATE THE COMMUNICATION BETWEEN THE CMainFrame and CFrameWmd{base class of th CMainFrame header will declare in MainFrame.h file}
//WE ALSO NEED TO DECLARE THAT MACRO WE DECLARED IT IN MainFrame.h HEADER FILE
BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()//THIS WILL USE THE onCreate
	ON_WM_SHOWWINDOW()//THIS WILL USE THE OnShowWindow
	ON_WM_ACTIVATE()//THIS WILL USE THE OnActivate
	ON_WM_PAINT()//THIS WILL USE THE OnPaint
	ON_WM_SIZE()//THIS WILL USE THE OnSize
	ON_WM_SIZING()//THIS WILL USE THE OnSizing
	ON_WM_DESTROY()//THIS WILL USE OnDestroy
END_MESSAGE_MAP()

//this class will show the windows behaviour
class CMainApp : public CWinApp
{
public:
	BOOL InitInstance();
};

///INSTANTIATE THE WINDOWS
BOOL CMainApp::InitInstance()
{
	m_pMainWnd = new CMainFrame;
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

CMainApp theApp;


