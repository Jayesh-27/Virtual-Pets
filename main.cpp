#include "Window.h"
#include "textures.h"
#include "GameObject.h"

int main()
{
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        glfwTerminate();
    }
    Window window;
    Object object1;
    textures texture;

    // Main rendering loop
    while (!window.WindowShouldClose())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);        
        
        object1.mainLoopThings();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);        

        window.swapBuffer();
        glfwPollEvents();
    }
    texture.deleteTextures();  

    window.DestroyWindow();
    object1.afterMainLoopThings();
    glfwTerminate();
    return 0;
}