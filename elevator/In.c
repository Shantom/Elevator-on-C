#include "elevator.h"
DWORD WINAPI input_1(LPVOID parameter)
{
	/*利用链表建立队列*/

	list *ptr = &head;
	while (1)
	{
		char key = getchar();
		switch (key)
		{
		case '1':case'Q':
			ptr->floorNumber = 1;
			break;
		case '2':case'W':case'S':
			ptr->floorNumber = 2;
			break;
		case '3':case'E':case'D':
			ptr->floorNumber = 3;
			break;
		case '4':case'R':case'F':
			ptr->floorNumber = 4;
			break;
		case '5':case'T':case'G':
			ptr->floorNumber = 5;
			break;
		case '6':case'Y':case'H':
			ptr->floorNumber = 6;
			break;
		case '7':case'U':case'J':
			ptr->floorNumber = 7;
			break;
		case '8':case'I':case'K':
			ptr->floorNumber = 8;
			break;
		case '9':case'L':
			ptr->floorNumber = 9;
			break;

		}
		ptr->next = malloc(sizeof(list));
		ptr = ptr->next;
	}
}
DWORD WINAPI input_2(LPVOID parameter)
{
	while (1)
	{
		char key = getchar();
		switch (key)
		{
		case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
			innerCmd[key-'0'-1] = TRUE;
			break;

		case'Q':
			upCmd[0] = TRUE;
			break;
		case'W':
			upCmd[1] = TRUE;
			break;
		case'E':
			upCmd[2] = TRUE;
			break;
		case'R':
			upCmd[3] = TRUE;
			break;
		case'T':
			upCmd[4] = TRUE;
			break;
		case'Y':
			upCmd[5] = TRUE;
			break;
		case'U':
			upCmd[6] = TRUE;
			break;
		case'I':
			upCmd[7] = TRUE;
			break;

		case'S':
			downCmd[1] = TRUE;
			break;
		case'D':
			downCmd[2] = TRUE;
			break;
		case'F':
			downCmd[3] = TRUE;
			break;
		case'G':
			downCmd[4] = TRUE;
			break;
		case'H':
			downCmd[5] = TRUE;
			break;
		case'J':
			downCmd[6] = TRUE;
			break;
		case'K':
			downCmd[7] = TRUE;
			break;
		case'L':
			downCmd[8] = TRUE;
			break;

		}
	}
}
