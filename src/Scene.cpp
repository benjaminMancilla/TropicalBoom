#include "Scene.h"
#include <iostream>
#include <glm/gtx/string_cast.hpp>

Scene::Scene()
    : camera(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))
{
    // Default projection matrix
    projectionMatrix = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

void Scene::addModel(const Model& model)
{
    models.push_back(model);
}

void Scene::setShader(Shader* shader)
{
    this->shader = shader;
}

void Scene::setupModels()
{
    for (Model& model : models)
    {
        model.setupMesh();
    }
}

void Scene::render(Renderer& renderer)
{
    if (shader)
    {
        shader->use();

        // set matrix projections to shader
        shader->setMat4("view", camera.getViewMatrix());
        shader->setMat4("projection", projectionMatrix);

        // set light
        shader->setVec3("lightPos", glm::vec3(2.0f, 2.0f, 2.0f));
        shader->setVec3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
        shader->setVec3("viewPos", camera.getPosition());

        static float rotationAngle = 0.0f; // Acumula el ángulo de rotación
        rotationAngle += 0.01f; // Incrementa el ángulo en cada fotograma

        // draw models
        for (const Model& model : models)
        {

            glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), rotationAngle, glm::vec3(0.0f, 1.0f, 0.0f));
            glm::mat4 modelMatrix = rotationMatrix * model.getModelMatrix();
            shader->setMat4("model", modelMatrix);
            shader->setVec3("objectColor", model.getColor());
            //shader->setMat4("model", model.getModelMatrix());
            renderer.renderModel(model);
        }
        
    }
    
    else
    {
        std::cerr << "Scene shader not initialized" << std::endl;
    }
}