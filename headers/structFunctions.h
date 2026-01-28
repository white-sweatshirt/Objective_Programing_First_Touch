#ifndef STRUCT_FUNCTIONS_H
#define STRUCT_FUNCTIONS_H
#include <iostream>
void ignoreToNextEnter()
{
    int c = -1;
    while ((c = getchar()) != EOF && c != '\n')
        ;
}
int getStandardChoiceResult(void (*showMenu)(void), int lowerLimit, int upperLimit)
{
    char choice;
    do
    {
        showMenu();
        choice = getchar();
        ignoreToNextEnter();
    } while (choice < lowerLimit || choice > upperLimit);
    return choice;
}
#endif