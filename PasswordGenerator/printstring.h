#ifndef PRINTSTRING_H
#define PRINTSTRING_H

void setCursorPosition(int X, int Y);

void printColouredText(char varText[],int color);

void printCharSet(int firstChar, int lastChar);

void printframe(int xLeftTop, int yLeftTop, int xRightBottom, int yRightBottom, int color);

#endif