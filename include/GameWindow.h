#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <string>

//Window for the game
class GameWindow 
{
    public:
        GameWindow(int width, int height, const std::string& title);
        ~GameWindow();

        bool init();
        void mainLoop();


    private:
        int width;
        int height;
        std::string title;
        GLFWwindow* window;

        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif // GAMEWINDOW_H