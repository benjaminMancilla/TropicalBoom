#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Model.h"
#include "Scene.h"
#include "Renderer.h"

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
        void mainLoop(Scene& scene);



    private:
        GLFWwindow* window;
        int width;
        int height;
        std::string title;

        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif // GAMEWINDOW_H