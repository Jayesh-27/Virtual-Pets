#include "Window.h"
#include "Textures.h"
#include "Gameobject.h"
#include <vector>

int main()
{    
    int N = 1;
    std::vector<Object*> objects;    

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
        std::cout << "\n\nObject: " << i << "\n";
        objects.push_back(new Object);

        objects[i]->transform.position.x = 0.0f;
        objects[i]->transform.position.y = -0.84f;
        objects[i]->transform.scale = Vector3(0.25f, 0.4f, 1.0f);        
    }

    textures texture;
    texture.changeCursor(window.window);

    bool runAnimation = false;
    bool wasMousePressed = false;
    bool isMousePressed = false;
    // Main rendering loop
    while (!window.WindowShouldClose())
    {
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture.texture);

        window.getCursorPosition();
        if ((window.ndcX >= objects[0]->transform.position.x - 0.09f) &&
            (window.ndcX <= objects[0]->transform.position.x + 0.08f) &&
            (window.ndcY >= objects[0]->transform.position.y - 0.17f) &&
            (window.ndcY <= objects[0]->transform.position.y + 0.17f) &&
            !runAnimation)
        {
            glfwSetWindowAttrib(window.window, GLFW_MOUSE_PASSTHROUGH, GLFW_FALSE);
        }
        else if(!runAnimation)
        {
            glfwSetWindowAttrib(window.window, GLFW_MOUSE_PASSTHROUGH, GLFW_TRUE);
        }

        isMousePressed = glfwGetMouseButton(window.window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

        if (isMousePressed && !wasMousePressed &&
            (window.ndcX >= objects[0]->transform.position.x - 0.09f) &&
            (window.ndcX <= objects[0]->transform.position.x + 0.08f) &&
            (window.ndcY >= objects[0]->transform.position.y - 0.17f) &&
            (window.ndcY <= objects[0]->transform.position.y + 0.17f))
        {
            runAnimation = !runAnimation;
        }

        wasMousePressed = isMousePressed;

        for (int i = 0; i < N; i++)
        {
            if (runAnimation)
            {
                objects[i]->Animation.runFromCursor(window.ndcX, window.ndcY);
            }
            else
            {
                objects[i]->Animation.BackandForth();
            }
            objects[i]->Render();            
        }


        window.swapBuffer();
        glfwPollEvents();
    }
    texture.deleteTextures();  

    window.DestroyWindow();
    for (int i = 0; i < N; i++)
    {
        objects[i]->DeleteObject();
    }
    glfwTerminate();
    return 0;
}