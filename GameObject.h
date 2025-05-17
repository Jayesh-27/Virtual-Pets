#ifndef GAMEOBJECT_CLASS_H
#define GAMEOBJECT_CLASS_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
class Object
{
public:
    // Define vertices for a textured quad
    static float vertices[8];
    static float texturePos[8];
    unsigned int indices[6];
	//void Transform();                 Future Position, Scale, Rotation
};

#endif
