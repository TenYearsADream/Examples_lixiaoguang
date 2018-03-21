#pragma once
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();

	void Init(int ObjectNumber, int VaoUnitNumber = 100);
	bool Release();
	void AddObject(int AddNumber);

	void AddData2Object();

private:

	//һ�������ɶ��VAO�����ɣ��������һ��������VaoUnitNumber��VAO�����ɡ�
	int VaoUnitNumber;
	Object* p_Object;

	//ObjectNumber������ĸ���������Ҫ����
	int ObjectNumber;

	std::vector<Object *> ObjectVector;
};

