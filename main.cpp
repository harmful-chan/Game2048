#include "Game2048.h"
#include <iostream>
#include <string.h>
using namespace ge;

int main()
{
   /* 
    unit_t *p = (unit_t *)malloc(4*4*sizeof(unit_t));
    p[0]  = 2; p[1]  = 0; p[2]  = 0; p[3]  = 0;
    p[4]  = 0; p[5]  = 2; p[6]  = 0; p[7]  = 0;
    p[8]  = 0; p[9]  = 0; p[10] = 2; p[11] = 0;
    p[12] = 0; p[13] = 0; p[14] = 0; p[15] = 2;

    Game2048 game(p);
    game.Show(); 
    */
    
        Game2048 game;
        AddNumber();
        game.Show();
        std::cout << "1" << "----------------" << std::endl;
        game.RefreshPanel(UP);
        game.Show();
        std::cout << "2" << "----------------" << std::endl;
        game.RefreshPanel(DOWN);
        game.Show();
        std::cout << "3" << "----------------" << std::endl;
        game.RefreshPanel(LEFT);
        game.Show();
        std::cout << "4" << "----------------" << std::endl;
        game.RefreshPanel(RIGHT);
        game.Show();
   
    return 0;
}
