#ifndef SCENE_H
#define SCENE_H

#include "Model.h"
#include "Shader.h"
#include "Renderer.h"
#include "Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

class Scene
{
    public:
        Scene();
        void addModel(const Model& model);
        void setupModels();
        
        void setShader(Shader* shader);
        
        void setCamera(const Camera& camera) { this->camera = camera; }
        const Camera& getCamera() const { return camera; }

        void setProjection(const glm::mat4& projection) { projectionMatrix = projection; }
        const glm::mat4& getProjection() const { return projectionMatrix; }
        
        void render(Renderer& renderer);
        

    private:
        Camera camera;
        std::vector<Model> models;
        Shader* shader = nullptr;
        glm::mat4 projectionMatrix;

};

#endif // SCENE_H