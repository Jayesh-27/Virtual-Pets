#ifndef TEXTURES_CLASS_H
#define TEXTURES_CLASS_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "stb_image.h"

class textures
{
public:
    unsigned char* data;
    unsigned char* cursorData;
    int imgWidth, imgHeight, nrChannels;
    GLuint texture;
    textures();

    void deleteTextures(); 

    GLFWcursor* cursor;
    void changeCursor(GLFWwindow* window);

};

#endif
