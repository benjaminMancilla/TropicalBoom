#ifndef MODEL_H
#define MODEL_H

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <iostream>
#include <string>
#include <vector>

struct Vertex 
{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

class Model 
{
    public:
        Model(const std::string& path);

        void setupMesh(); // GPU setup
        unsigned int getVAO() const { return Model_VAO; }
        const std::vector<unsigned int>& getIndices() const { return indices; }
        const std::vector<Vertex>& getVertices() const { return vertices; }
        const glm::mat4& getModelMatrix() const { return modelMatrix; }

        const glm::vec3& getColor() const { return color; }
        void setColor(const glm::vec3& color) { this->color = color; }

        void translate(const glm::vec3& translation);
        void rotate(float angle, const glm::vec3& axis);
        void scale(const glm::vec3& scale);

    private:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        unsigned int Model_VAO, Model_VBO, Model_EBO;
        
        void loadModel(const std::string& path);

        glm::mat4 modelMatrix = glm::mat4(1.0f); // Identity matrix

        glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);

};

#endif // MODEL_H