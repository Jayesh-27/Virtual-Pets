#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
class VBO
{
public:
	GLuint ID;
	VBO(GLfloat* vertices, GLsizeiptr size);
	VBO() : ID(0) {}
	void Bind();
	void Unbind();
	void Delete();
};

#endif