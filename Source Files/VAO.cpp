#include"VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO& VBO, GLuint layout)
{
    VBO.Bind();
    // If layout is 0, it's the position (first 2 floats)
    if (layout == 0) {
        glVertexAttribPointer(layout, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    }
    // If layout is 1, it's the texture coordinates (second 2 floats)
    else if (layout == 1) {
        glVertexAttribPointer(layout, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
    }
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(ID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}