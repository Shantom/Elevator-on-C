/*����
*��������ʱ��״̬�жϺ���
*Ŀ��¥���жϺ���
*ʱ���¼����
*/
//////////////////////
#include"elevator.h"

extern void judgeUpDown_State��int currentFloor��int goalFloor��;//״̬�ж�
extern void  judgeGoalFloor1_State��list *��;//����1Ŀ��¥���ж�
extern void  judgeGoalFloor2_State��list *��;//����2Ŀ��¥���ж�
extern void  judgeGoalFloor3_State��list *��;//����3Ŀ��¥���ж�
extern void  judgeGoalFloor4_State��list *��;//����4Ŀ��¥���ж�
extern void  timeRecord_State();//ʱ���¼����

/*
*״̬�ж�
*/
void
judgeUpDown_State��int currentFloor��int goalFloor��
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
void  judgeGoalFloor1_State��list **allCmd��
{
	goalFloor = (**allCmd).floorNumber;
	(*allCmd) = (*allCmd)->next;
}

/*
*����2Ŀ��¥���ж�
*/

void  judgeGoalFloor2_State����
{
	if (elevState == UP)
	{
		while (upCmd[curFloor]�� = 1&&curFloor<=MAXFLOOR)
			curFloor++;

			goalFloor = upCmd[curFloor];
	}
	else if (elevState == DOWN)
	{
		while (upCmd[curFloor]�� = 1&&curFloor>0)
			curFloor--;

		goalFloor = upCmd[curFloor];
	}
	else if (elevState == VACANT)
	{
		
	}
}
void  judgeGoalFloor3_State��list *��
void  judgeGoalFloor4_State��list *��
void  timeRecord_State()






