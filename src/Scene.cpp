#include "Scene.h"
#include <iostream>
#include <glm/gtx/string_cast.hpp>

Scene::Scene()
    : camera(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))
{
    // Default projection matrix
    projectionMatrix = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
}

void Scene::setupModels()
{
    for (Model& model : models)
    {
        model.setupMesh();
    }
}

void Scene::render()
{
    if (shader)
    {
        shader->use();

        // set matrix projections to shader
        shader->setMat4("view", camera.getViewMatrix());
        shader->setMat4("projection", projectionMatrix);
        shader->setMat4("lightSpaceMatrix", lightSpaceMatrix);

        // set light
        shader->setInt("lightCount", lights.size());
        for (size_t i = 0; i < lights.size(); i++)
        {
            std::string baseName = "lights[" + std::to_string(i) + "]";
            lights[i]->applyToShader(baseName, shader->ID);
        }

        // set camera
        shader->setVec3("viewPos", camera.getPosition());

        shader->setSampler("shadowMap", 0); 
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, shadowMap);

        static float rotationAngle = 0.0f;
        rotationAngle += 0.01f;

        // draw models
        for (const Model& model : models)
        {

            //glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), rotationAngle, glm::vec3(0.0f, 1.0f, 0.0f));
            //glm::mat4 modelMatrix = rotationMatrix * model.getModelMatrix();
            //shader->setMat4("model", modelMatrix);
            shader->setMat4("model", model.getModelMatrix());
            shader->setVec3("objectColor", model.getColor());
            renderer->renderModel(model);
        }
        
    }
    
    else
    {
        std::cerr << "Scene shader not initialized" << std::endl;
    }
}

void Scene::setupShadowMap()
{
    // Generate framebuffer
    glGenFramebuffers(1, &shadowFBO);

    // Generate texture
    glGenTextures(1, &shadowMap);
    glBindTexture(GL_TEXTURE_2D, shadowMap);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

    // Attach texture to framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, shadowFBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, shadowMap, 0);
    glDrawBuffer(GL_NONE);
    glReadBuffer(GL_NONE);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        std::cerr << "ERROR: Shadow framebuffer is not complete!" << std::endl;
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void Scene::renderShadowMap()
{
    glBindFramebuffer(GL_FRAMEBUFFER, shadowFBO);
    glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
    glClear(GL_DEPTH_BUFFER_BIT);

    shadowShader->use();
    
    glm::mat4 lightView = lights[0]->getViewMatrix();

    glm::mat4 lightProjection = glm::ortho(-15.0f, 15.0f, -15.0f, 15.0f, 1.0f, 20.0f);


    lightSpaceMatrix = lightProjection * lightView;
    shadowShader->setMat4("lightSpaceMatrix", lightSpaceMatrix);

    for (const Model& model : models) {
        shadowShader->setMat4("model", model.getModelMatrix());
        renderer->renderModel(model);
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(0, 0, 800, 600);

}

// Rotate light around the scene (for the moment)
void Scene::update(float deltaTime)
{
    for(Light* light : lights)
    {
        light->update(deltaTime);
    }
}