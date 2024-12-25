#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader 
{
    public:
        unsigned int ID;

        Shader(const char* vertexPath, const char* fragmentPath);
        void use();

    private:
        void checkCompileErrors(unsigned int shader, const std::string& type);
};


#endif // SHADER_H