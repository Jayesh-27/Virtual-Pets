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
    Object object2;
    textures texture;
    float temp1 = 0.0f;
    bool btemp1 = false;
    float temp2 = 1.0f;
    bool btemp2 = false;

    // Main rendering loop
    while (!window.WindowShouldClose())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);        
        
        object1.transform.position.x = temp1;
        object1.transform.position.y = 0.0f;
        object1.Render();

        object2.transform.position.x = temp2;
        object2.transform.position.y = 0.0f;
        object2.Render();

        if (btemp1)
        {
            temp1 -= 0.001f;
            if (temp1 <= 0.0f)
                btemp1 = false;
        }
        else
        {
            temp1 += 0.001f;
            if (temp1 >= 1.0f)
                btemp1 = true;
        }


        if (btemp2)
        {
            temp2 -= 0.001f;
            if (temp2 <= 0.0f)
                btemp2 = false;
        }
        else
        {
            temp2 += 0.001f;
            if (temp2 >= 1.0f)
                btemp2 = true;
        }

        std::cout << "temp1 is " << temp1 << " and temp2 is " << temp2 << std::endl;
        window.swapBuffer();
        glfwPollEvents();
    }
    texture.deleteTextures();  

    window.DestroyWindow();
    object2.afterRender();
    glfwTerminate();
    return 0;
}