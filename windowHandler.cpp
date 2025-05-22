#include "Window.h"

Window::Window()
{
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        glfwTerminate();
        return;
    }

    // Configure GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
    glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
    glfwWindowHint(GLFW_MOUSE_PASSTHROUGH, GLFW_TRUE);

    if (CreateWindow() != 0) {
        std::cerr << "Window creation failed\n";
        glfwTerminate();
    }
}

int Window::CreateWindow()
{
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

    // Create window
    window = glfwCreateWindow(mode->width - 2, mode->height - 2, "Transparent Image Window", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;  
    }
    else
    {
        std::cout << "Window Created Successfully\n";
    }

    int xPos = (mode->width - (mode->width - 2)) / 2;
    int yPos = (mode->height - (mode->height - 2)) / 2;
    glfwSetWindowPos(window, xPos, yPos);

    glfwMakeContextCurrent(window);
    return 0;
}

void Window::DestroyWindow()
{
    glfwDestroyWindow(window);
}

bool Window::WindowShouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::swapBuffer()
{
    glfwSwapBuffers(window);
}