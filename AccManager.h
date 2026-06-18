// Copyright (c) 2026 Yuhano. All rights reserved.
// AccManager.h: PROJECT_NAME 应用程序的主头文件

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"

class CAccManagerApp : public CWinApp
{
public:
	CAccManagerApp();
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};

extern CAccManagerApp theApp;