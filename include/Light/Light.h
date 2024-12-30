#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>

#define LIGHT_TYPE_DIRECTIONAL 0
#define LIGHT_TYPE_POINT 1

class Light
{
    public:
        Light(const glm::vec3& position, const glm::vec3& color)
            : position(position), color(color) {};

        virtual ~Light() {};

        virtual void update(float deltaTime) {};

        virtual void applyToShader(const std::string& uniformName, unsigned int shaderID) const = 0;

        const glm::vec3& getPosition() const { return position; }
        void setPosition(const glm::vec3& position) { this->position = position; }

        const glm::vec3& getColor() const { return color; }
        void setColor(const glm::vec3& color) { this->color = color; }

        virtual glm::mat4 getViewMatrix() const = 0;



    protected:
        glm::vec3 position;
        glm::vec3 color;

};

#endif // LIGHT_H