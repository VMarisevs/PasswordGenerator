#ifndef FILEREADER_H
#define FILEREADER_H

void readReservedWords(char reservedWords[][16], int reservedWordsSize);

void readSavedPasswords(char savedPasswords[][16], int savedPasswordsSize);

int calculateRealWords(char savedPasswords[][16], int savedPasswordsSize);

int savePasswordchar(char passwordPointer[],char reservedWords[][16], int reservedWordsSize,char savedPasswords[][16], int savedPasswordsSize);

#endif