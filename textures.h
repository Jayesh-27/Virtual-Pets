#ifndef TEXTURES_CLASS_H
#define TEXTURES_CLASS_H
#include <GLFW/glfw3.h>
#include "stb_image.h"

class textures
{
public:
    unsigned char* data;
    int imgWidth, imgHeight, nrChannels;
    GLuint texture;

    int InitializeTexture();
    void deleteTextures();
    
};

#endif
