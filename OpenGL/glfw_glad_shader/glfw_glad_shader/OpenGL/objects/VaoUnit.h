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
	VaoUnit(int index);
	~VaoUnit();

	void Release();

	unsigned int *GetVao();
	unsigned int *GetVbo();

	//��ȡ��ǰVaoUnit������Vector�еı��
	int GetIndex();

private:

	// Ĭ��ʹ��VAO1����VBOʹ��3��
	unsigned int VBO[5], VAO[1];
	EdgePoint m_EdgePoint;
	bool IsCurrentMeasure;

	//��ǰVaoUnit������Vector�еı��
	int index;

};

