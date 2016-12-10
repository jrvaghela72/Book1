#include "MainFrame.h"
#include <winuser.h>
#include <winuser.h>
#include <winuser.h>
//constructor
CMainFrame::CMainFrame()
{
	//THIS ALL ARE  USED FOR CUSTOMISATION OF THE WINDOWS LIKE DEFAULT COLOR,DEFAULT CURSOR,DEFAULT ICON ETC
	//HCURSOR m_cursor = AfxGetApp()->LoadCursor(IDC_APP_CURS);
	//HICON m_icon = AfxGetApp()->LoadIcon(IDI_ICON1);
	
	//LPCTSTR RWC = AfxRegisterWndClass(CS_VREDRAW|CS_HREDRAW, m_cursor, (HBRUSH)GetStockObject(WHITE_BRUSH),m_icon);
	LPCTSTR RWC = AfxRegisterWndClass(CS_VREDRAW|CS_HREDRAW, NULL, (HBRUSH)GetStockObject(WHITE_BRUSH),NULL);
	
	//IT WILL LOAD THE SORTCUT KEY FOR THE MENU
	m_Haccel =LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(MAIN_ACCELARATOR));

	Create(RWC, CString(MAKEINTRESOURCE(ID_EDIT_UNDO)), WS_OVERLAPPEDWINDOW, CRect(120, 100, 700, 480), NULL,MAKEINTRESOURCE(MAIN_MENU));
	
	//IT WILL DISABLE THE CURSOR
	//ShowCursor(TRUE);

	//set the custom cursor
	//HCURSOR cursor = LoadCursor(NULL, MAKEINTRESOURCE(IDC_APP_CURS));
	//SetCursor(cursor);
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

//THIS METHOD WILL HANDLING THE ALL INPUT FROM KEYBOARD YOU CAN CHECK THE NAME OF THE KEY USING WINDOWS REFRENCE
void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlag)
{
	/*CString msg;
	switch(nChar)
	{
	case VK_RETURN:
		msg.Format(L"ENTER KEY");
		break;
	case VK_F1:
		msg.Format(L"F1 for Help");
		break;
	case VK_DELETE:
		msg.Format(L"DEL FOR DELETE CONTENT");
		break;
	case VK_SHIFT:
		msg.Format(L"SHIFT KEY");
		break;
	case VK_CONTROL:
		msg.Format(L"CTRL KEY");
		break;
	default:
		msg.Format(L"KEY PRESSED DONT KNOW THE NAME OF KEY");
		break;
	}
	MessageBox(msg);*/
}

//THIS WILL USE FOR KEY UP EVENT HANDLING FOR DEFEENT BETWEEN KEYDOWN AND KEYUP PLEASE CHECK ONLINE DOCUMENTATION FOR IT
void CMainFrame::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlag)
{
	CString msg;
	switch (nChar)
	{
	case VK_INSERT:
		msg.Format(L"INSERT KEY");
		break;
	default:
		msg.Format(L"KEY PRESSED DONT KNOW THE NAME OF KEY");
		break;
	}
	MessageBox(msg);
}

//FOR HANDLING THE LIFT CLICK OF THE MOUSE BUTTON
void CMainFrame::OnLButtonDown(UINT nFlag, CPoint points)
{
	CString msg="This message has been send";
	//msg.Format(_T("Left Button Down at Point X:%d,Y:%d"),points.x,points.y);
	//MessageBox(msg);
	SendMessage(WM_SETTEXT,(WPARAM)(LPCTSTR)msg);
}
//FOR HANDLING THE RIGHT CLICK OF THE MOUSE BUTTON
void CMainFrame::OnRButtonDown(UINT nFlag, CPoint points)
{
	CString msg="hello";
	/*msg.Format(_T("Right Button Down at Point X:%d,Y:%d"), points.x, points.y);
	MessageBox(msg);*/
	
	PostMessage(WM_GETTEXT, (WPARAM)(LPCTSTR)msg);
	MessageBox(msg);
}

void CMainFrame::OnMButtonDown(UINT nFlag, CPoint points)
{
	CString msg;
	msg.Format(_T("Middle Button Down at Point X:%d,Y:%d"), points.x, points.y);
	//MessageBox(msg);
}

void CMainFrame::OnLButtonDblClk(UINT nFlag, CPoint points)
{
	CString msg;
	msg.Format(_T("Left Button DBLCLICK at Point X:%d,Y:%d"), points.x, points.y);
	MessageBox(msg);
}

void CMainFrame::OnRButtonDblClk(UINT nFlag, CPoint points)
{
	CString msg;
	msg.Format(_T("Right Button DBLCLICK at Point X:%d,Y:%d"), points.x, points.y);
	MessageBox(msg);
}

void CMainFrame::OnMouseMove(UINT nFlag, CPoint points)
{
	CString msg;
	msg.Format(_T("Mouse Move at Point X:%d,Y:%d"), points.x, points.y);
	//MessageBox(msg);
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
	ON_WM_KEYDOWN()//THIS WILL USE OnKeyDown
	ON_WM_KEYUP()//THIS WILL USE OnKeyUp
	ON_WM_LBUTTONDOWN()//THIS WILL USE OnLButtonDown
	ON_WM_RBUTTONDOWN()//THIS WILL USE OnRButtonDown
	ON_WM_MBUTTONDOWN()//THIS WILL USE OnMButtonDown
	ON_WM_LBUTTONDBLCLK()//THIS WILL USE OnLButtonDblClk
	ON_WM_RBUTTONDBLCLK()//THIS WILL USE OnRButtonDblClk
	ON_WM_MOUSEMOVE()//THIS WILL USE OnMouseMove

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


