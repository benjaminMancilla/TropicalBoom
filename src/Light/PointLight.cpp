#include "Light/PointLight.h"
#include <glad/gl.h>

void PointLight::update(float deltaTime)
{
    // Do nothing
}

void PointLight::applyToShader(const std::string& uniformName, unsigned int shaderID) const
{
    int posLoc = glGetUniformLocation(shaderID, (uniformName + ".position").c_str());
    int colorLoc = glGetUniformLocation(shaderID, (uniformName + ".color").c_str());
    int typeLoc = glGetUniformLocation(shaderID, (uniformName + ".type").c_str());
    glUniform3fv(posLoc, 1, &position[0]);
    glUniform3fv(colorLoc, 1, &color[0]);
    glUniform1i(typeLoc, LIGHT_TYPE_POINT);
}

glm::mat4 PointLight::getViewMatrix() const
{
    glm::mat4 lightView = glm::lookAt(this->getPosition(), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    return lightView;

}