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
	if (elevState == VACANT)
		return;        //电梯空闲
	if (currentFloor < goalFloor)
	    elevState=UP;  //电梯上行
	else if (currentFloor>goalFloor)
		elevState = DOWN;  //电梯下行
	else if (currentFloor == goalFloor)
		elevState = PAUSE;   //电梯停靠
}

/*
*策略1目标楼层判断
*/
void  judgeGoalFloor1_State(list **allCmd)
{
	if ((*allCmd)->next == NULL)
	{
		elevState = VACANT;
		return;
	}

	/*while ((**allCmd).floorNumber == 0)
		Sleep(1);*/
	goalFloor = (**allCmd).floorNumber;
	(*allCmd) = (*allCmd)->next;
	elevState = PAUSE;
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

/*
*时间状态记录函数
*/
void  timeRecord_State()
{
	endTime = time(NULL);

}






