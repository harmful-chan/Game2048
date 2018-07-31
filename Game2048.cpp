#include "Game2048.h"
#include <string.h>
#include <stdlib.h>
namespace ge{

//初始化面板空间，并初始化0
Game2048::Game2048()
{ 
    pPanel = (unit_t *)malloc(4*4*sizeof(unit_t));
    //pPanel = new unit_t[4][4];
    memset(pPanel, 0, 4*4*sizeof(unit_t));
}

//s释放面板空间
Game2048::~Game2048()
{
    delete pPanel;
}

//按方向刷新屏幕
void Game2048::RefreshPanel(Dir tAction)
{
    MergeNumber(tAction);
    MoveNumber(tAction);
    AddNumber();
}

//合并数字
void Game2048::MergeNumber(Dir tAction)
{
    int x = 0;
    int y = 0;
    int stat = 1;

    unit_t (*p)[4] = (unit_t (*)[4])pPanel;    //一维数组转二维数组指针

    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
        {
      
            switch(stat)
            {
                case 1:
                         if(tAction == LEFT)   stat = 2;
                    else if(tAction == UPWARD) stat = 3;
                    else if(tAction == RIGHT)  stat = 4;
                    else if(tAction == DOWN)   stat = 5;
                break;
                if(ZERO != p[j][i]) 
                    MergeIdentical(&(p[0][i]), &(p[j][i]));
            
                if(ZERO != p[j][i]) 
                    MergeIdentical(&(p[0][i]), &(p[j][i]));
         
                if(ZERO != p[i][3-j]) 
                    MergeIdentical(&(p[i][3]), &(p[i][3-j]));
      
                if(ZERO != p[3-j][i]) 
                    MergeIdentical(&(p[3][i]), &(p[3-j][i]));
            }
        }
    }    
}

};


