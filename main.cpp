#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

int main()
{
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    // Configure GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
    glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
    glfwWindowHint(GLFW_MOUSE_PASSTHROUGH, GLFW_TRUE);

    // Create window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Transparent Image Window", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Load OpenGL functions
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        return -1;
    }

    // Print OpenGL version for debugging
    std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

    // Load image
    int imgWidth, imgHeight, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("C:/Users/jayes/Desktop/Assests/pixelated-BallonwithPenguin.png", &imgWidth, &imgHeight, &nrChannels, 4);
    if (!data) {
        std::cerr << "Failed to load image\n";
        return -1;
    }

    std::cout << "Image loaded: " << imgWidth << "x" << imgHeight << " with " << nrChannels << " channels" << std::endl;

    // Create texture
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        
    // Upload texture data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);

    // Check for texture creation errors
    GLenum err = glGetError();
    if (err != GL_NO_ERROR) {
        std::cout << "OpenGL texture error: " << err << std::endl;
    }

    // Define vertices for a textured quad
    float vertices[] = {
        // positions    // texture coords
        -0.5f, -0.5f,  0.0f, 0.0f,  // bottom left
         0.5f, -0.5f,  1.0f, 0.0f,  // bottom right
         0.5f,  0.5f,  1.0f, 1.0f,  // top right
        -0.5f,  0.5f,  0.0f, 1.0f   // top left
    };

    unsigned int indices[] = {
        0, 1, 2,  // first triangle
        2, 3, 0   // second triangle
    };

    // Create shader program
    Shader shaderProgram("C:\\Users\\jayes\\Desktop\\Virtual Pets\\VirtualPets\\Resources Files\\default.vert",
        "C:\\Users\\jayes\\Desktop\\Virtual Pets\\VirtualPets\\Resources Files\\default.frag");

    // Create and configure VAO, VBO, EBO
    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    // Set up vertex attributes
    VAO1.LinkVBO(VBO1, 0);  // Position attribute (layout location 0 in shader)
    VAO1.LinkVBO(VBO1, 1);  // Texture coordinate attribute (layout location 1 in shader)

    // Unbind everything to prevent accidental modifications
    EBO1.Bind();  // Keep the EBO bound to the VAO
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();  // Now unbind the EBO

    // Check for setup errors
    while ((err = glGetError()) != GL_NO_ERROR) {
        std::cout << "OpenGL setup error: " << err << std::endl;
    }

    // Configure OpenGL for transparency
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Main rendering loop
    while (!glfwWindowShouldClose(window))
    {
        // Clear the screen with transparent black
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use shader program
        shaderProgram.Activate();

        // Bind texture to texture unit 0
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture);

        // Set uniforms
        GLint texLoc = shaderProgram.GetUniformLocation("imageTexture");
        if (texLoc != -1) {
            glUniform1i(texLoc, 0);  // Texture unit 0
        }
        else {
            std::cout << "Warning: imageTexture uniform not found in shader" << std::endl;
        }

        GLint posLoc = shaderProgram.GetUniformLocation("imagePosition");
        if (posLoc != -1) {
            glUniform2f(posLoc, 0.0f, 0.0f);  // Center position
        }
        else {
            std::cout << "Warning: imagePosition uniform not found in shader" << std::endl;
        }

        GLint scaleLoc = shaderProgram.GetUniformLocation("imageScale");
        if (scaleLoc != -1) {
            glUniform2f(scaleLoc, 1.0f, 1.0f);  // Normal scale
        }
        else {
            std::cout << "Warning: imageScale uniform not found in shader" << std::endl;
        }
        GLint colorLoc = shaderProgram.GetUniformLocation("triangleColor");
        if (colorLoc != -1) {
            glUniform4f(colorLoc, 1.0f, 0.0f, 0.0f, 1.0f); // Example: solid red
        }
        // Draw the quad
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Check for rendering errors
        err = glGetError();
        if (err != GL_NO_ERROR) {
            std::cout << "OpenGL render error: " << err << std::endl;
        }

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();
    glDeleteTextures(1, &texture);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}