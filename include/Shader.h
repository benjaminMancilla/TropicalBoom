#ifndef SHADER_H
#define SHADER_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>

class Shader 
{
    public:
        unsigned int ID;

        Shader(const char* vertexPath, const char* fragmentPath);
        void use();

        void setMat4(const std::string& name, const glm::mat4& mat) const;
        void setVec3(const std::string& name, const glm::vec3& vec) const;
        void setSampler(const std::string& name, int textureUnit) const;
        void setInt(const std::string& name, int value) const;

    private:
        void checkCompileErrors(unsigned int shader, const std::string& type);
};


#endif // SHADER_H