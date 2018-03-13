// glfw_glew_IMGUI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define GLEW_STATIC

#include <GLEW/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>

/* ע�⣺#define GLEW_STATIC �� #include<GL/glew.h>ǰ�棬
* #include<GL/glew.h>��#include<GLFW/glfw3.h>ǰ��
*/
using namespace std;

/*������������Ļص�����*/
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// ���û�����ESC��,��������window���ڵ�WindowShouldClose����Ϊtrue
	// �ر�Ӧ�ó���
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main()
{
	/*��ʼ��GLFW*/
	glfwInit();
	/*����GLFW����*/
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	/*��������*/
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
		return -1;
	}
	/*֪ͨGLFW�����Ǵ��ڵ�����������Ϊ��ǰ�̵߳���������*/
	glfwMakeContextCurrent(window);

	/*GLEW����������OpenGL�ĺ���ָ��ģ������ڵ����κ�OpenGL�ĺ���֮ǰ������Ҫ��ʼ��GLEW*/
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		cout << "Failed to initialize GLEW" << endl;
		return -1;
	}
	/*����OpenGL��Ⱦ���ڵĳߴ��С������OpenGL��ֻ��֪����������ڴ��ڴ�С��ʾ���ݺ�����*/
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	/*ע��ص�����*/
	glfwSetKeyCallback(window, key_callback);
	/*�¼�ѭ��*/
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		/*���������û�д���ʲô�¼�������������롢����ƶ��ȣ���
		*Ȼ����ö�Ӧ�Ļص�����������ͨ���ص������ֶ����ã���
		����һ������Ϸѭ���Ŀ�ʼ�����¼�������
		*/

		// ����д��Ⱦָ��


		glfwSwapBuffers(window);
		/*�����ύ����ɫ���壨����һ��������GLFW����ÿһ��������ɫ�Ĵ󻺳壩��
		*������һ�����б��������ƣ����ҽ�����Ϊ�����ʾ����Ļ��
		*/
	}
	/*�ͷ�GLFW������ڴ�*/
	glfwTerminate();

	return 0;
}
