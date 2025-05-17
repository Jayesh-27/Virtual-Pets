#ifndef GAMEOBJECT_CLASS_H
#define GAMEOBJECT_CLASS_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <shaderClass.h>
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
class Object
{
public:
    Shader shaderProgram;

    // Define vertices for a textured quad
    static float vertices[8];
    static float texturePos[8];
    static unsigned int indices[6];    
    VAO VAO1;
    VBO VBO1;
    VBO VBO2;
    EBO EBO1;
    Object();
	//void Transform();                 Future Position, Scale, Rotation
    void ShaderHandling();
    void VBO_VAO_EBO();
    void mainLoopThings();
    void afterMainLoopThings();
};
#endif