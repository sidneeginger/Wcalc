
// MedCalcM.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMedCalcMApp: 
// �йش����ʵ�֣������ MedCalcM.cpp
//

class CMedCalcMApp : public CWinApp
{
public:
	CMedCalcMApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMedCalcMApp theApp;