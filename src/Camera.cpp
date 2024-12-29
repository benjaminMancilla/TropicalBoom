#include "Camera.h"

Camera::Camera(const glm::vec3& position, const glm::vec3& target, const glm::vec3& up)
    : position(position), target(target), up(up)
{
    viewMatrix = glm::lookAt(position, target, up);
}

void Camera::setPosition(const glm::vec3& position)
{
    this->position = position;
    viewMatrix = glm::lookAt(position, target, up);
}

void Camera::lookAt(const glm::vec3& target)
{
    this->target = target;
    viewMatrix = glm::lookAt(position, target, up);
}

void Camera::updateViewMatrix()
{
    viewMatrix = glm::lookAt(position, target, up);
}