#include <GameObject.h>


// Define vertices for a textured quad
float Object::vertices[] = {
    // positions   // texture coords
    -0.5f, -0.5f,  // bottom left
     0.5f, -0.5f,  // bottom right
     0.5f,  0.5f,  // top right
    -0.5f,  0.5f  // top left
};
float Object::texturePos[] = {
    0.0f, 0.0f,  // bottom left
    1.0f, 0.0f,  // bottom right
    1.0f, 1.0f,  // top right
    0.0f, 1.0f   // top left
};
unsigned int Object::indices[] = {
    0, 1, 2,  // first triangle
    2, 3, 0   // second triangle
};

void Object::ShaderHandling()
{
    Shader shaderProgram("C:\\Users\\jayes\\Desktop\\Virtual Pets\\VirtualPets\\Resources Files\\default.vert",
                         "C:\\Users\\jayes\\Desktop\\Virtual Pets\\VirtualPets\\Resources Files\\default.frag");
    shaderProgram.Activate();
    


    GLint texLoc = shaderProgram.GetUniformLocation("imageTexture");
    if (texLoc != -1) {
        glUniform1i(texLoc, 0);
    }
    else {
        std::cout << "Warning: imageTexture uniform not found in shader" << std::endl;
    }

    GLint posLoc = shaderProgram.GetUniformLocation("imagePosition");
    if (posLoc != -1) {
        glUniform2f(posLoc, 0.0f, 0.0f);
    }
    else {
        std::cout << "Warning: imagePosition uniform not found in shader" << std::endl;
    }

    GLint scaleLoc = shaderProgram.GetUniformLocation("imageScale");
    if (scaleLoc != -1) {
        glUniform2f(scaleLoc, 1.0f, 1.0f);
    }
    else {
        std::cout << "Warning: imageScale uniform not found in shader" << std::endl;
    }
}

void Object::VBO_VAO_EBO()
{
    VAO VAO1;   //pos
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    VBO VBO2(texturePos, sizeof(texturePos));
    EBO EBO1(indices, sizeof(indices));

    VAO1.LinkVBO(VBO1, 0);
    VAO1.LinkVBO(VBO2, 1);

    EBO1.Bind();
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();
}

void Object::mainLoopThings()
{

}

void Object::afterMainLoopThings()
{
    VAO1.Delete();
    VBO1.Delete();
    VBO2.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

}