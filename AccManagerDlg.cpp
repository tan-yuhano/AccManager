// Copyright(c) 2026 Yuhano.All rights reserved.
// AccManagerDlg.cpp: 实现文件
#include "pch.h"
#include "framework.h"
#include "AccManager.h"
#include "AccManagerDlg.h"
#include "afxdialogex.h"

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
END_MESSAGE_MAP()

BOOL CAccManagerDlg::OnInitDialog()
{
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

HCURSOR CAccManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CAccManagerDlg::OnBnClickedEnable()
{
	std::system("net user administrator /active:yes");
}
void CAccManagerDlg::OnBnClickedDisable()
{
	std::system("net user administrator /active:no");
}
void CAccManagerDlg::OnBnClickedDelete()
{
	std::system("net user administrator """);
}

void CAccManagerDlg::OnBnClickedCmd()
{
	std::system("cmd.exe");
}
