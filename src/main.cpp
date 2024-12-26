#include <GameWindow.h>
#include <Model.h>
#include <Scene.h>
#include <Renderer.h>

#include <iostream>

void initTriangleTest(unsigned int& VAO, unsigned int& VBO)
{
    // Vertex data
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // Generate vertex array object
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate vertex buffer object
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Set vertex attribute pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

int main ()
{
    GameWindow gameWindow(800, 600, "Hello World");
    if (!gameWindow.init()) 
    {
        return -1;
    }

    Shader shader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
    Scene scene;
    Renderer renderer;

    Model cube("models/cube.obj");
    Model triangle("models/triangle.obj");

    scene.addModel(cube);
    scene.addModel(triangle);
    scene.setShader(&shader);

    gameWindow.mainLoop(scene, renderer);

    return 0;
}


