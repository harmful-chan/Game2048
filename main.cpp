#include "Game2048.h"
#include <iostream>
using namespace ge;

int main()
{
    Game2048 game;
   

    game.AddNumber();

    game.Show();

    
        std::cout << "1" << "----------------" << std::endl;
        //game.RefreshPanel(UP);
        game.RefreshPanel(LEFT);
        game.Show();
        std::cout << "2" << "----------------" << std::endl;
       // game.RefreshPanel(DOWN);
        game.RefreshPanel(LEFT);
        game.Show();
        std::cout << "3" << "----------------" << std::endl;
        game.RefreshPanel(LEFT);
        game.Show();
        std::cout << "4" << "----------------" << std::endl;
       // game.RefreshPanel(RIGHT);
        game.RefreshPanel(LEFT);
        game.Show();

    return 0;
}
