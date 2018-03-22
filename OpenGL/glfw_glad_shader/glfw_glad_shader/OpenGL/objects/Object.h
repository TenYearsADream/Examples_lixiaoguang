#pragma once

// vector
#include <vector>

#include "VaoUnit.h"

class Object
{
public:
	Object();
	~Object();

	void Init(int VaoUnitNumber, int Index);
	bool Release();

	

	//Ŀǰʹ��ģ�����ݣ���Ҫ������ʵ���ݣ���ָ�봫��
	//Idle��ջ��Show��ջ
	bool AddData2VaoUnit();
	bool IsFull();
	bool IsEmpty();
	
	void RenderVaoUnit();

protected:
	void InitSampleData();
	void ReleaseSampleData();

	void BindData2VaoUnit();

private:

	//һ�������ɶ��VAO�����ɣ��������һ��������VaoUnitNumber��VAO�����ɡ�
	int VaoUnitNumber;
	VaoUnit *p_VaoUnit;

	// ���ж���VaoUnitVectorIdle�����ڼ��ص�������
	std::vector<VaoUnit *> VaoUnitVectorIdle;

	// ��ʾ����VaoUnitVectorShow��������ʾ��������
	std::vector<VaoUnit *> VaoUnitVectorShow;

	//��ǰ������Queue�еı��
	int Index;

	//Cube���ӣ����ڲ���VAO����
	float* VerticesCubeSample;
	float* ColorsCubeSample;
};

