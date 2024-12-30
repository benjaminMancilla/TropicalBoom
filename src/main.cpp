#include <GameWindow.h>
#include <Model.h>
#include <Scene.h>
#include <Renderer.h>
#include <Light/DirectionalLight.h>
#include <Light/PointLight.h>

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

int main() {
    // Window
    GameWindow gameWindow(800, 600, "Tropical Boom");
    if (!gameWindow.init()) {
        return -1;
    }
    
    // Scene
    Scene scene;

    // Shader
    Shader shader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
    Shader shadowShader("shaders/shadow_vertex_shader.glsl", "shaders/shadow_fragment_shader.glsl");

    scene.setShader(&shader);
    scene.setShadowShader(&shadowShader);
    
    // Projection
    scene.setProjection(glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f));

    // Camera
    Camera camera(glm::vec3(0.0f, 1.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    scene.setCamera(camera);

    // Lights
    DirectionalLight* light = new DirectionalLight(glm::vec3(-1.0f, -20.0f, -20.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    scene.addLight(light);
    PointLight* pointLight = new PointLight(glm::vec3(4.0f, 6.0f, 4.0f), glm::vec3(0.9f, 0.9f, 0.9f));
    scene.addLight(pointLight);


    // Models
    Model cube("models/cube.obj");
    cube.setColor(glm::vec3(0.0f, 1.0f, 0.0f));

    Model triangle("models/triangle.obj");
    triangle.setColor(glm::vec3(0.0f, 0.0f, 1.0f));

    Model plane("models/plane.obj");
    plane.setColor(glm::vec3(0.8f, 0.8f, 0.8f));

    scene.addModel(cube);
    scene.addModel(triangle);
    scene.addModel(plane);

    // Render
    scene.setupModels();
    scene.setupShadowMap();

    Renderer renderer;
    scene.setRenderer(&renderer);

    gameWindow.mainLoop(scene);

    return 0;
}



