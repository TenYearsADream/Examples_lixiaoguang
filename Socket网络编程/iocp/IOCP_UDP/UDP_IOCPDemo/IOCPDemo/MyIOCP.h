#pragma once

#include <WinSock2.h>
#include "IThread.h"
#include <vector>

using namespace std;

#define IOCP_BUF_LEN 512

typedef struct iocp_data
{
	WSAOVERLAPPED	 overlapped;
	WSABUF			 wsaBuf;
	char			 data[IOCP_BUF_LEN];

	sockaddr_in		 remoteAddr;
	int				 remoteAddrLen;
	DWORD flags;

	iocp_data()
	{
		flags=0;
		wsaBuf.buf=data;
		wsaBuf.len=IOCP_BUF_LEN;
		remoteAddrLen=sizeof(sockaddr_in);

		memset(data,0x00,IOCP_BUF_LEN);
		memset(&remoteAddr,0x00,sizeof(sockaddr_in));
		memset(&overlapped,0x00,sizeof(WSAOVERLAPPED));
	}

	~iocp_data()
	{
		remoteAddrLen=10;
	}

	void initData()
	{
		flags=0;
		wsaBuf.buf=data;
		wsaBuf.len=IOCP_BUF_LEN;
		remoteAddrLen=sizeof(sockaddr_in);

		memset(data,0x00,IOCP_BUF_LEN);
		memset(&remoteAddr,0x00,sizeof(sockaddr_in));
		memset(&overlapped,0x00,sizeof(WSAOVERLAPPED));
	}
}IOCPDATA,* PIOCPDATA;

class CMyIOCP : public IThread
{
public:
	CMyIOCP(void);
	~CMyIOCP(void);
	
	void Run(void);
	void Stop(void);
private:
	bool m_isRun;
	HANDLE m_hIocp;			// ��ɶ˿ھ��
	SOCKET m_udpSocket;	// udp�׽���
	int m_numOfWorkThreads;	// �����߳���
	int m_numOfMaxIoConcurrent; // ��󲢷���
	vector<IOCPDATA *> m_iocpDataVector;	// ������ɶ˿�������Ϣ����
	vector<HANDLE> m_vetHThread;

	inline void InitData();
	// ������ɶ˿�
	inline bool InitIOCP();

	// ������ɶ˿��߳�
	bool StartThreads();

	// �����׽���
	inline bool InitSocket();

	// ��ɶ˿ڰ�һ�׽���
	inline bool IocpBindSocket();

	//�׽����ص�����,�Ա��׽��ֽ���Զ������
	void IoPend();

	// ���ݽ����̺߳���;
	DWORD WINAPI ThreadExecute();
};
