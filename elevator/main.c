/*
*					_ooOoo_
*				   o8888888o
*				   88" . "88
*				   (| -_- |)
*				   O\  =  /O
*				____/`---'\____
*			  .'  \\|     |//  `.
*			 /  \\|||  :  |||//  \
*			/  _||||| -:- |||||-  \
*			|   | \\\  -  /// |   |
*			| \_|  ''\---/''  |_/ |
*			\  .-\__  `-'  ___/-. /
*		  ___`. .'  /--.--\  `. .'___
*      ."" '<  `.___\_<|>_/___.'  >' "".
* 	  | | :  `- \`.;`\ _ /`;.`/ - ' : | |
*	  \  \ `-.   \_ __\ /__ _/   .-' /  /
*======`-.____`-.___\_____/___.-'____.-'======
*					`=---='
*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
*			佛祖保佑       永无BUG
*/

#include "elevator.h"

main()
{
	system("color 3f");

	puts("欢迎使用1513 A类电梯\n操作方法：输入命令后回车");
	puts("请选择您需要的服务策略\n1:先来先服务策略;2:顺便服务策略");

	int policy = getchar();

	HANDLE th1;
	HANDLE th2;
	if (policy == '1')
	{
		th1 = CreateThread(NULL, 0, input_1, NULL, 0, NULL);
		th2 = CreateThread(NULL, 0, output_1, NULL, CREATE_SUSPENDED, NULL);
		while (head.floorNumber == 0)
			;
		ResumeThread(th2);
}
	else if (policy == '2')
	{
		th1 = CreateThread(NULL, 0, input_1, NULL, 0, NULL);
		th2 = CreateThread(NULL, 0, output_1, NULL, 0, NULL);
	}
	WaitForSingleObject(th1,INFINITE);
	//WaitForSingleObject(th2,INFINITE);

}


int innerReq(list *allCmd, int goal)
{
	(*allCmd).floorNumber = goal;
	(*allCmd).up_Down = 0;
	return TRUE;
}
DWORD WINAPI output_1(LPVOID parameter)
{
	list *pre = NULL;
	list *current = root;

	while (1)
	{
		if (current != NULL)
		{
			int i;

			if (cur_floor<current->floorNumber)
			{
				for (i = cur_floor; i < current->floorNumber; i++)
				{
					printf("当前楼层%d,正在向上运行\n", i);
					Sleep(500);
				}
				printf("到达目的楼层%d\n\n", i);
				Sleep(2000);
			}

			else if (cur_floor>current->floorNumber)
			{
				for (i = cur_floor; i > current->floorNumber; i--)
				{
					printf("当前楼层%d,正在向下运行\n", i);
					Sleep(500);
				}
				printf("到达目的楼层%d\n\n", i);
				Sleep(2000);
			}
			cur_floor = i;

			pre = current;
		}
		while (current->next == NULL)
			;
		current = current->next;
		free(pre);

	}
}
