#include "Game2048.h"
#include <stdlib.h>
namespace ge{

//初始化面板空间，并初始化0
Game2048::Game2048()
{ 
    pPanel = (unit_t *)malloc(4*4*sizeof(unit_t));
    memset(pPanel, 0, sizeof(pPanel));
}

//s释放面板空间
Game2048::~Game2048()
{
    delete nPanel;
}

//按方向刷新屏幕
Game2048::RefreshPanel(Dir tAction)
{
    MergeNumber(tAction);
    MoveNumber(tAction);
    AddNumber();
}

//合并数字
Game2048::MergeNumber(Dir tAction)
{
    int x = 0;
    int y = 0;
    int stat = 1;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
        {
            while(stat)
            switch(stat)
            {
                case 1:
                         if(tAction == LETF)   stat = 2;
                    else if(tAction == UPWARD) stat = 3;
                    else if(tAction == RIGHT)  stat = 4;
                    else if(tAction == DOWN)   stat = 5;
                break;
                if(ZERO != *(nPanel[j][i])) 
                    MergeIdentical(*(nPanel[0][i]), *(nPanel[j][i]));
            
                if(ZERO != *(nPanel[j][i])) 
                    MergeIdentical(*(nPanel[0][i]), *(nPanel[j][i]));
         
                if(ZERO != *(nPanel[i][3-j])) 
                    MergeIdentical(*(nPanel[i][3]), *(nPanel[i][3-j]));
      
                if(ZERO != *(nPanel[3-j][i])) 
                    MergeIdentical(*(nPanel[3][i]), *(nPanel[3-j][i]));
            }
        }
    }    

    //向左
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
        {
            if(ZERO != *(nPanel[i][j])) 
            {
                MergeIdentical(*(nPanel[i][0]), *(nPanel[i][j]));
                break;
            }
        }
    }
    //向上
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
        {
            if(ZERO != *(nPanel[j][i])) 
            {
                MergeIdentical(*(nPanel[0][i]), *(nPanel[j][i]));
                break;
            }
        }
    } 

    //向右
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
        {
            if(ZERO != *(nPanel[i][3-j])) 
            {
                MergeIdentical(*(nPanel[i][3]), *(nPanel[i][3-j]));
                break;
            }
        }
    } 

    //向下
    for(int i = 0; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
        {
            if(ZERO != *(nPanel[3-j][i])) 
            {
                MergeIdentical(*(nPanel[3][i]), *(nPanel[3-j][i]));
                break;
            }
        }
    }
}




};
