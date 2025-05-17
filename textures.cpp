#include <iostream>
#include <textures.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int textures::InitializeTexture()
{
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("C:/Users/jayes/Desktop/Assests/pixelated-BallonwithPenguin.png", &imgWidth, &imgHeight, &nrChannels, 4);
    if (!data) {
        std::cerr << "Failed to load image\n";
        return -1;
    }

    std::cout << "Image loaded: " << imgWidth << "x" << imgHeight << " with " << nrChannels << " channels" << std::endl;
    
    textures::createTextures();
    return 0;
}

int textures::createTextures()
{
    // Create texture
    
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    // Upload texture data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    // Check for texture creation errors
    GLenum err = glGetError();
    if (err != GL_NO_ERROR) {
        std::cout << "OpenGL texture error: " << err << std::endl;
        return -1;
    }
    // Bind texture to texture unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
        
    return 0;
}

void textures::deleteTextures()
{
    glDeleteTextures(1, &texture);
}