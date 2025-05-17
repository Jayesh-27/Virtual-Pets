#ifndef EBO_CLASS_H
#define EBO_CLASS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class EBO
{
public:
	GLuint ID;
	EBO(GLuint* indices, GLsizeiptr size);
	EBO(){}
	void Bind();
	void Unbind();
	void Delete();
};

#endif