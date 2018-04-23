#pragma once

#include <deque>
#include "VaoUnit.h"

// Include GLFW
#include <GLFW/glfw3.h>

class ObjectQueue
{
public:
	ObjectQueue();
	~ObjectQueue();

	void Init(int QueueLength, int VaoUnitNumber = 4);
	bool Release();

	void AddObject2Queue(int AddLength);

	bool SubtractObject2Queue(int SubtractLength);
	void AddData2Object(char* DataPoints);
	void SetMultipleFrame(bool Val);
	void UpdateFromInputs(GLFWwindow* Window);


	void RenderObject();

private:

	//һ��VAO�ɶ�֡���������ɣ�һ��VAO��СVaoUnitSize
	int VaoUnitSize;

	// ÿһ�����󣬷�װ��VaoUnit
	VaoUnit* p_VaoUnit;

	//QueueLength�����г���
	int QueueLength;

	// ��/��֡�л�
	bool IsMultipleFrame;

	//ʹ�ö��У�Double ended queue
	std::deque<VaoUnit *> ObjectDeque;
	unsigned int FrameCount;
};

