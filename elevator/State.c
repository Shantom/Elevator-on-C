/*包含
*电梯运行时的状态判断函数
*目标楼层判断函数
*时间记录函数
*/
//////////////////////
#include"elevator.h"

extern void judgeUpDown_State（int currentFloor，int goalFloor）;//状态判断
extern void  judgeGoalFloor1_State（list *）;//策略1目标楼层判断
extern void  judgeGoalFloor2_State（list *）;//策略2目标楼层判断
extern void  judgeGoalFloor3_State（list *）;//策略3目标楼层判断
extern void  judgeGoalFloor4_State（list *）;//策略4目标楼层判断
extern void  timeRecord_State();//时间记录函数

/*
*状态判断
*/
void
judgeUpDown_State（int currentFloor，int goalFloor）
{
	if (currentFloor < goalFloor)
	    upper_Run();//电梯上行
	else if (currentFloor>goalFloor)
		downer_Run();//电梯下行
	else if (currentFloor == goalFloor)
		pause_Run();//电梯停止

}

/*
*策略1目标楼层判断
*/
void  judgeGoalFloor1_State（list **allCmd）
{
	goalFloor = (**allCmd).floorNumber;
	(*allCmd) = (*allCmd)->next;
}

/*
*策略2目标楼层判断
*/

void  judgeGoalFloor2_State（）
{
	if (elevState == UP)
	{
		while (upCmd[curFloor]！ = 1&&curFloor<=MAXFLOOR)
			curFloor++;

			goalFloor = upCmd[curFloor];
	}
	else if (elevState == DOWN)
	{
		while (upCmd[curFloor]！ = 1&&curFloor>0)
			curFloor--;

		goalFloor = upCmd[curFloor];
	}
	else if (elevState == VACANT)
	{
		
	}
}
void  judgeGoalFloor3_State（list *）
void  judgeGoalFloor4_State（list *）
void  timeRecord_State()






