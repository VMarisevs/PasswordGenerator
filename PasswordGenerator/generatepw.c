#include "generatepw.h"

#include <stdlib.h>
#include <time.h>

#ifndef VERIFYPW_H
#include "verifypw.h"
#endif

typedef int booleans;
#define true 1
#define false 0


char generateNumber()
{
	int generatedValue;
	char result;

	generatedValue = (rand()%(9+1))+48;
	result=(char)generatedValue;

	return result;
}

char generateUppercaseLetter()
{
	int generatedValue;
	char result;


	generatedValue = (rand()%(25+1))+65; // generates between 25 char and starting from 65 ascii table
	result=(char)generatedValue;

	return result;
}

char generateLowercaseLetter()
{
	int generatedValue;
	char result;


	generatedValue = (rand()%(25+1))+97; // generates between 25 char and starting from 97 ascii table
	result=(char)generatedValue;

	return result;
}

char generateSpecialChar()
{
	int generatedValue;
	char result;
	char SpecialCharList[] = {"!#$&()*+,-.:;<=>?@[]^_`{}~"};

	generatedValue = rand()%sizeof(SpecialCharList);

	result = SpecialCharList[generatedValue];
	return result;
}

char generateChar()
{
	
	int range;
	char result;

	
	range = (rand()%4)+1;
	
	
	switch(range)
		{
			case 1:
				result = generateNumber();
				break;
			case 2:
				result = generateUppercaseLetter();
				break;
			case 3:
				result = generateLowercaseLetter();
				break;
			case 4:
				result = generateSpecialChar();
				break;
		}

	return result;
}

void generatePW(char * passwordPointer, int maxArraySize,char reservedWords[][16], int reservedWordsSize,char savedPasswords[][16], int savedPasswordsSize)
{
	
	
	int generatedSize, i;

	srand((unsigned int)time(NULL));

	// password will be generated between 9 and 15
	generatedSize = rand()%(6+1)+9;	

	do
	{
		for ( i = 0;i < maxArraySize; i++ )
		{
			passwordPointer[i] = '\0';
		}

		for (i = 0; i < generatedSize; i++)
		{					
			passwordPointer[i] = generateChar();
		}
		system("cls");
	} while (verifyPW(passwordPointer, reservedWords, reservedWordsSize,savedPasswords,savedPasswordsSize,true) != true);

}