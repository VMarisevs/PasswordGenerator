#ifndef GENERATEPW_H
#define GENERATEPW_H


char generateNumber();

char generateUppercaseLetter();

char generateLowercaseLetter();

char generateSpecialChar();

char generateChar();

void generatePW(char * passwordPointer, int maxArraySize,char reservedWords[][16], int reservedWordsSize,char savedPasswords[][16], int savedPasswordsSize);

#endif