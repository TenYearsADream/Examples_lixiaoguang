#include "VaoUnit.h"
#include <stdio.h>


VaoUnit::VaoUnit()
{

}

VaoUnit::~VaoUnit()
{
}

void VaoUnit::Init(int index, int FrameCountMax)
{

	this->index = index;
	this->FrameCountMax = FrameCountMax;
	FrameCount = 0;

	this->m_EdgePoint = EdgePoint();
	this->IsCurrentMeasure = false;

	// Points����
	Points = new char[FrameCountMax * 128 * 128 * 4 * sizeof(float)];

	// colors ����
	//Colors = new char[FrameCountMax * 128 * 128 * 4 * sizeof(float)];



	glGenVertexArrays(1, VAO);
	glGenBuffers(2, VBO);


	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO[0]);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	//glBufferData(GL_ARRAY_BUFFER, FrameCountMax * 128 * 128 * 3 * sizeof(float), Points, GL_DYNAMIC_DRAW);


	//GL_MAP_PERSISTENT_BIT // ����Mapped״̬Ҳ��ʹ��
	//GL_MAP_COHERENT_BIT; // ���ݶ�GPU�����ɼ�

	glBufferStorage(GL_ARRAY_BUFFER, FrameCountMax * 128 * 128 * 4 * sizeof(float), Points, GL_DYNAMIC_STORAGE_BIT | GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);

	//ptr_Points = (char*)glMapBufferRange(GL_ARRAY_BUFFER, 0, FrameCountMax * 128 * 128 * 3 * sizeof(float), GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);
	//glBufferSubData(GL_ARRAY_BUFFER, FrameCount * 128 * 128 * 3 * sizeof(float), 128 * 128 * 3 * sizeof(float), DataPoints);
	/*

	// ��ȡ��������ӳ��ָ��ptr
	void * ptr = glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY);

	// �������ǵ����ݵ�ָ����ָ���λ��
	memcpy(ptr, DataPoints, 128 * 128 * 3 * sizeof(float));

	// ʹ����֮���ͷ�ӳ���ָ��
	glUnmapBuffer(GL_ARRAY_BUFFER);

	*/


	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
		4,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
		);

	/*

	// 2nd attribute buffer : colors

	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	//glBufferData(GL_ARRAY_BUFFER, FrameCountMax * 128 * 128 * 4 * sizeof(float), Colors, GL_DYNAMIC_DRAW);

	//GL_MAP_PERSISTENT_BIT // ����Mapped״̬Ҳ��ʹ��
	//GL_MAP_COHERENT_BIT; // ���ݶ�GPU�����ɼ�

	glBufferStorage(GL_ARRAY_BUFFER, FrameCountMax * 128 * 128 * 4 * sizeof(float), Colors, GL_DYNAMIC_STORAGE_BIT | GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);

	//ptr_Colors = (char*)glMapBufferRange(GL_ARRAY_BUFFER, 0, FrameCountMax * 128 * 128 * 3 * sizeof(float), GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);

	//glBufferSubData(GL_ARRAY_BUFFER, FrameCount * 128 * 128 * 4 * sizeof(float), 128 * 128 * 4 * sizeof(float), DataColors);


	
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(
		3,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		4,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);


	*/
	
	
	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

}

bool VaoUnit::Release()
{
	glDeleteVertexArrays(1, VAO);
	glDeleteBuffers(2, VBO);

	delete Points;
	return true;
}

// �����ݵ�VAO
void VaoUnit::BindData2VaoUnit(char* DataPoints)
{
	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
	glBindVertexArray(VAO[0]);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);

	glBufferSubData(GL_ARRAY_BUFFER, FrameCount * 128 * 128 * 4 * sizeof(float), 128 * 128 * 4 * sizeof(float), DataPoints);
	
	//GLvoid *ptr_Points = glMapBufferRange(GL_ARRAY_BUFFER, FrameCount * 128 * 128 * 3 * sizeof(float), 128 * 128 * 3 * sizeof(float), GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);

	
	// ��ȡ��������ӳ��ָ��ptr
	//void * ptr_Points = glMapBufferRange(GL_ARRAY_BUFFER, FrameCount * 128 * 128 * 3 * sizeof(float), 128 * 128 * 3 * sizeof(float), GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT | GL_MAP_UNSYNCHRONIZED_BIT);

	// �������ǵ����ݵ�ָ����ָ���λ��
	//memcpy(ptr_Points + FrameCount * 128 * 128 * 3 * sizeof(float), DataPoints, 128 * 128 * 3 * sizeof(float));

	// ʹ����֮���ͷ�ӳ���ָ��
	//glUnmapBuffer(GL_ARRAY_BUFFER);
	
	
	/*

	// 2nd attribute buffer : colors

	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);

	glBufferSubData(GL_ARRAY_BUFFER, FrameCount * 128 * 128 * 4 * sizeof(float), 128 * 128 * 4 * sizeof(float), DataColors);

	//GLvoid *ptr_Colors = glMapBufferRange(GL_ARRAY_BUFFER, FrameCount * 128 * 128 * 4 * sizeof(float), 128 * 128 * 4 * sizeof(float), GL_MAP_WRITE_BIT | GL_MAP_PERSISTENT_BIT | GL_MAP_COHERENT_BIT);

	// ��ȡ��������ӳ��ָ��ptr
	//void * ptr_Colors = glMapBufferRange(GL_ARRAY_BUFFER, FrameCount * 128 * 128 * 4 * sizeof(float), 128 * 128 * 4 * sizeof(float), GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT | GL_MAP_UNSYNCHRONIZED_BIT);

	// �������ǵ����ݵ�ָ����ָ���λ��
	//memcpy(ptr_Colors + FrameCount * 128 * 128 * 4 * sizeof(float), DataColors, 128 * 128 * 4 * sizeof(float));

	// ʹ����֮���ͷ�ӳ���ָ��
	//glUnmapBuffer(GL_ARRAY_BUFFER);

	*/


	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
	glBindVertexArray(0);

	


	FrameCount++;
}

// ��Ⱦ��ǰVAO
void VaoUnit::RanderVAO()
{
	// bind the VAO
	glBindVertexArray(VAO[0]);

	// 12*3 indices starting at 0 -> 12 triangles
	glDrawArrays(GL_POINTS, 0, FrameCount * 128 * 128);

	//printf("FrameCount[%d] \n", FrameCount);

	// unbind the VAO
	glBindVertexArray(0);

}

// ��ȡ��ǰVAO������֡��
int VaoUnit::Get_FrameCount()
{

	return FrameCount;
}

// ��ǰVAO ����
bool VaoUnit::Reset()
{
	FrameCount = 0;

	return true;
}

// �ж� ��ǰVAO������֡�����Ƿ�ﵽ���ֵ
bool VaoUnit::IsFull()
{
	if (FrameCount == FrameCountMax)
	{
		return true;
	}
	else
	{
		return false;
	}

}

// �ж� ��ǰVAO�Ƿ�Ϊ��
bool VaoUnit::IsEmpty()
{
	if (FrameCount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

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