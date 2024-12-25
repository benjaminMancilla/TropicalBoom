#ifndef MODEL_H
#define MODEL_H

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>
#include <string>
#include <vector>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

class Model 
{
    public:
        Model(const std::string& path);
        void draw() const;

    private:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        unsigned int Model_VAO, Model_VBO, Model_EBO;
        void setupMesh();
        void loadModel(const std::string& path);

};

#endif // MODEL_H