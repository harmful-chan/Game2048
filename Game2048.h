//Game2048.h

#ifndef _GAME2048_H_
#define _GAME2048_H_
namespace ge
{

#define ZERO 0


typedef unsigned int unit_t; 


/* 方向定义 */
typedef enum FreshDirection
{
    UP = 1,
    DOWN,
    LEFT,
    RIGHT
}Dir;

class Game2048
{
private :
    unit_t *pPanel;

    int MergeNumber(Dir tAction);    //合并数字,执行完成返回0, 否则-1
    int MoveNumber(Dir tAction);    //数字移动,执行完成返回0,否则-1
    void AddNumber();    //空白区域产生随机数

    int MergeIdentical(unit_t *pSrcNum, unit_t *pDetNum);    //相同数字合并
    int ExchangeIdentical(unit_t *pSrcNum, unit_t *pDetNum);    //交换数字 


public :
    Game2048();    //面板初始化空间为空
    Game2048(unit_t *p){pPanel = p;};    //人为初始化
    ~Game2048();       
    void RefreshPanel(Dir tAction);    //面板刷新方向

    //测试
    void Show();    //显示
    
};

};
#endif
