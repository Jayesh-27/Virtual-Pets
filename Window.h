#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H
#include <GLFW/glfw3.h>

class Window
{
public:

    GLFWwindow* window;
    int InitializeWindow();
    int CreateWindow();
    void DestroyWindow();
    bool WindowShouldClose();
    void swapBuffer();
};
#endif
