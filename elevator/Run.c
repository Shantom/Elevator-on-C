/*
*�����������С����С���ͣ�����к���
*/
void file_Out()
void win_Out()
void pilot_Out()
void timer_Out()

#include"elevator.h"

void upper_Run()
{
	++curFloor;
	win_Out(curFloor);
}
void downer_Run()
{
	--curFloor;
	win_Out(curFloor);
}
void pause_Run()
{
	win_Out(-curFloor);
}

void vacant_Run()
{
	win_Out(0);
}



