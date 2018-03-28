#pragma once

#include <deque>
#include "Object.h"

class ObjectQueue
{
public:
	ObjectQueue();
	~ObjectQueue();

	void Init(int ObjectNumber, int VaoUnitNumber = 10);
	bool Release();
	void AddObject(int AddNumber);

	void AddData2Object(char* DataPoints, char* DataColors);

	void RenderObject();

private:

	//һ�������ɶ��VAO�����ɣ��������һ��������VaoUnitNumber��VAO�����ɡ�
	int VaoUnitNumber;
	Object* p_Object;

	//ObjectNumber������ĸ���������Ҫ����
	int ObjectNumber;


	//ʹ�ö��У�Double ended queue
	std::deque<Object *> ObjectDeque;
	unsigned int Usage;
};

