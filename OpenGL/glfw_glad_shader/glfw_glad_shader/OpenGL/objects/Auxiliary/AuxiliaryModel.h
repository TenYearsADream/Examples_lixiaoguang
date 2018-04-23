#pragma once

// glad
#include <glad/glad.h>

// GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
//using namespace glm;

class AuxiliaryModel
{
public:
	AuxiliaryModel();
	~AuxiliaryModel();

	void Init();
	bool Release();

	// ��Ⱦ��ǰVAO
	void RanderVAO();


private:

	// Ĭ��ʹ��VAO1����EBOʹ��1����VBOʹ��2��
	unsigned int VBO[2], EBO[1], VAO[1];
};

