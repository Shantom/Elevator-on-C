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
	if (elevState == VACANT)
		return;        //���ݿ���
	if (currentFloor < goalFloor)
	    elevState=UP;  //��������
	else if (currentFloor>goalFloor)
		elevState = DOWN;  //��������
	else if (currentFloor == goalFloor)
		elevState = PAUSE;   //����ͣ��
}

/*
*����1Ŀ��¥���ж�
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

/*
*ʱ��״̬��¼����
*/
void  timeRecord_State()
{
	endTime = time(NULL);

}






