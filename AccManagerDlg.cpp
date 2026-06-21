// Copyright(c) 2026 Yuhano.All rights reserved.
// AccManagerDlg.cpp: 实现文件
#include "pch.h"
#include "framework.h"
#include "AccManager.h"
#include "AccManagerDlg.h"
#include "afxdialogex.h"
#include <windows.h>
#include <lm.h>
#pragma comment(lib, "netapi32.lib")

CAccManagerDlg::CAccManagerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ACCMANAGER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAccManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAccManagerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Enable, &CAccManagerDlg::OnBnClickedEnable)
	ON_BN_CLICKED(IDC_Disable, &CAccManagerDlg::OnBnClickedDisable)
	ON_BN_CLICKED(IDC_Delete, &CAccManagerDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_Cmd, &CAccManagerDlg::OnBnClickedCmd)
	ON_BN_CLICKED(IDC_Restart, &CAccManagerDlg::OnBnClickedRestart)
END_MESSAGE_MAP()

BOOL CAccManagerDlg::OnInitDialog()
{
	SetWindowText(_T("Yuhano Account Manager"));
	CDialogEx::OnInitDialog();
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	return TRUE;
}

void CAccManagerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this);

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

BOOL CAccManagerDlg::EnableAdministrator(BOOL bEnable)
{
	USER_INFO_1008 userInfo;
	userInfo.usri1008_flags = bEnable ? 0 : UF_ACCOUNTDISABLE;
	NET_API_STATUS nStatus = NetUserSetInfo(NULL,
		L"Administrator",
		1008,
		(LPBYTE)&userInfo,
		NULL);

	if (nStatus == NERR_Success)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL CAccManagerDlg::SetAdministratorPassword(LPCWSTR lpszNewPassword)
{
	USER_INFO_1003 userInfo;
	userInfo.usri1003_password = (LPWSTR)lpszNewPassword;
	NET_API_STATUS nStatus = NetUserSetInfo(NULL,
		L"Administrator",
		1003,
		(LPBYTE)&userInfo,
		NULL);

	if (nStatus == NERR_Success)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

HCURSOR CAccManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CAccManagerDlg::OnBnClickedEnable()
{
	EnableAdministrator(TRUE);
}
void CAccManagerDlg::OnBnClickedDisable()
{
	EnableAdministrator(FALSE);
}
void CAccManagerDlg::OnBnClickedDelete()
{
	SetAdministratorPassword(L"");
}
void CAccManagerDlg::OnBnClickedCmd()
{
	std::system("cmd.exe");
}
void CAccManagerDlg::OnBnClickedRestart()
{
	HANDLE hToken;
	TOKEN_PRIVILEGES tkp;
	if (!OpenProcessToken(GetCurrentProcess(),
		TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
		return;
	LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
	if (!ExitWindowsEx(EWX_REBOOT, 0))
	{
		AfxMessageBox(_T("重启失败"));
	}
}
