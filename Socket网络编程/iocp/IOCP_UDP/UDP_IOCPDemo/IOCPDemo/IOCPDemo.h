// IOCPDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CIOCPDemoApp:
// �йش����ʵ�֣������ IOCPDemo.cpp
//

class CIOCPDemoApp : public CWinApp
{
public:
	CIOCPDemoApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CIOCPDemoApp theApp;