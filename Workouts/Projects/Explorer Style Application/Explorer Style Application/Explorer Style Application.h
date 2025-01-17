
// Explorer Style Application.h : main header file for the Explorer Style Application application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CExplorerStyleApplicationApp:
// See Explorer Style Application.cpp for the implementation of this class
//

class CExplorerStyleApplicationApp : public CWinAppEx
{
public:
	CExplorerStyleApplicationApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExplorerStyleApplicationApp theApp;
