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
    int imgWidth, imgHeight, nrChannels;
    GLuint texture;

    void deleteTextures();
    
};

#endif
