#include <GameWindow.h>

int main ()
{
    GameWindow gameWindow(800, 600, "Hello World");
    if (!gameWindow.init()) 
    {
        return -1;
    }
    gameWindow.mainLoop();
    return 0;
}


