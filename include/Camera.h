#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
    public:
        Camera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up);

        const glm::mat4& getViewMatrix() const { return viewMatrix; }

        void setPosition(const glm::vec3& position);
        void lookAt(const glm::vec3& target);

        const glm::vec3& getPosition() const { return position; }

    private:
        glm::mat4 viewMatrix;
        glm::vec3 position;
        glm::vec3 target;
        glm::vec3 up;

        void updateViewMatrix();
};

#endif // CAMERA_H