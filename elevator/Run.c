/*
*包含电梯上行、下行、暂停、空闲函数
*/
#include"elevator.h"

/*
*上行函数
*/
void upper_Run()
{
	++curFloor;
	win_Out(curFloor);
}

/*
*下行函数
*/
void downer_Run()
{
	--curFloor;
	win_Out(curFloor);
}

/*
*暂停函数
*/
void pause_Run()
{
	win_Out(-curFloor);
}

/*
*空闲函数
*/
void vacant_Run()
{
	win_Out(0);
}



