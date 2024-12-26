#ifndef SCENE_H
#define SCENE_H

#include "Model.h"
#include "Shader.h"
#include "Renderer.h"

#include <vector>

class Scene
{
    public:
        void addModel(const Model& model);
        void setShader(Shader* shader);
        void setupModels();
        void render(Renderer& renderer);

    private:
        std::vector<Model> models;
        Shader* shader = nullptr;

};

#endif // SCENE_H