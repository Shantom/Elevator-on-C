#include "elevator.h"
void win_Out(int floor)
{
	if (floor > 0)
		printf("��ǰ¥��Ϊ��%d��\n", floor);
	else if (floor == 0)
		puts("��ǰ���ݿ���");
	else
		printf("��ǰ����ͣ����%d��", -floor);
}
void pilot_Out()
{

}