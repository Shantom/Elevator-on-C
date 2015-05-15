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


DWORD WINAPI input_1(LPVOID parameter);
DWORD WINAPI output_1(LPVOID parameter);
void upper_Run();
void downer_Run();
void pause_Run();
void judgeUpDown_State(int currentFloor,int goalFloor);
void judgeGoalFloor1_State(list *);


int curFloor = 1;
