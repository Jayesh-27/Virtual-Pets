#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Window.h"
#include "textures.h"
#include "GameObject.h"

int main()
{
    Window window;
    if (window.InitializeWindow() != 0) {
        std::cerr << "Window initialization failed\n";
        return -1;
    }

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
           
    textures texture;
    texture.InitializeTexture();

    // Configure OpenGL for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Main rendering loop
    while (!window.WindowShouldClose())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        GLint texLoc = shaderProgram.GetUniformLocation("imageTexture");
        if (texLoc != -1) {
            glUniform1i(texLoc, 0);
        }
        else {
            std::cout << "Warning: imageTexture uniform not found in shader" << std::endl;
        }

        GLint posLoc = shaderProgram.GetUniformLocation("imagePosition");
        if (posLoc != -1) {
            glUniform2f(posLoc, 0.0f, 0.0f);
        }
        else {
            std::cout << "Warning: imagePosition uniform not found in shader" << std::endl;
        }

        GLint scaleLoc = shaderProgram.GetUniformLocation("imageScale");
        if (scaleLoc != -1) {
            glUniform2f(scaleLoc, 1.0f, 1.0f);
        }
        else {
            std::cout << "Warning: imageScale uniform not found in shader" << std::endl;
        }
        
        VAO1.Bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        GLenum err;
        while ((err = glGetError()) != GL_NO_ERROR)
            std::cout << "GL ERROR: " << err << std::endl;

        window.swapBuffer();
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    VBO2.Delete();
    EBO1.Delete();
    shaderProgram.Delete();
    texture.deleteTextures();  

    window.DestroyWindow();
    glfwTerminate();
    return 0;
}