#ifndef NUMBERS_H
#define NUMBERS_H
#include <iostream>
// libary wrriten for other subject
bool isDigit(char c);
bool isAlphaNumeric(char c);
bool isLetter(char c);

bool isItNatural(char t[], int limit);
bool isItIntiger(char t[], int limit);
bool isItReal(char t[], int limit);
double convertToDoulble(char t[], int limit);
int convertToIntiger(char t[], int limit);
int getNaturalNumberFromKeyPad(char number[], int limit);
double getRealNumberFromKeyPad(char number[], int limit);
#define MAX_TEXT 100
#endif