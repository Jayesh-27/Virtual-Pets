#include"VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &ID);
	std::cout << "VAO ID: " << ID << std::endl;
}

void VAO::LinkVBO(VBO& VBO, GLuint layout)
{
    VBO.Bind();    
	glVertexAttribPointer(layout, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
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