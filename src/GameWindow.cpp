#include "GameWindow.h"
#include "Shader.h"
#include "Model.h"

#include <iostream>
#include <vector>

// Constructor
GameWindow::GameWindow(int width, int height, const std::string& title)
    : width(width), height(height), title(title), window(nullptr) {}

// Destructor
GameWindow::~GameWindow() 
{
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

    glEnable(GL_DEPTH_TEST);

    return true;
}

// Callback for framebuffer size
void GameWindow::framebufferSizeCallback(GLFWwindow* window, int width, int height) 
{
    glViewport(0, 0, width, height);
}

// Main loop with Models
void GameWindow::mainLoop(Scene& scene) 
{
    while (!glfwWindowShouldClose(window)) 
    {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render the scene
        scene.renderShadowMap();
        scene.render();

        // Swap chain and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

