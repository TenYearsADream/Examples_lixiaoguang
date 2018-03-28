#include "VaoUnit.h"


VaoUnit::VaoUnit()
{

}

VaoUnit::~VaoUnit()
{
}

void VaoUnit::Init(int index)
{

	this->index = index;
	this->m_EdgePoint = EdgePoint();
	this->IsCurrentMeasure = false;

	glGenVertexArrays(1, VAO);
	glGenBuffers(5, VBO);
}

void VaoUnit::Release()
{
	glDeleteVertexArrays(1, VAO);
	glDeleteBuffers(5, VBO);
}

unsigned int* VaoUnit::GetVao()
{
	return VAO;
}

unsigned int* VaoUnit::GetVbo()
{

	return VBO;
}

//��ȡ��ǰVaoUnit������Vector�еı��
int VaoUnit::GetIndex()
{
	return index;
}