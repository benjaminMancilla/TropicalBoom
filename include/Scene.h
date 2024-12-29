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

        void addModel(const Model& model) { models.push_back(model); }
        void setupModels();

        void setRenderer(Renderer* renderer) { this->renderer = renderer; }
        
        void setShader(Shader* shader) { this->shader = shader; }
        void setShadowShader(Shader* shadowShader) { this->shadowShader = shadowShader; }
        
        void setCamera(const Camera& camera) { this->camera = camera; }
        const Camera& getCamera() const { return camera; }

        void setProjection(const glm::mat4& projection) { projectionMatrix = projection; }
        const glm::mat4& getProjection() const { return projectionMatrix; }

        void setLightPos(const glm::vec3& lightPos) { this->lightPos = lightPos; }

        void setupShadowMap();
        void renderShadowMap();
        
        void render();
        

    private:
        Camera camera;
        Renderer* renderer = nullptr;
        std::vector<Model> models;
        Shader* shader = nullptr;
        glm::mat4 projectionMatrix;
        glm::mat4 lightSpaceMatrix;
        glm::vec3 lightPos;

        // Shadow mapping
        Shader* shadowShader = nullptr;
        unsigned int shadowFBO;
        unsigned int shadowMap;
        const unsigned int SHADOW_WIDTH = 2048, SHADOW_HEIGHT = 2048;
        

};

#endif // SCENE_H