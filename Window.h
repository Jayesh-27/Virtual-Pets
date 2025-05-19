#ifndef WINDOW_CLASS_H
#define WINDOW_CLASS_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:

    GLFWwindow* window;
    Window();
    int CreateWindow();
    void DestroyWindow();
    bool WindowShouldClose();
    void swapBuffer();
};
#endif
