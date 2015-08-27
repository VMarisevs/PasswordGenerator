#define _CRT_SECURE_NO_WARNINGS

#include "filereader.h"

#include <stdio.h>

#ifndef VERIFYPW_H
#include "verifypw.h"
#endif


void readReservedWords(char reservedWords[][16], int reservedWordsSize)
{
	int i,y;
	size_t n = 0;
	FILE *reservedWordsPointer = fopen("reservedwords.txt","r");

	for (i = 0; i < reservedWordsSize; i++)
	{
		for (y = 0; y < 16; y++)
		{
			reservedWords[i][y] = '\0';
		}
	}


	if (reservedWordsPointer != NULL)
	{
		y = 0;
		while ((i = fgetc(reservedWordsPointer)) != EOF)
		{
			if (((char)i) !='\n')
			{
				reservedWords[y][n++] = (char) i;
			}
			else
			{
				reservedWords[y][n++] = '\0';
				y++;
				n=0;
			}
		}
			reservedWords[y][n] = '\0'; 
	}

	fclose(reservedWordsPointer);
}

void readSavedPasswords(char savedPasswords[][16], int savedPasswordsSize)
{
	int i,y;
	size_t n = 0;
	FILE *savedPasswordsPointer = fopen("savedpasswords.txt","r");

	for (i = 0; i < savedPasswordsSize; i++)
	{
		for (y = 0; y < 16; y++)
		{
			savedPasswords[i][y] = '\0';
		}
	}


	if (savedPasswordsPointer != NULL)
	{
		y = 0;
		while ((i = fgetc(savedPasswordsPointer)) != EOF)
		{
			if (((char)i) !='\n')
			{
				savedPasswords[y][n++] = (char) i;
			}
			else
			{
				savedPasswords[y][n++] = '\0';
				y++;
				n=0;
			}
		}
			savedPasswords[y][n] = '\0'; 
	}

	fclose(savedPasswordsPointer);
}

int calculateRealWords(char savedPasswords[][16], int savedPasswordsSize)
{
	int i,result = 0;

	for (i = 0; i < savedPasswordsSize; i++)
	{
		if ((savedPasswords[i][0]) != '\0')
		{
			result++;
		}	
	}

	return result;
}

int savePasswordchar(char passwordPointer[],char reservedWords[][16], int reservedWordsSize,char savedPasswords[][16], int savedPasswordsSize)
{
	int i, result = 0 ;
	size_t n = 0;

	FILE * savedPasswordsFile;

	if (verifyPW(passwordPointer, reservedWords, reservedWordsSize,savedPasswords,savedPasswordsSize,true) == true)
	{
		savedPasswordsFile = fopen("savedpasswords.txt","w");
		if (savedPasswordsFile != NULL)
		{
		
			//if the password verified we can save it

			for (i = 0; i < (calculateRealWords(savedPasswords, savedPasswordsSize)); i++)
			{
				fprintf(savedPasswordsFile, "%s\n",savedPasswords[i]);
			}

			fprintf(savedPasswordsFile, "%s",passwordPointer);

			result = 1;	
		}
		fclose(savedPasswordsFile);

	}

	return result;
}