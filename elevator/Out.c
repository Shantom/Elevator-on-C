#include "elevator.h"

void win_Out(int floor)
{
	if (floor > 0)
	{
		Sleep(1000);
		printf("当前楼层为第%d层\n", floor);
	}
	else if (floor == 0)
		puts("当前电梯空闲");
	else
		printf("当前电梯停靠在%d层", -floor);
}
//void pilot_Out()
//{
//
//}