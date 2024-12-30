#ifndef DIRECTIONAL_LIGHT_H
#define DIRECTIONAL_LIGHT_H

#include "Light.h"

class DirectionalLight : public Light
{
    public:
        DirectionalLight(const glm::vec3& direction, const glm::vec3& color)
            : Light(glm::vec3(0.0f), color), direction(direction) {};

        void update(float deltaTime) override;

        void applyToShader(const std::string& uniformName, unsigned int shaderID) const override;

        const glm::vec3& getDirection() const { return direction; }
        void setDirection(const glm::vec3& direction) { this->direction = direction; }

        glm::mat4 getViewMatrix() const override;

    private:
        glm::vec3 direction;
};

#endif // DIRECTIONAL_LIGHT_H