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
        void prepareRender(Renderer& renderer);

    private:
        std::vector<Model> models;
        Shader* shader;

};

#endif // SCENE_H