/*
*�����������С����С���ͣ�����к���
*/
#include"elevator.h"

/*
*���к���
*/
void upper_Run()
{
	++curFloor;
	win_Out(curFloor);
}

/*
*���к���
*/
void downer_Run()
{
	--curFloor;
	win_Out(curFloor);
}

/*
*��ͣ����
*/
void pause_Run()
{
	win_Out(-curFloor);
}

/*
*���к���
*/
void vacant_Run()
{
	win_Out(0);
}



