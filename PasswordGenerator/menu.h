#ifndef MENU_H
#define MENU_H

void printMenuItems(int selectedItem, char * passwordPointer,char reservedWords[][16],char savedPasswords[][16]);

int selectMenu(char * passwordPointer,char reservedWords[][16],char savedPasswords[][16]);

void printPasswordIfExists(char * passwordPointer, int maxArraySize,char reservedWords[][16], int reservedWordsSize,char savedPasswords[][16], int savedPasswordsSize);

void printAbout();

void menu();

#endif