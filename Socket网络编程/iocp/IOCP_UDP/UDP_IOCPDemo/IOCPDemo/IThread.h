#pragma once

class IThread
{
public:
	IThread(void);
	virtual ~IThread(void);

protected:
	// �̺߳���
	virtual DWORD WINAPI ThreadExecute(void)=0;	

	typedef union _thread_proc
	{
		DWORD (WINAPI *ThreadRun)(PVOID para);
		DWORD (WINAPI IThread::*ThreadExecute)(void);
	}THREADPROC;    // �̺߳���ָ������,ʹ������ͨ��Ա�������̺߳���ʱʹ��;

	THREADPROC m_threadFunc; // ����ͨ��Ա������Ϊ�̺߳������м����
};




