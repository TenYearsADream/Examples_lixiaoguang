#pragma once

// vector
#include <vector>

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

struct VaoUnit
{
	// Ĭ��ʹ��VAO1����VBOʹ��3��
	unsigned int VBO[5], VAO[1];
	EdgePoint m_EdgePoint;
	bool IsCurrentMeasure;

	VaoUnit()
	{
		this->m_EdgePoint = EdgePoint();
		this->IsCurrentMeasure = false;

		glGenVertexArrays(1, VAO);
		glGenBuffers(5, VBO);

	}

	void Release()
	{
		glDeleteVertexArrays(1, VAO);
		glDeleteBuffers(5, VBO);
	}

};



class Object
{
public:
	Object();
	~Object();

	void Init(int VaoUnitNumber);
	bool Release();

	void AddData2VaoUnit();

private:

	//һ�������ɶ��VAO�����ɣ��������һ��������VaoUnitNumber��VAO�����ɡ�
	int VaoUnitNumber;
	VaoUnit *p_VaoUnit;


	std::vector<VaoUnit *> VaoUnitVector;
};

