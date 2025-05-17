#include <GameObject.h>


// Define vertices for a textured quad
float Object::vertices[8] = {
    // positions   // texture coords
    -0.5f, -0.5f,  // bottom left
     0.5f, -0.5f,  // bottom right
     0.5f,  0.5f,  // top right
    -0.5f,  0.5f  // top left
};
float texturePos[] = {
    0.0f, 0.0f,  // bottom left
    1.0f, 0.0f,  // bottom right
    1.0f, 1.0f,  // top right
    0.0f, 1.0f   // top left
};
unsigned int indices[] = {
    0, 1, 2,  // first triangle
    2, 3, 0   // second triangle
};