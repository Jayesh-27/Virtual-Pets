#include "window.h"
#include "textures.h"
#include "gameobject.h"
#include <vector>

int main()
{
    int N = 3;
    std::vector<Object*> objects;    

    //std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;
    Window window;

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        glfwTerminate();
    }
    // Configure OpenGL for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    for (int i = 0; i < N; i++)
    {
        objects.push_back(new Object);
    }

    //Object object1;
    textures texture;

    // Main rendering loop
    while (!window.WindowShouldClose())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture.texture);



        for (int i = 0; i < N; i++)
        {
            if (i == 1)
            {
                objects[i]->transform.position = Vector3(1.0f, 1.0f, 0.0f);
                objects[i]->transform.scale = Vector3(1.0f, 1.0f, 0.0f);
                objects[i]->Render();
                continue;
            }
            objects[i]->transform.position = Vector3(0.0f, 0.0f, 0.0f);
            objects[i]->transform.scale = Vector3(1.0f, 1.0f, 0.0f);
            objects[i]->Render();
        }
        
        //object1.transform.position =  Vector3(0.0f, 0.0f, 0.0f);
        //object1.transform.scale =  Vector3(1.0f, 1.0f, 0.0f);
        //object1.Render();





        window.swapBuffer();
        glfwPollEvents();
    }
    texture.deleteTextures();  

    window.DestroyWindow();
    for (int i = 0; i < N; i++)
    {
        objects[i]->DeleteObject();
    }
    //object1.DeleteObject();
    glfwTerminate();
    return 0;
}