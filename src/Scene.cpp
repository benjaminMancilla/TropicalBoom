#include "Scene.h"

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
    }
    for (const Model& model : models)
    {
        renderer.renderModel(model);
    }
}