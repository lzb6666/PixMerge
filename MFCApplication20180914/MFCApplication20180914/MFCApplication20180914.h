
// MFCApplication20180914.h: MFCApplication20180914 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CMFCApplication20180914App:
// 有关此类的实现，请参阅 MFCApplication20180914.cpp
//

class CMFCApplication20180914App : public CWinAppEx
{
public:
	CMFCApplication20180914App() noexcept;

	CMultiDocTemplate* m_pDocTemplate;

	int m_iCntpix = 0;
// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	afx_msg void On32772();
	afx_msg void OnMenuMerge();
};

extern CMFCApplication20180914App theApp;
