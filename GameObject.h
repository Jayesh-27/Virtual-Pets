#ifndef GAMEOBJECT_CLASS_H
#define GAMEOBJECT_CLASS_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <shaderClass.h>
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Transform.h"

//#include "saman.h"
class Object {
public:
    Transform transform;
    Object();
    void ShaderHandling();
    void VBO_VAO_EBO();
    void Render();
    void afterRender();

    static float vertices[];
    static float texturePos[];
    static unsigned int indices[];

    Shader shaderProgram;
    VAO VAO1;
    VBO VBO1;
    VBO VBO2;
    EBO EBO1;
};

#endif