#pragma once

#include <deque>
#include "VaoUnit.h"

class ObjectQueue
{
public:
	ObjectQueue();
	~ObjectQueue();

	void Init(int QueueLength, int VaoUnitNumber = 4);
	bool Release();
	void AddObject2Queue(int AddLength);

	void AddData2Object(char* DataPoints, char* DataColors);

	void RenderObject();

private:

	//һ��VAO�ɶ�֡���������ɣ�һ��VAO��СVaoUnitSize
	int VaoUnitSize;

	// ÿһ�����󣬷�װ��VaoUnit
	VaoUnit* p_VaoUnit;

	//QueueLength�����г���
	int QueueLength;


	//ʹ�ö��У�Double ended queue
	std::deque<VaoUnit *> ObjectDeque;
	unsigned int FrameCount;
};

