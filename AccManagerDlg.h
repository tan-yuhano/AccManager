// Copyright (c) 2026 Yuhano. All rights reserved.
// AccManagerDlg.h: 头文件

#pragma once

class CAccManagerDlg : public CDialogEx
{
// 构造
public:
	CAccManagerDlg(CWnd* pParent = nullptr);
	#ifdef AFX_DESIGN_TIME
		enum { IDD = IDD_ACCMANAGER_DIALOG };
	#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

// 实现
protected:
	HICON m_hIcon;
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};