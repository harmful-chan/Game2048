//Game2048.h

#ifndef _GAME2048_H_
#define _GAME2048_H_
namespace ge
{

#define ZERO 0


typedef unsigned int unit_t; 

typedef enum FreshDirection
{
    UPWARD,
    DOWN,
    LEFT,
    RIGHT
}Dir;

class Game2048
{
private :
    unit_t *pPanel;

    void MergeNumber(Dir tAction);    //合并数字
    void MoveNumber(Dir tAction);    //数字移动
    void AddNumber();    //空白处添加数字

    int MergeIdentical(unit_t *pSrcNum, unit_t *pDetNum);    //相同数字合并
    int ExchangeZero(unit_t *pSrcNum, unit_t *pDetNum);    //nSrcNum为0则两者交换位置
    
public :
    Game2048();    //面板初始化
    ~Game2048();       
    void RefreshPanel(Dir tAction);    //面板刷新方向

    
    
    
};

};
#endif
