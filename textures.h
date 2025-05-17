#ifndef TEXTURES_CLASS_H
#define TEXTURES_CLASS_H
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class textures
{
public:
    unsigned char* data;
    int imgWidth, imgHeight, nrChannels;
    GLuint texture;

    int InitializeTexture();
    int createTextures();
    void deleteTextures();
    
};

#endif
