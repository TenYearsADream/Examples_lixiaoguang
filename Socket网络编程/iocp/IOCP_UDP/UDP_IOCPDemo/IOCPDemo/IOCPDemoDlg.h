// IOCPDemoDlg.h : ͷ�ļ�
//

#pragma once

#include "MyIOCP.h"

// CIOCPDemoDlg �Ի���
class CIOCPDemoDlg : public CDialog
{
// ����
public:
	CIOCPDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IOCPDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStart();

	CMyIOCP m_iocp;
	afx_msg void OnBnClickedStop();
};
