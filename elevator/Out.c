#include "elevator.h"

void win_Out(int floor)
{
	if (floor > 0)
	{
		Sleep(1000);
		printf("��ǰ¥��Ϊ��%d��\n", floor);
	}
	else if (floor == 0)
		puts("��ǰ���ݿ���,�ȴ��û�ָ���С���\n");
	else
		printf("��ǰ����ͣ����%d��\n", -floor);
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
		{      //���ǿ���ʱ��ʼ����
			switch (elevState)
			{
				//����ֱ��״̬תΪͣ��
			case UP:
				upper_Run();
				if (curFloor == goalFloor)
					elevState = PAUSE;
				break;

				//����ֱ��״̬תΪͣ��
			case DOWN:
				downer_Run();
				if (curFloor == goalFloor)
					elevState = PAUSE;
				break;

				//ͣ��ʱ�ж�תΪ���л��Ǽ���ִ��ָ��
			case PAUSE:
				pause_Run();
				
				if (tempHead->next == NULL)//תΪ����״̬
					elevState = VACANT;

				if (tempHead->next != NULL)//�����ж�״̬��ִ��
				{
					judgeGoalFloor1_State(&tempHead);
					judgeUpDown_State(curFloor, goalFloor);
				}
				
				break;		

			default:
				break;
			}
			
			//����ʱֹͣ����,�ȴ�����
			if (elevState == VACANT)
			{
				vacant_Run();
				while (tempHead->next == NULL)
					Sleep(1);
			}
			////���ݵ���Ŀ��¥��ʱͣ��
			//if (curFloor == goalFloor)
			//{
			//	pause_Run();

			//	//�ж�û��ָ��ʱ�������״̬
			//	if (tempHead->next == NULL)
			//	{
			//		vacant_Run();
			//		//ֹͣ����,�ȴ�����
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
		{      //���ǿ���ʱ��ʼ����
			switch (elevState)
			{
				//����ֱ��״̬תΪͣ��
			case UP:
				upper_Run();
				if (curFloor == goalFloor)
					elevState = PAUSE;
				break;

				//����ֱ��״̬תΪͣ��
			case DOWN:
				downer_Run();
				if (curFloor == goalFloor)
					elevState = PAUSE;
				break;

				//ͣ��ʱ�ж�תΪ���л��Ǽ���ִ��ָ��
			case PAUSE:
				pause_Run();

				if (tempHead->next == NULL)//תΪ����״̬
					elevState = VACANT;

				if (tempHead->next != NULL)//�����ж�״̬��ִ��
				{
					judgeGoalFloor2_State(&tempHead);
					judgeUpDown_State(curFloor, goalFloor);
				}

				break;

			default:
				break;
			}

			//����ʱֹͣ����,�ȴ�����
			if (elevState == VACANT)
			{
				vacant_Run();
				while (tempHead->next == NULL)
					Sleep(1);
			}
			////���ݵ���Ŀ��¥��ʱͣ��
			//if (curFloor == goalFloor)
			//{
			//	pause_Run();

			//	//�ж�û��ָ��ʱ�������״̬
			//	if (tempHead->next == NULL)
			//	{
			//		vacant_Run();
			//		//ֹͣ����,�ȴ�����
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
