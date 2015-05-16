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

/*顺便服务策略的指示灯*/
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


void upper_Run();//上行函数
void downer_Run();//下行函数
void pause_Run();//暂停函数
void vacant_Run();//空闲函数

void judgeUpDown_State(int curFloor, int goalFloor);//判断当前电梯即将变换的状态
void judgeGoalFloor1_State(list *);//策略1目标楼层判断
void  judgeGoalFloor2_State(list *);//策略2目标楼层判断
void  judgeGoalFloor3_State(list *);//策略3目标楼层判断
void  judgeGoalFloor4_State(list *);//策略4目标楼层判断
void  timeRecord_State();//时间记录函数


int curFloor = 1;
int goalFloor = 1;
int elevState = VACANT;

