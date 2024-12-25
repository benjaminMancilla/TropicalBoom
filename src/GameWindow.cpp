#include "GameWindow.h"
#include "Shader.h"

#include <iostream>
#include <vector>

// Constructor
GameWindow::GameWindow(int width, int height, const std::string& title)
    : width(width), height(height), title(title), window(nullptr), shader(nullptr) {}

// Destructor
GameWindow::~GameWindow() 
{
    if (shader) {delete shader;}
    if (window) {glfwDestroyWindow(window);}
    glfwTerminate();
}

// Init GLFW library and create window
bool GameWindow::init() 
{
    // Init GLFW
    if (!glfwInit()) 
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    // Crete GLFW window
    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (!window) 
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    // Make context
    glfwMakeContextCurrent(window);

    // Init GLAD
    if (!gladLoadGL(glfwGetProcAddress)) 
    {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return false;
    }

    // Config viewport
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glViewport(0, 0, width, height);

    // Init shader
    shader = new Shader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");

    return true;
}

// Callback for framebuffer size
void GameWindow::framebufferSizeCallback(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

// Main loop
void GameWindow::mainLoop(const unsigned int* VAOs, const int* vertexCounts, size_t objectCount) 
{
    while (!glfwWindowShouldClose(window)) 
    {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Use the shader
        shader->use();

        // Draw the VAO
        if (VAOs && vertexCounts) 
        {
            for (size_t i = 0; i < objectCount; i++) 
            {
                glBindVertexArray(VAOs[i]);
                glDrawArrays(GL_TRIANGLES, 0, vertexCounts[i]);
            }
            glBindVertexArray(0); // Unbind VAO
        }

        // Swap chain and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}
