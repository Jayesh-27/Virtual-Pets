#include "shaderClass.h"
#include <fstream>
#include <sstream>

std::string get_file_contents(const char* filename)
{
    std::ifstream in(filename, std::ios::binary);
    if (!in)
    {
        std::cerr << "ERROR: Could not open file " << filename << std::endl;
        throw(errno);
    }
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return contents;
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
    std::cout << "Shader ID: " << ID << std::endl;
    std::string vertexCode;
    std::string fragmentCode;

    try {
        vertexCode = get_file_contents(vertexFile);
        fragmentCode = get_file_contents(fragmentFile);
    }
    catch (int err) {
        std::cerr << "ERROR: Failed to read shader files (" << vertexFile << " or " << fragmentFile << "): errno " << err << std::endl;
        return; 
    }

    if (vertexCode.empty() || fragmentCode.empty())
    {
        std::cerr << "ERROR: Shader file contents are empty" << std::endl;
        return;
    }


    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmentCode.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    GLint success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR: Vertex Shader Compilation Failed\n" << infoLog << std::endl;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "ERROR: Fragment Shader Compilation Failed\n" << infoLog << std::endl;
    }

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);

    GLint linkSuccess;
    glGetProgramiv(ID, GL_LINK_STATUS, &linkSuccess);
    if (!linkSuccess) {
        char infoLog[512];
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cerr << "ERROR: Shader Program Linking Failed\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
    glUseProgram(ID);
}

void Shader::Delete()
{
    glDeleteProgram(ID);
}

int Shader::GetUniformLocation(const char* name)
{
    return glGetUniformLocation(ID, name);
}
