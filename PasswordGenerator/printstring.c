#include "printstring.h"

#include <stdio.h>
#include <conio.h>
#include <windows.h>


void setCursorPosition(int X, int Y)
{	
// MAX X = 79
// MAX Y = 24
    COORD pos = {X, Y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void printColouredText(char varText[],int color)
{
	HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
	switch(color)
	{
		case 1:
			// selected menu item color
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			break;
		case 2:
			// not selected menu item color
			SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			break;
		case 3:
			// didn't pass verification
			SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
			break;
		case 4:
			// pass verification
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			break;
		case 5:
			// yellow color
			SetConsoleTextAttribute(h, FOREGROUND_GREEN  | FOREGROUND_INTENSITY |FOREGROUND_RED );
			break;
		case 6:
			// 
			SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY |FOREGROUND_RED );
			break;
	}
	printf(varText);
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);

}

void printCharSet(int firstChar, int lastChar)
{
	char varChar;
	int i;
	for (i = firstChar; i <= lastChar; i++)
	{
		varChar = (char)i;
		printf("%c ",varChar);
	}
}

void printframe(int xLeftTop, int yLeftTop, int xRightBottom, int yRightBottom, int color)
{
	char printChar[] = {"x"};
	int x,y;
	//drawing top line
	
		//printChar[0] = (char)(182);
		
		for (y = yLeftTop; y <= yRightBottom; y++)
		{
			for (x = xLeftTop; x <= xRightBottom; x++)
			{
				setCursorPosition(x,y);
				
				if ((x == xLeftTop) || (y == yLeftTop)  ||  (x == xRightBottom) || (y == yRightBottom))
				{
					printColouredText(printChar,color);
				}
			}
		}
		
}