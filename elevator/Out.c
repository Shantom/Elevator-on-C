#include "elevator.h"

void win_Out(int floor)
{
	if (floor > 0)
	{
		Sleep(1000);
		printf("当前楼层为第%d层\n", floor);
	}
	else if (floor == 0)
		puts("当前电梯空闲,等待用户指令中……\n");
	else
		printf("当前电梯停靠在%d层\n", -floor);
}


void file_Out()
{

}
//void win_Out()
//void pilot_Out()
//void timer_Out()


DWORD WINAPI output_1(LPVOID parameter)
{
	list* tempHead = &head;

	while (1)
	{
		judgeGoalFloor1_State(&tempHead);
		judgeUpDown_State(curFloor, goalFloor);

		while (elevState!=VACANT)
		{      //不是空闲时开始运行
			switch (elevState)
			{
				//上行直到状态转为停靠
			case UP:
				upper_Run();
				if (curFloor == goalFloor)
					elevState = PAUSE;
				break;

				//下行直到状态转为停靠
			case DOWN:
				downer_Run();
				if (curFloor == goalFloor)
					elevState = PAUSE;
				break;

				//停靠时判断转为空闲还是继续执行指令
			case PAUSE:
				pause_Run();
				
				if (tempHead->next == NULL)//转为空闲状态
					elevState = VACANT;

				if (tempHead->next != NULL)//继续判断状态并执行
				{
					judgeGoalFloor1_State(&tempHead);
					judgeUpDown_State(curFloor, goalFloor);
				}
				
				break;		

			default:
				break;
			}
			
			//空闲时停止运行,等待命令
			if (elevState == VACANT)
			{
				vacant_Run();
				while (tempHead->next == NULL)
					Sleep(1);
			}
			////电梯到达目标楼层时停靠
			//if (curFloor == goalFloor)
			//{
			//	pause_Run();

			//	//判断没有指令时进入空闲状态
			//	if (tempHead->next == NULL)
			//	{
			//		vacant_Run();
			//		//停止运行,等待命令
			//		while (tempHead->next == NULL)
			//			Sleep(1);
			//	}
			}

		}
		/*if (tempHead == NULL)
		{
			vacant_Run();
			while (tempHead == NULL)
				Sleep(1);
		}*/
	}


DWORD WINAPI output_2(LPVOID parameter)
{
	list* tempHead = &head;

	while (1)
	{
		judgeGoalFloor2_State(&tempHead);
		judgeUpDown_State(curFloor, goalFloor);

		while (elevState != VACANT)
		{      //不是空闲时开始运行
			switch (elevState)
			{
				//上行直到状态转为停靠
			case UP:
				upper_Run();
				if (curFloor == goalFloor)
					elevState = PAUSE;
				break;

				//下行直到状态转为停靠
			case DOWN:
				downer_Run();
				if (curFloor == goalFloor)
					elevState = PAUSE;
				break;

				//停靠时判断转为空闲还是继续执行指令
			case PAUSE:
				pause_Run();

				if (tempHead->next == NULL)//转为空闲状态
					elevState = VACANT;

				if (tempHead->next != NULL)//继续判断状态并执行
				{
					judgeGoalFloor2_State(&tempHead);
					judgeUpDown_State(curFloor, goalFloor);
				}

				break;

			default:
				break;
			}

			//空闲时停止运行,等待命令
			if (elevState == VACANT)
			{
				vacant_Run();
				while (tempHead->next == NULL)
					Sleep(1);
			}
			////电梯到达目标楼层时停靠
			//if (curFloor == goalFloor)
			//{
			//	pause_Run();

			//	//判断没有指令时进入空闲状态
			//	if (tempHead->next == NULL)
			//	{
			//		vacant_Run();
			//		//停止运行,等待命令
			//		while (tempHead->next == NULL)
			//			Sleep(1);
			//	}
		}

	}
	/*if (tempHead == NULL)
	{
	vacant_Run();
	while (tempHead == NULL)
	Sleep(1);
	}*/
}
