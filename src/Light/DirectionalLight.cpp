#include "Light/DirectionalLight.h"
#include <glad/gl.h>

void DirectionalLight::applyToShader(const std::string& uniformName, unsigned int shaderID) const
{
    int directionLoc = glGetUniformLocation(shaderID, (uniformName + ".direction").c_str());
    int colorLoc = glGetUniformLocation(shaderID, (uniformName + ".color").c_str());
    int typeLoc = glGetUniformLocation(shaderID, (uniformName + ".type").c_str());
    glUniform3fv(directionLoc, 1, &direction[0]);
    glUniform3fv(colorLoc, 1, &color[0]);
    glUniform1i(typeLoc, LIGHT_TYPE_DIRECTIONAL);

}

void DirectionalLight::update(float deltaTime)
{
    // Rotate light around the scene
    static float angle = 0.0f;
    angle += 0.1f * deltaTime;
    float radius = 5.0f;
    direction = glm::vec3(radius * cos(angle), 3.0f, radius * sin(angle));
}

glm::mat4 DirectionalLight::getViewMatrix() const
{
    glm::vec3 lightDir = normalize(this->getDirection());
    glm::mat4 lightView = glm::lookAt(lightDir * 10.0f, glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    return lightView;

}