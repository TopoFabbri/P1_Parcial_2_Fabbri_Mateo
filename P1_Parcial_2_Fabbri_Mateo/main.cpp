#include <iostream>
#include <ctime>

#include "AwesomeLibrary.h"
#include "Game.h"

void runProgram();
void defaults();

void main()
{
    runProgram();
}

void runProgram()
{
    defaults();
    Base* game = new Game();
    dynamic_cast<Game*>(game)->loop();
    delete game;
}

void defaults()
{
    srand(time(nullptr));
    hideCursor();
}