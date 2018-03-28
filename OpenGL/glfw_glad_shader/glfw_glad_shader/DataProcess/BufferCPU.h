#pragma once

#include <stdio.h>
#include <tchar.h>
#include <atlstr.h>

//ѭ������ڵ�
typedef struct list
{
	char* data;
	list *next;
}List, *PList;

class BufferCPU
{
public:
	BufferCPU(int Size_List, int DataLength);
	~BufferCPU();


private:
	int DataLength;
	int Size_List;
	PList Front, Rear;

public:

	//����β�巨����ѭ������
	void CreateList();

	//��ѭ��ѭ������β�������µĽڵ�
	void PushRear();

	int LengthList();
	bool isEmpty();
	bool isFull();
	bool EnList(char* P_char);//�洢��Ԫ����Ϊ DataLength
	bool DeList(char* P_char);//�洢��Ԫ����Ϊ DataLength

	bool ReleaseList();
	void ShowStatus();//��ʾ��ǰ����״̬
};