/*包含
*电梯运行时的状态判断函数
*目标楼层判断函数
*时间记录函数
*/
//////////////////////
#include"elevator.h"


/*
*状态判断
*/
void
judgeUpDown_State(int currentFloor,int goalFloor)
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
void  judgeGoalFloor1_State(list **allCmd)
{
	while ((*allCmd)->next == NULL)
		Sleep(1);//当没有下一条指令

	goalFloor = (**allCmd).floorNumber;
	(*allCmd) = (*allCmd)->next;
}

/*
*策略2目标楼层判断
*/

void  judgeGoalFloor2_State()
{
	if (elevState == UP)
	{
		while (upCmd[curFloor]!= 1&&curFloor<=MAXFLOOR)
			curFloor++;

			goalFloor = upCmd[curFloor];
	}
	else if (elevState == DOWN)
	{
		while (upCmd[curFloor]!= 1&&curFloor>0)
			curFloor--;

		goalFloor = upCmd[curFloor];
	}
	else if (elevState == VACANT)
	{
		goalFloor = 0;
	}
}
//void  judgeGoalFloor3_State(list *)
//void  judgeGoalFloor4_State(list *)
//void  timeRecord_State()






