#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Shader.h"
#include "Model.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <string>
#include <vector>

//Window for the game
class GameWindow 
{
    public:
        GameWindow(int width, int height, const std::string& title);
        ~GameWindow();

        bool init();
        void mainLoop(const std::vector<Model>& models);
        void mainLoop(const unsigned int* VAOs, const int* vertexCounts, size_t objectCount);



    private:
        int width;
        int height;
        std::string title;
        GLFWwindow* window;
        Shader* shader;


        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif // GAMEWINDOW_H