#include "Shader.h"
#include <glad/gl.h>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
    // Read the vertex and fragment shaders from file
    
    std::ifstream vShaderFile(vertexPath), fShaderFile(fragmentPath);
    
    if (!vShaderFile.is_open()) 
    {
        std::cerr << "ERROR: Could not open vertex shader file: " << vertexPath << std::endl;
        ID = 0;
        return;
    }
    
    if (!fShaderFile.is_open()) 
    {
        std::cerr << "ERROR: Could not open fragment shader file: " << fragmentPath << std::endl;
        ID = 0;
        return;
    }

    std::stringstream vShaderStream, fShaderStream;
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();
    std::string vertexCode = vShaderStream.str();
    std::string fragmentCode = fShaderStream.str();
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    // Compile the vertex shaders
    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");

    // Compile the fragment shaders
    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    // Link the shaders
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    checkCompileErrors(ID, "PROGRAM");

    // Clear intermediate shaders
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use()
{
    if (ID) 
    {
        glUseProgram(ID);
    }
    else 
    {
        std::cerr << "Shader program not initialized" << std::endl;
    }
}

void Shader::checkCompileErrors(unsigned int shader, const std::string& type) 
{
    int success;
    char infoLog[1024];
    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n";
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            std::cerr << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n";
        }
    }
}