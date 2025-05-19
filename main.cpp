#include "window.h"
#include "textures.h"
#include "gameobject.h"

int main()
{
    //std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    Window window;

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        glfwTerminate();
    }
    // Configure OpenGL for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    Object object1;
    textures texture;

    // Main rendering loop
    while (!window.WindowShouldClose())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture.texture);




        
        object1.transform.position =  Vector3(0.0f, 0.0f, 0.0f);
        object1.transform.scale =  Vector3(1.0f, 1.0f, 0.0f);
        object1.Render();





        window.swapBuffer();
        glfwPollEvents();
    }
    texture.deleteTextures();  

    window.DestroyWindow();
    object1.DeleteObject();
    glfwTerminate();
    return 0;
}