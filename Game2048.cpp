#include "Game2048.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

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
    MoveNumber(tAction);
    MergeNumber(tAction);
    MoveNumber(tAction);
    AddNumber();

}
//合并数字
int Game2048::MergeNumber(Dir tAction)
{
    int ret = 0;

    unit_t (*p)[4] = (unit_t (*)[4])pPanel;    //一维数组转二维数组指

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(tAction == UP)
                if(p[j][3-i] != ZERO && p[j][3-i] == p[j+1][3-i])
                { 
                    ret = -1;
                    MergeIdentical(&p[j][3-i], &p[j+1][3-i]);
                }
            else if(tAction == DOWN)
                if(p[3-j][i] != ZERO && p[3-j][i] == p[3-j-1][i])
                { 
                    ret = -1;
                    MergeIdentical(&p[3-j][i], &p[3-j-1][i]);
                }
            else if(tAction == LEFT)
                if(p[i][j] != ZERO && p[i][j] == p[i][j+1])
                { 
                    ret = -1;
                    MergeIdentical(&p[i][j], &p[i][j+1]);
                }
            else if(tAction == RIGHT)
                if(p[3-i][3-j] != ZERO && p[3-i][3-j] == p[3-i][3-j-1])
                { 
                    ret = -1;
                    MergeIdentical(&p[3-i][3-j], &p[3-i][3-j-1]);
                }
        }
    }

    return ret;
}

//移动数字
int Game2048::MoveNumber(Dir tAction)
{
    int ret = 0;
        
    unit_t (*p)[4] = (unit_t (*)[4])pPanel;    //一维转二维数组

    for(int i = 0; i < 4; i++)    //行
    {
        for(int j = 0; j < 4; j++)   //同行内
        {
            if(tAction == UP) 
                if(p[j][3-i] != ZERO) 
                    continue;
            else if(tAction == DOWN)
                if(p[3-j][i] != ZERO)   
                    continue; 
            else if(tAction == LEFT)
                if(p[i][j] != ZERO)     
                    continue; 
            else if(tAction == RIGHT)
                if(p[3-i][3-j] != ZERO) 
                    continue; 
    
           
            for(int k = j+1; k < 4; k++)
            {
                if(tAction == UP) 
                {
                    if(p[k][3-i] == ZERO)   
                        continue; 
                    ExchangeIdentical(&p[j][3-i], &p[k][3-i]);
                }
                else if(tAction == DOWN)
                {
                    if(p[3-k][i] == ZERO)   
                        continue; 
                    ExchangeIdentical(&p[3-j][i], &p[3-k][i]);
                }
                else if(tAction == LEFT)
                {
                    if(p[i][k] == ZERO)     
                        continue; 
                    ExchangeIdentical(&p[i][j], &p[i][k]);
                }
                else if(tAction == RIGHT)
                {
                    if(p[3-i][3-k] == ZERO) 
                        continue; 
                    ExchangeIdentical(&p[3-i][3-j], &p[3-i][3-k]);
                }

                ret = -1;
                break;
            }
        }
    }

    return ret;
}

//生成随机数
void Game2048::AddNumber()
{
    srand((unsigned int)time(NULL));

    for(int i = 0; i < 16; i++)
    { 
        if(pPanel[i] == ZERO)
        {
            int nStat = rand()%4;
            if(nStat == 0) 
                (rand()%2 == ZERO) ? pPanel[i] = 2 : pPanel[i] = 4;  
        }
    }
}



//交换数字
int Game2048::ExchangeIdentical(unit_t *pSrcNum, unit_t *pDetNum)
{
    unit_t tTmp = *pSrcNum;
    *pSrcNum = *pDetNum;
    *pDetNum = tTmp;
}
//合并数字
int Game2048::MergeIdentical(unit_t *pSrcNum, unit_t *pDetNum)
{
    *pSrcNum *= 2;
    *pDetNum = ZERO;
}


void Game2048::Show()
{
    for(int i = 0; i < 16; i++)
    {
        std::cout << pPanel[i] << " ";
        if(i % 4 == 3)
            std::cout << std::endl;
    }

}

};


