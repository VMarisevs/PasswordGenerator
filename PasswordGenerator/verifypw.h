#ifndef VERIFYPW_H
#define VERIFYPW_H

typedef int booleans;
#define true 1
#define false 0

int passwordLength(char varPW[]);

booleans lengthBetween9and15(char varPW[]);

booleans isThere2Numbers(char varPW[]);

booleans isThere2UppercaseLetters(char varPW[]);

booleans isThere2LowercaseLetters(char varPW[]);

booleans isThereSpecialChar(char varPW[]);

booleans isThereSpecialWords(char varPW[],char reservedWords[][16], int reservedWordsSize);

booleans thisPasswordExists(char varPW[],char savedPasswords[][16], int savedPasswordsSize);

booleans verifyPW(char varPW[],char reservedWords[][16], int reservedWordsSize,char savedPasswords[][16], int savedPasswordsSize, int withtext);

#endif