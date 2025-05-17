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

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        glfwTerminate();
    }

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    Object object1;
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

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        object1.mainLoopThings();
        GLenum err;
        while ((err = glGetError()) != GL_NO_ERROR)
            std::cout << "GL ERROR: " << err << std::endl;

        window.swapBuffer();
        glfwPollEvents();
    }
    texture.deleteTextures();  

    window.DestroyWindow();
    object1.afterMainLoopThings();
    glfwTerminate();
    return 0;
}