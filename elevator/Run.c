/*
*�����������С����С���ͣ�����к���
*/
#include"elevator.h"

/*
*���к���
*/
void upper_Run()
{
	Sleep(1000);
	++curFloor;
	win_Out(curFloor);
}

/*
*���к���
*/
void downer_Run()
{
	Sleep(1000);
	--curFloor;
	win_Out(curFloor);
}

/*
*��ͣ����
*/
void pause_Run()
{
	
	win_Out(-curFloor);
	Sleep(500);

}

/*
*���к���
*/
void vacant_Run()
{

	win_Out(0);

}



