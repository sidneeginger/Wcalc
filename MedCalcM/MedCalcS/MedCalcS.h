
// MedCalcS.h : MedCalcS Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CMedCalcSApp:
// �йش����ʵ�֣������ MedCalcS.cpp
//

class CMedCalcSApp : public CWinApp
{
public:
	CMedCalcSApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMedCalcSApp theApp;
