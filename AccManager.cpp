
// AccManager.cpp: 定义应用程序的类行为。
//

#include "pch.h"
#include "framework.h"
#include "AccManager.h"
#include "AccManagerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BEGIN_MESSAGE_MAP(CAccManagerApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()

CAccManagerApp::CAccManagerApp()
{
	
}

CAccManagerApp theApp;
BOOL CAccManagerApp::InitInstance()
{
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	CShellManager *pShellManager = new CShellManager;
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));
	SetRegistryKey(_T("Yuhano AccManager"));
	CAccManagerDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: 对话框创建失败\n");
		TRACE(traceAppMsg, 0, "警告: 无法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

	#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
		ControlBarCleanUp();
	#endif
	
	return FALSE;
}

