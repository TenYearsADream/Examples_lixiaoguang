#pragma once

// glad
#include <glad/glad.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//using namespace glm;



//��ǰ֡ ����-z���ĸ��߽��
struct EdgePoint
{
	//-x,-y ���½ǣ�����-z��
	glm::vec3 NxNy;

	//-x,+y ���Ͻǣ�����-z��
	glm::vec3 NxPy;

	//+x,-y ���½ǣ�����-z��
	glm::vec3 PxNy;

	//+x,+y ���Ͻǣ�����-z��
	glm::vec3 PxPy;

	EdgePoint()
	{
		this->NxNy = glm::vec3(0.0f, 0.0f, 0.0f);
		this->NxPy = glm::vec3(0.0f, 0.0f, 0.0f);
		this->PxNy = glm::vec3(0.0f, 0.0f, 0.0f);
		this->PxPy = glm::vec3(0.0f, 0.0f, 0.0f);
	}

};



class VaoUnit
{
public:
	VaoUnit();
	~VaoUnit();

	void Init(int index, int FrameCountMax = 5);
	void Release();

	// �����ݵ�VAO
	void BindData2VaoUnit(char* DataPoints, char* DataColors);

	// ��Ⱦ��ǰVAO
	void RanderVAO();

	// ��ȡ��ǰVAO������֡��
	int Get_FrameCount();

	// ��ǰVAO ����
	void Reset();

	// �ж� ��ǰVAO������֡�����Ƿ�ﵽ���ֵ
	bool IsFull();


	unsigned int *GetVao();
	unsigned int *GetVbo();

	//��ȡ��ǰVaoUnit������Vector�еı��
	int GetIndex();

private:

	// Ĭ��ʹ��VAO1����VBOʹ��5��
	unsigned int VBO[5], VAO[1];

	// ��ǰVAO��Ե���ݵ�����
	EdgePoint m_EdgePoint;

	// ��ǰVAO�Ƿ�������ݲ���
	bool IsCurrentMeasure;

	//��ǰVaoUnit������Vector�еı��
	int index;

	// FrameCountMax��ÿһ��VAO���ص�֡������
	int FrameCountMax;

	// FrameCount��ÿһ��VAO���ص�֡����ǰ��
	int FrameCount;

	// CurrentBytes����ǰ���������ֽڣ�
	int CurrentBytes;
};

