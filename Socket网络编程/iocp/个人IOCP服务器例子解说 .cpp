
����д������Ľ�˵��һ���棬��˵iocp�ڲ�����������ⲿ���Ը��˲鿼д��iocp�������Ϳͻ���д�ģ���һ���棬�ο�libeventlibevent-1.4.4-iocp-3 ���µ�������һ���Ƚϱ�׼�ķ������Ϳͻ������ӡ�
���ֿ���ͨ��ǰ���ֻ�ý���iocp�Ļ�����⣻ͨ���󲿷ֽ����Լ�������libevent����׼��iocp���롣

 
һ��//���������Լ���iocp��

 
1���Լ���iocp��������MyIOCPServer.cpp��

 
#include "stdafx.h"
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////

// ���������
typedef struct tagPER_HANDLE_DATA
{
 SOCKET Socket;
 SOCKADDR_STORAGE ClientAddr;
 // ��������������������������Ϣ�����ܷ����������

}PER_HANDLE_DATA, *LPPER_HANDLE_DATA;

// ��I/O ��������
typedef struct tagPER_IO_DATA
{
 OVERLAPPED Overlapped;
 WSABUF DataBuf;
 char buffer[1024];
 int BufferLen;
 int OperationType; // ������Ϊ��д�ı�־��Ϊ�򵥣��Һ�����
}PER_IO_DATA, *LPPER_IO_DATA;

//////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////

//�̺߳���
DWORD WINAPI ServerWorkerThread(LPVOID lpParam);

DWORD WINAPI ServerWorkerThread(LPVOID lpParam)
{
 HANDLE CompletionPort = (HANDLE)lpParam;
 DWORD BytesTransferred;
 LPOVERLAPPED lpOverlapped;
 LPPER_HANDLE_DATA PerHandleData = NULL;
 LPPER_IO_DATA PerIoData = NULL;
 DWORD SendBytes;
 DWORD RecvBytes;
 DWORD Flags;
 BOOL bRet = FALSE;

 while (TRUE) //����ѭ��
 {
  bRet = GetQueuedCompletionStatus(CompletionPort,&BytesTransferred,(PULONG_PTR)&PerHandleData,(LPOVERLAPPED*)&lpOverlapped,INFINITE);

  // ���ɹ��ķ��أ����Ҫע��ʹ�������CONTAINING_RECORD
  PerIoData = (LPPER_IO_DATA)CONTAINING_RECORD(lpOverlapped,PER_IO_DATA,Overlapped);
  // �ȼ��һ�£������Ƿ����׽��������д�����

  if (0 == BytesTransferred)
  {
   closesocket(PerHandleData->Socket);
   GlobalFree(PerHandleData);
   GlobalFree(PerIoData);
   continue;
  }

  // ���ݴ���
  char sendBuf[100];
  sprintf(sendBuf,"Welcome %s to  %d %d \n",PerIoData->DataBuf.buf,PerHandleData->Socket,::GetCurrentThreadId());
  send(PerHandleData->Socket,sendBuf,strlen(sendBuf)+1,0);
  //WSASend()
   /*DataBuf.len = DATA_BUFSIZE; 
  ����DataBuf.buf = buffer; ����
    for(i=0; i < SEND_COUNT ;i++) { ����
     WSASend(PerHandleData->Socket, &DataBuf, 1, ����&SendBytes, 0, &SendOverlapped, NULL); */


  // �ɹ��ˣ�����������յ������Կͻ��˵�����
  cout << PerIoData->DataBuf.buf << ::GetCurrentThreadId() << endl;

  Flags = 0;
  // Ϊ��һ���ص����ý�����I/O ��������
  ZeroMemory(&(PerIoData->Overlapped), sizeof(OVERLAPPED));

  PerIoData->DataBuf.len = 1024;
  PerIoData->DataBuf.buf = PerIoData->buffer;
  PerIoData->OperationType = 0; // read

  WSARecv(PerHandleData->Socket,&(PerIoData->DataBuf),1,&RecvBytes,&Flags,&(PerIoData->Overlapped),NULL);
 }
 return 0;
}

//////////////////////////////////////////////////////////////////////////
//
//
//////////////////////////////////////////////////////////////////////////

int main(int argc, _TCHAR* argv[])
{
 //ͷ������
 HANDLE CompletionPort;
 WSADATA wsd;
 SYSTEM_INFO SystemInfo;
 SOCKADDR_IN InternetAddr;
 SOCKET Listen;

 // ����WinSock2.2
 WSAStartup(MAKEWORD(2, 2), &wsd);

 // 1.����һ��I/O ��ɶ˿�
 CompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE,NULL,0,0);

 // 2.ȷ��ϵͳ���ж��ٸ�������
 GetSystemInfo(&SystemInfo);

 // 3.����ϵͳ�п��õĴ��������������������߳�
 for (int i = 0; i < int(SystemInfo.dwNumberOfProcessors * 2); ++i)
 {
  HANDLE ThreadHandle;

  // ����һ���������Ĺ������̣߳�������ɶ˿ڴ��ݵ����߳�
  ThreadHandle = CreateThread(NULL,0,ServerWorkerThread,CompletionPort,0,NULL);

  CloseHandle(ThreadHandle);
 }

 // 4.����һ�������׽��֣����µ���·���ǹ̶��ġ�
 Listen = WSASocket(AF_INET,SOCK_STREAM,0,NULL,0,WSA_FLAG_OVERLAPPED);

 //�󶨺ͼ���
 InternetAddr.sin_family = PF_INET;
 InternetAddr.sin_port = htons(6001);
 InternetAddr.sin_addr.s_addr = htonl(INADDR_ANY);
 bind(Listen, (SOCKADDR*)&InternetAddr, sizeof(InternetAddr));
 listen(Listen, 5);

 //����ѭ��
 BOOL b = TRUE;
 while (b)
 {
  PER_HANDLE_DATA * PerHandleData = NULL;
  SOCKADDR_IN saRemote;
  SOCKET Accept;
  int RemoteLen;

  // 5.�������ӣ���������ɶ˿ڣ����������AcceptEx �����棬�Դ�
  // ����������Winsock Ӧ�ó���
  RemoteLen = sizeof(saRemote);
  Accept = accept(Listen, (SOCKADDR*)&saRemote, &RemoteLen);

  // 6.�����������׽��ֹ����ĵ����������Ϣ�ṹ
  PerHandleData = (LPPER_HANDLE_DATA)GlobalAlloc(GPTR,sizeof(PER_HANDLE_DATA));

  //cout << "Socket number " << Accept << " connected" << endl;

  PerHandleData->Socket = Accept;
  memcpy(&PerHandleData->ClientAddr, &saRemote, RemoteLen);

  // 7.�������׽��ֺ���ɶ˿ڹ�������
  CreateIoCompletionPort((HANDLE)Accept,CompletionPort,(DWORD)PerHandleData,0);

  // ��ʼ�ڽ����׽����ϴ���I/O
  // ʹ���ص�I/O ���ƣ����½����׽�����Ͷ��һ�������첽
  // WSARecv �� WSASend ������ЩI/O ������ɺ󣬹������߳�
  // ��ΪI/O �����ṩ����֮��Ϳ������������


  static int const DATA_BUFSIZE = 4096; 
  DWORD RecvBytes = 0;
  DWORD Flags = 0;

  // ��I/O ��������
  LPPER_IO_DATA PerIoData = NULL;
  PerIoData = (LPPER_IO_DATA)GlobalAlloc(GPTR, sizeof(PER_IO_DATA));
  ZeroMemory(&(PerIoData->Overlapped), sizeof(OVERLAPPED));
  PerIoData->DataBuf.len = 1024;
  PerIoData->DataBuf.buf = PerIoData->buffer;
  PerIoData->OperationType = 0; // read
  WSARecv(PerHandleData->Socket,&(PerIoData->DataBuf),1,&RecvBytes,&Flags,&(PerIoData->Overlapped),NULL);
 }

 return 0;
}

 

 

2���Լ���iocp�ͻ��ˣ�MyIOCPClient.cpp��

 

#include "stdafx.h"
#include <Winsock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <stdio.h>

void main()
{
 WORD wVersionRequested;
 WSADATA wsaData;
 int err;

 wVersionRequested = MAKEWORD( 1, 1 );

 err = WSAStartup( wVersionRequested, &wsaData );
 if ( err != 0 ) {
  return;
 }


 if ( LOBYTE( wsaData.wVersion ) != 1 ||
  HIBYTE( wsaData.wVersion ) != 1 ) {
   WSACleanup( );
   return; 
 }

 while (true)
 {
  SOCKET sockClient=socket(AF_INET,SOCK_STREAM,0);

  SOCKADDR_IN addrSrv;
  addrSrv.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
  addrSrv.sin_family=AF_INET;
  addrSrv.sin_port=htons(6001);
  connect(sockClient,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));

  send(sockClient,"This is lisi",strlen("This is lisi")+1,0);

  char recvBuf[100];
  recv(sockClient,recvBuf,100,0);
  printf("%s\n",recvBuf);

  closesocket(sockClient);
 }

 WSACleanup();
}
