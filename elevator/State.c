/*����
*��������ʱ��״̬�жϺ���
*Ŀ��¥���жϺ���
*ʱ���¼����
*/
//////////////////////
#include"elevator.h"


/*
*״̬�ж�
*/
void
judgeUpDown_State(int currentFloor,int goalFloor)
{
	if (currentFloor < goalFloor)
	    upper_Run();//��������
	else if (currentFloor>goalFloor)
		downer_Run();//��������
	else if (currentFloor == goalFloor)
		pause_Run();//����ֹͣ

}

/*
*����1Ŀ��¥���ж�
*/
void  judgeGoalFloor1_State(list **allCmd)
{
	while ((*allCmd)->next == NULL)
		Sleep(1);//��û����һ��ָ��

	goalFloor = (**allCmd).floorNumber;
	(*allCmd) = (*allCmd)->next;
}

/*
*����2Ŀ��¥���ж�
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






