#define _CRT_SECURE_NO_WARNINGS

#include "menu.h"

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


#ifndef PRINTSTRING_H
#include "printstring.h"
#endif

#ifndef VERIFYPW_H
#include "verifypw.h"
#endif

#ifndef GENERATEPW_H
#include "generatepw.h"
#endif

#ifndef FILEREADER_H
#include "filereader.h"
#endif


#define LASTMENUITEM 4 // it's always should be exit!
#define MAXPASSWORDSIZE 255 //to let user insert 255 chars
#define MAXRESERVEDWORDS 1000 // maximum words that is used for reserved words array and saved passwords (pw that already were generated)

// keys
#define ENTER 13
#define ESC 27
#define UPARROW 72
#define DOWNARROW 80


void printMenuItems(int selectedItem, char * passwordPointer,char reservedWords[][16],char savedPasswords[][16])
{
	// array of colors for menu
	int itemsSelection[LASTMENUITEM+1] = {2,2,2,2,2};

	// setting the selected item
	itemsSelection[selectedItem] = 1;
	system("cls");

		printPasswordIfExists(passwordPointer, MAXPASSWORDSIZE, reservedWords, MAXRESERVEDWORDS, savedPasswords,MAXRESERVEDWORDS);
	// printing whole menu
		setCursorPosition(40,10);	
		printColouredText("Verify Password",itemsSelection[0]);

		setCursorPosition(40,11);
		printColouredText("Generate Password", itemsSelection[1]);

		setCursorPosition(40,12);
		printColouredText("Save Password",itemsSelection[2]);

		setCursorPosition(40,13);
		printColouredText("About",itemsSelection[3]);

		setCursorPosition(40,14);
		printColouredText("Exit",itemsSelection[4]);

}

int selectMenu(char * passwordPointer,char reservedWords[][16],char savedPasswords[][16])
{
	int keyPressed;
	int selectedMenuItem = 0;

	printMenuItems(selectedMenuItem, passwordPointer, reservedWords, savedPasswords);

	// menu view
	do
	{
		keyPressed = _getch();

		switch (keyPressed)
		{
		case UPARROW:
			selectedMenuItem--;
			if(selectedMenuItem<0)
			{
				selectedMenuItem = LASTMENUITEM;
			}

			break;


		case DOWNARROW:
			selectedMenuItem++;
			if(selectedMenuItem>LASTMENUITEM)
			{
				selectedMenuItem = 0;
			}
			break;
		}
		printMenuItems(selectedMenuItem, passwordPointer, reservedWords, savedPasswords);
	}
	while (keyPressed!=ENTER);
	
	
return selectedMenuItem;
}

void printPasswordIfExists(char * passwordPointer, int maxArraySize,char reservedWords[][16], int reservedWordsSize,char savedPasswords[][16], int savedPasswordsSize)
{
	if (passwordPointer[0] != '\0')
	{
		printframe(28, 2, 49,6, 2);
		
		
		if (verifyPW(passwordPointer, reservedWords, reservedWordsSize,savedPasswords,savedPasswordsSize,false) == true)
		{
			setCursorPosition(31,4);
			printColouredText(passwordPointer, 4);
		}
		else
		{
			setCursorPosition(31,4);
			printColouredText(passwordPointer, 3);
		}
	}
}

void printAbout()
{
	printframe(8, 3, 72, 18, 4);
	printframe(9, 3, 71, 18, 2);

	setCursorPosition(14,5);
	printColouredText("This programm is made to generate password.",6);
	setCursorPosition(14,6);
	printColouredText("Maximum of reserved words and existing passwords are",6);
	setCursorPosition(12,7);
	printColouredText("defined in  MAXRESERVEDWORDS.",6);
	setCursorPosition(14,8);
	printColouredText("Special Character list: !#$&()*+,-.:;<=>?@[]^_`{}~",6);

	setCursorPosition(37,12);
	printColouredText("Prepared by: Vladislavs Marisevs",5);
	setCursorPosition(32,13);
	printColouredText("For the attention of: Damien Costello",5);
	setCursorPosition(35,14);
	printColouredText("Class: Software Development year 2",5);
	setCursorPosition(25,15);
	printColouredText("College: Galway Mayo Institute of Technology",5);
	setCursorPosition(36,16);
	printColouredText("Submission Date: 6th January 2014",5);

}

void menu()
{	
	int selectedMenuItem;
	char varPassword[MAXPASSWORDSIZE] = {""};
	char varReservedWords[MAXRESERVEDWORDS][16];
	char varSavedPasswords[MAXRESERVEDWORDS][16];

	do
	{
		selectedMenuItem = selectMenu(varPassword, varReservedWords, varSavedPasswords);
		

		switch(selectedMenuItem)
		{
			// 1 menu item, Verify password 
			case 0:
				system("cls");

				printframe(28, 2, 49,6, 2);
				setCursorPosition(31,4);
				

				scanf("%s",varPassword);
				//fgets(varPassword, MAXPASSWORDSIZE, stdin);
				fflush(stdin);

				readReservedWords(varReservedWords, MAXRESERVEDWORDS);
				readSavedPasswords(varSavedPasswords,MAXRESERVEDWORDS);
				verifyPW(varPassword, varReservedWords, MAXRESERVEDWORDS,varSavedPasswords,MAXRESERVEDWORDS,true);


				setCursorPosition(20,24);
				system("pause");
				break;

			// 2 menu item, Generate password
			case 1:
				system("cls");

				//setCursorPosition(20,17);
				readReservedWords(varReservedWords, MAXRESERVEDWORDS);
				readSavedPasswords(varSavedPasswords,MAXRESERVEDWORDS);
				generatePW(varPassword, MAXPASSWORDSIZE, varReservedWords, MAXRESERVEDWORDS, varSavedPasswords,MAXRESERVEDWORDS);

				
				printPasswordIfExists(varPassword, MAXPASSWORDSIZE, varReservedWords, MAXRESERVEDWORDS, varSavedPasswords,MAXRESERVEDWORDS);
								
				setCursorPosition(20,24);
				system("pause");
				break;

			// 3 menu item,  Save password
			case 2:
				system("cls");

				readReservedWords(varReservedWords, MAXRESERVEDWORDS);
				readSavedPasswords(varSavedPasswords,MAXRESERVEDWORDS);

				printPasswordIfExists(varPassword, MAXPASSWORDSIZE, varReservedWords, MAXRESERVEDWORDS, varSavedPasswords,MAXRESERVEDWORDS);

				if ((savePasswordchar(varPassword,varReservedWords,MAXRESERVEDWORDS,varSavedPasswords,MAXRESERVEDWORDS)) == 1)
				{
					setCursorPosition(30,21);
					printColouredText("The password is saved successfully.",4);
				}
				else
				{
					setCursorPosition(30,21);
					printColouredText("We can't save the password.",3);
				}

				setCursorPosition(20,24);
				system("pause");
				break;

			// 4 menu item, About
			case 3:
				system("cls");

				printAbout();

				setCursorPosition(20,24);
				system("pause");
				break;
		}
	}
	while (selectedMenuItem != LASTMENUITEM);

}

