#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include<glad/glad.h>
#include<iostream>

std::string get_file_contents(const char* filename);

class Shader
{
public:
	GLuint ID;
	Shader(const char* vertexFile, const char* fragmentFile);
	Shader(){}
	void Activate();
	void Delete();
	int GetUniformLocation(const char* name);
};
#endif