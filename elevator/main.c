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
*			���汣��       ����BUG
*/

#include "elevator.h"
//��ʼ������
list head = { 0 };

int curFloor=1;
int goalFloor=1;
int elevState=VACANT;
int curTime = 0;

time_t startTime, endTime;



main()
{
	system("color 3f");

	puts("��ӭʹ��1513 A�����\n�������������������س�");
	puts("��ѡ������Ҫ�ķ������\n1:�����ȷ������;2:˳��������");

	int policy = getchar();//��ȡ����
	      getchar();

	 startTime = time(NULL);

	HANDLE th1=NULL;
	HANDLE th2=NULL;
	if (policy =='1')
	{
		th1 = CreateThread(NULL, 0, input_1, NULL, 0, NULL);
		th2 = CreateThread(NULL, 0, output_1, NULL, CREATE_SUSPENDED, NULL);
		while (head.floorNumber == 0)
			;
		ResumeThread(th2);
		
     }
	else if (policy =='2')
	{
		th1 = CreateThread(NULL, 0, input_2, NULL, 0, NULL);
		th2 = CreateThread(NULL, 0, output_2, NULL, 0, NULL);
	
	}
	WaitForSingleObject(th1, INFINITE);
	WaitForSingleObject(th2, INFINITE);
	
}




