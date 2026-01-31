#include "numbers.h"
bool isWhiteSpace(char c)
{
    // Check if the character is a white space
    return (c == ' ' || c == '\t' || c == '\n');
}
bool isDigit(char c)
{
    if ('0' <= c && c <= '9')
        return true;
    else
        return false;
}
bool isLetter(char c)
{
    if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
        return true;
    else
        return false;
}

bool isAlphaNumeric(char c)
{
    if (isDigit(c) || isLetter(c))
        return true;
    else
        return false;
}
bool isItNatural(char t[], int limit)
{
    // checks wheter t is natural number
    if (!*t)
        return false; // empty string is not a number
    for (int i = 0; i < limit && *(t + i); i++)
        if (!isDigit(*(t + i)))
            return false;
    return true;
}
bool isItIntiger(char t[], int limit)
{

    if (*t == '+' || *t == '-')
        t++;
    return isItNatural(t, limit);
}
bool isItReal(char t[], int limit)
{
    // assumes that t is table of chars limited in quantity by limit
    // returns wheter number is real at definition real number can be both intger
    // as well as float
    if (!*t || limit <= 0 || !t)
        return false;
    int c = 0, i = 0;

    if (*t == '+' || *t == '-')
        i++;
    bool wasTherePoint = 0, hasDigit = 0;
    for (; i < limit - 1 && *(t + i); i++) // -1 for '\0';
    {
        if (isDigit(*(t + i)))
            hasDigit = true;
        else if (*(t + i) == '.' && !wasTherePoint)
            wasTherePoint = true; // only one point is allowed
        else
            return false;
    }
    return hasDigit ? true : false;
}
double convertToDoulble(char t[], int limit)
{
    // assumes that limit is positive number
    // and that t is table of characters in with real number is stored table of characters
    int i = 0;
    bool negative = false;
    if (i < limit - 1 && (*(t + i) == '+' || *(t + i) == '-'))
    {
        if (*(t + i) == '-')
            negative = true;
        i++;
    }

    double intPart = 0.0;

    for (; i < limit - 1 && *(t + i) && isDigit(*(t + i)); i++)
        intPart = intPart * 10.0 + (*(t + i) - '0');

    double fracPart = 0.0;
    double fracDiv = 1.0;

    // fractional part (optional)
    if (i < limit - 1 && *(t + i) == '.')
    {
        i++;
        for (; i < limit - 1 && *(t + i) && isDigit(*(t + i)); i++)
        {
            fracPart = fracPart * 10.0 + (*(t + i) - '0');
            fracDiv *= 10.0;
        }
    }
    double result = intPart + (fracDiv > 1.0 ? fracPart / fracDiv : 0.0);
    if (negative)
        result *= -1.0;

    return result;
}
int convertToIntiger(char t[], int limit)
{
    // assumes that t is intiger stored on table of chars
    // limit is maximum lenght of table t
    int i = 0;
    bool negative = 0;
    if (i < limit - 1 && (*(t + i) == '+' || *(t + i) == '-'))
    {
        if (*(t + i) == '-')
            negative = true;
        i++;
    }
    int digit = 0.0;

    for (; i < limit - 1 && *(t + i) && isDigit(*(t + i)); i++)
        digit = digit * 10.0 + (*(t + i) - '0');

    return negative ? (-1) * digit : digit;
}
int getNaturalNumberFromKeyPad(char number[], int limit)
{
    do
    {
        std::cout << "podaj liczbe: ";
        std::cin >> number;
    } while (!isItNatural(number, limit));

    return convertToIntiger(number, limit);
}
double getRealNumberFromKeyPad(char number[], int limit)
{
    do
    {
        std::cout << "podaj liczbe: ";
        std::cin >> number;
    } while (!isItReal(number, limit));
    return convertToDoulble(number, limit);
}