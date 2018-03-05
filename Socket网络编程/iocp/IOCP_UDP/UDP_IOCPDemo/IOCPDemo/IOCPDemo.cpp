// IOCPDemo.cpp : ����Ӧ�ó��������Ϊ��
//

#pragma comment(lib,"ws2_32.lib")
#include "stdafx.h"
#include "IOCPDemo.h"
#include "IOCPDemoDlg.h"
#include <WinSock2.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CIOCPDemoApp

BEGIN_MESSAGE_MAP(CIOCPDemoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CIOCPDemoApp ����
CIOCPDemoApp::CIOCPDemoApp()
{
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CIOCPDemoApp ����
CIOCPDemoApp theApp;


// CIOCPDemoApp ��ʼ��

BOOL CIOCPDemoApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	AfxEnableControlContainer();

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	{
		WSAData wsaData={0};
		int res=WSAStartup(0x0202,&wsaData);

		if (res!=0)
		{
			TRACE("ERROR:WSAStartup error;ErrorCode:%d\n\n",WSAGetLastError());
			return FALSE;
		}
		
		if (wsaData.wVersion!=0x0202)
		{
			TRACE("ERROR:Can't find usable winsock DLL;ErrorCode:%d\n\n",WSAGetLastError());
			return FALSE;
		}
	}

	CIOCPDemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˴����ô����ʱ�á�ȷ�������ر�
		//  �Ի���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ�á�ȡ�������ر�
		//  �Ի���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�

	WSACleanup();
	return FALSE;
}
