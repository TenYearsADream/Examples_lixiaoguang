#include "ObjectManager.h"


ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

void ObjectManager::Init(int ObjectNumber, int VaoUnitNumber)
{

	//һ�������ɶ��VAO�����ɣ��������һ��������VaoUnitNumber��VAO�����ɡ�
	this->VaoUnitNumber = VaoUnitNumber;

	//ObjectNumber������ĸ���������Ҫ����
	this->ObjectNumber = ObjectNumber;// 10;


	for (int i = 0; i < (int)ObjectNumber; i++)
	{

		p_Object = new Object();
		p_Object->Init(VaoUnitNumber);

		ObjectVector.push_back(p_Object);

		printf("ObjectNumber idx = %d \n", i);
	}

}

bool ObjectManager::Release()
{

	//��һ�ַ�ʽȫ���ͷ�
	/*
	while (!ObjectVector.empty())
	{
		p_Object = ObjectVector.back();
		
		if (!p_Object->Release())
		{
			return false;
		}
		
		ObjectVector.pop_back();
	}
	*/


	for (std::vector<Object *>::iterator it = ObjectVector.begin(); it != ObjectVector.end(); ++it)
	{

		if (!(*it)->Release())
		{
			return false;
		}

	}

	// erase the all elements:
	ObjectVector.erase(ObjectVector.begin(), ObjectVector.end());

	if (ObjectVector.empty())
	{
		printf("ObjectManager Release Success! \n");
		return true;
	}
	else
	{
		return false;
	}

}

void ObjectManager::AddObject(int AddNumber)
{

	for (int i = 0; i < AddNumber; i++)
	{

		p_Object = new Object();
		p_Object->Init(VaoUnitNumber);

		ObjectVector.push_back(p_Object);
	}
}

void ObjectManager::AddData2Object()
{
	//��Ҫ�ṹ�壬˵��ObjectVectorʹ�����
	//����Ϊ��ʱ����
	for (std::vector<Object *>::iterator it = ObjectVector.begin(); it != ObjectVector.end(); ++it)
	{

		p_Object->AddData2VaoUnit();

	}
}