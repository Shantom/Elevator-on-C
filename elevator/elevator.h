#include <stdio.h> 
#include <conio.h> 
#include <windows.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct CommandList{
	int floorNumber;
	struct CommandList *next;
}list;

list head = { 0 };

/*˳�������Ե�ָʾ��*/
BOOL upCmd[8];
BOOL downCmd[8];
BOOL innerCmd[9];

#define MAXCMD 200

#define BOOL int8_t
#define FALSE 0
#define TRUE 1
#define MAXFLOOR 9

#define SPACE 32
#define ESC 27

#define UP 1
#define DOWN 2
#define PAUSE 3
#define VACANT 4

DWORD WINAPI input_1(LPVOID parameter);
DWORD WINAPI output_1(LPVOID parameter);


void upper_Run();//���к���
void downer_Run();//���к���
void pause_Run();//��ͣ����
void vacant_Run();//���к���

void judgeUpDown_State(int curFloor, int goalFloor);//�жϵ�ǰ���ݼ����任��״̬
void judgeGoalFloor1_State(list *);//����1Ŀ��¥���ж�
void  judgeGoalFloor2_State(list *);//����2Ŀ��¥���ж�
void  judgeGoalFloor3_State(list *);//����3Ŀ��¥���ж�
void  judgeGoalFloor4_State(list *);//����4Ŀ��¥���ж�
void  timeRecord_State();//ʱ���¼����


int curFloor = 1;
int goalFloor = 1;
int elevState = VACANT;

