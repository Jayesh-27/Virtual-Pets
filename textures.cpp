#include <textures.h>

textures::textures()
{
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("C:/Users/jayes/Desktop/Assests/Penguin.png", &imgWidth, &imgHeight, &nrChannels, 4);
    
    std::cout << "Image loaded: " << imgWidth << "x" << imgHeight << " with " << nrChannels << " channels" << std::endl;
    if (!data) {
        std::cerr << "Failed to load image\n";
        glfwTerminate();
        return;
    }
    std::cout << "Penguin Image size: " << imgWidth << "x" << imgHeight << std::endl;

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
        glfwTerminate();
    }
    // Bind texture to texture unit 0
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
}

void textures::changeCursor(GLFWwindow* window)
{
    stbi_set_flip_vertically_on_load(false);  

    cursorData = stbi_load("C:\\Users\\jayes\\Desktop\\Assests\\Fire.png", &imgWidth, &imgHeight, &nrChannels, 4);

    if (cursorData) {
        GLFWimage image;
        image.width = imgWidth;
        image.height = imgHeight;
        image.pixels = cursorData;

        cursor = glfwCreateCursor(&image, 0, 0);
        glfwSetCursor(window, cursor);

        stbi_image_free(cursorData);
        std::cout << "Loaded cursor image.\n";
    }
    else {
        std::cout << "Failed to load cursor image.\n";
    }

    if (cursor) {
        glfwSetCursor(window, cursor);
    }
}


void textures::deleteTextures()
{
    glDeleteTextures(1, &texture);
}