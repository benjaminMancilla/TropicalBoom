#ifndef POINT_LIGHT_H
#define POINT_LIGHT_H

#include "Light.h"

class PointLight : public Light
{
    public:
        PointLight(const glm::vec3& position, const glm::vec3& color)
            : Light(position, color) {};

        void update(float deltaTime) override;

        void applyToShader(const std::string& uniformName, unsigned int shaderID) const override;

        glm::mat4 getViewMatrix() const override;

    private:

};

#endif // POINT_LIGHT_H