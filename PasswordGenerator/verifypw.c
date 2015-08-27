#include "verifypw.h"

#include <stdio.h>
#include <string.h>

#ifndef PRINTSTRING_H
#include "printstring.h"
#endif

typedef int booleans;
#define true 1
#define false 0

#define VERIFICATIONSUM 7


int passwordLength(char varPW[])
{
	// checking if there are more than 15 characters
	// we will check only first 15

	int length =0;

	if (strlen(varPW)>15)
	{
		length = 15;
	}
	else 
	{
		length = strlen(varPW);
	}
	
	return length;
}

booleans lengthBetween9and15(char varPW[])
{
	booleans result = false;

	if ((strlen(varPW)>=9) && (strlen(varPW)<=15))
	{
		result = true;
	}
	return result;
}

booleans isThere2Numbers(char varPW[])
{
	booleans result = false;

	int  i = 0, 
		 iCounter = 0, 
		 length = passwordLength(varPW);
	

	for (i = 0; i < length; i++ )
	{
		// running through the string (up to 15 characters)
		// looking for numbers
		if (((int)varPW[i]>=48) && ((int)varPW[i]<=57))
		{
			iCounter++;
		}
	}

	if (iCounter >= 2)
	{
		result = true;
	}

	return result;
}

booleans isThere2UppercaseLetters(char varPW[])
{
	booleans result = false;
	
	int  i = 0, 
		 iCounter = 0, 
		 length = passwordLength(varPW);
	

	for (i = 0; i < length; i++ )
	{
		// running through the string (up to 15 characters)
		// looking for uppercase letters
		if (((int)varPW[i]>=65) && ((int)varPW[i]<=90))
		{
			iCounter++;
		}
	}

	if (iCounter >= 2)
	{
		result = true;
	}
	return result;
}

booleans isThere2LowercaseLetters(char varPW[])
{
	booleans result = false;
	
	int  i = 0, 
		 iCounter = 0, 
		 length = passwordLength(varPW);
	

	for (i = 0; i < length; i++ )
	{
		// running through the string (up to 15 characters)
		// looking for lowercase letters
		if (((int)varPW[i]>=97) && ((int)varPW[i]<=122))
		{
			iCounter++;
		}
	}

	if (iCounter >= 2)
	{
		result = true;
	}
	return result;
}

booleans isThereSpecialChar(char varPW[])
{
	booleans result = false;
	
	int  i = 0, 
		 iCounter = 0, 
		 length = passwordLength(varPW);
	

	for (i = 0; i < length; i++ )
	{
		// running through the string (up to 15 characters)
		// looking for all printable special characters excluding "\"
		//
		if (
			((int)varPW[i]>=33) && ((int)varPW[i]<=47)
			||
			((int)varPW[i]>=58) && ((int)varPW[i]<=64)
			||
			((int)varPW[i]>=91) && ((int)varPW[i]<92)
			||
			((int)varPW[i]>92) && ((int)varPW[i]<=96)
			||
			((int)varPW[i]>=123) && ((int)varPW[i]<=126)
		   )
		{
			iCounter++;
		}
	}

	if (iCounter >= 1)
	{
		result = true;
	}
	return result;
}

booleans isThereSpecialWords(char varPW[],char reservedWords[][16], int reservedWordsSize)
{
	booleans result = false;
	
	int i, iCounter = 0;

	for (i = 0; i < reservedWordsSize; i++)
	{
		if (reservedWords[i][0]!='\0')
		{
			if (strstr(varPW,reservedWords[i]) != 0 )
			{
				iCounter++;
			}
		}
	}

	if ((iCounter == 0) || (reservedWords[0][0] == '\0'))
	{
		result = true;
	}
	return result;
}

booleans thisPasswordExists(char varPW[],char savedPasswords[][16], int savedPasswordsSize)
{
	booleans result = false;
	
	int i = 0, iCounter = 0;



	for (i = 0; i < savedPasswordsSize; i++)
	{
		if (savedPasswords[i][0] != '\0')
		{
			if (strncmp(varPW,savedPasswords[i],16) == 0)
			{
				iCounter++;
			}
		}
	}


	if ((iCounter == 0) || (savedPasswords[0][0] == '\0'))
	{
		result = true;
	}
	return result;
}

booleans verifyPW(char varPW[],char reservedWords[][16], int reservedWordsSize,char savedPasswords[][16], int savedPasswordsSize, int withtext)
{
	int verified = 0; // it will add for each passed verification
	booleans verification = false;


	if (withtext == 1)
	{
		if (lengthBetween9and15(varPW) == true)
		{
			setCursorPosition(30,12);
			printColouredText("Length between 9 and 15.",4);
			verified++;
		}
		else
		{
			setCursorPosition(30,12);
			printColouredText("Length between 9 and 15.",3);
		}



		if (isThere2Numbers(varPW) == true)
		{
			setCursorPosition(30,13);
			printColouredText("2 or more numbers",4);
			verified++;
		}
		else
		{
			setCursorPosition(30,13);
			printColouredText("2 or more numbers",3);
		}



		if (isThere2UppercaseLetters(varPW) == true)
		{
			setCursorPosition(30,14);
			printColouredText("2 or more uppercase letters",4);
			verified++;
		}
		else
		{
			setCursorPosition(30,14);
			printColouredText("2 or more uppercase letters",3);
		}



		if (isThere2LowercaseLetters(varPW) == true)
		{
			setCursorPosition(30,15);
			printColouredText("2 or more lowercase letters",4);
			verified++;
		}
		else
		{
			setCursorPosition(30,15);
			printColouredText("2 or more lowercase letters",3);
		}



		if (isThereSpecialChar(varPW) == true)
		{
			setCursorPosition(30,16);
			printColouredText("At least 1 special character",4);
			verified++;
		}
		else
		{
			setCursorPosition(30,16);
			printColouredText("At least 1 special character",3);
		}
		


		if (isThereSpecialWords(varPW,reservedWords, reservedWordsSize) == true)
		{
			setCursorPosition(30,17);
			printColouredText("Password doesn't contain reserved word",4);
			verified++;
		}
		else
		{
			setCursorPosition(30,17);
			printColouredText("Password contains reserved word",3);
		}

		if (thisPasswordExists(varPW, savedPasswords, savedPasswordsSize) == true)
		{
			setCursorPosition(30,18);
			printColouredText("Password doesn't exists",4);
			verified++;
		}
		else
		{
			setCursorPosition(30,18);
			printColouredText("Password already exists",3);
		}



		if (verified == VERIFICATIONSUM)
		{
			// verification passed
			setCursorPosition(30,20);
			printColouredText("This password passed the verification.",4);
			verification = true;
		}
		else
		{
			// didn't pass the verification
			setCursorPosition(30,20);
			printColouredText("This password didn't pass the verification.",3);
			verification = false;
		
		}
	} 
	else
	{
		if (lengthBetween9and15(varPW) == true)
		{
			verified++;
		}


		if (isThere2Numbers(varPW) == true)
		{
			verified++;
		}


		if (isThere2UppercaseLetters(varPW) == true)
		{
			verified++;
		}


		if (isThere2LowercaseLetters(varPW) == true)
		{
			verified++;
		}
		

		if (isThereSpecialChar(varPW) == true)
		{
			verified++;
		}
	

		if (isThereSpecialWords(varPW,reservedWords, reservedWordsSize) == true)
		{
			verified++;
		}

		if (thisPasswordExists(varPW, savedPasswords, savedPasswordsSize) == true)
		{
			verified++;
		}


		if (verified == VERIFICATIONSUM)
		{
			// verification passed
			verification = true;
		}
		else
		{
			// didn't pass the verification
			verification = false;
		
		}
	}

	return verification;
}

