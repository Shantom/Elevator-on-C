#include "elevator.h"

void win_Out(int floor)
{
	if (floor > 0)
	{
		Sleep(1000);
		printf("��ǰ¥��Ϊ��%d��\n", floor);
	}
	else if (floor == 0)
		puts("��ǰ���ݿ���");
	else
		printf("��ǰ����ͣ����%d��", -floor);
}
//void pilot_Out()
//{
//
//}