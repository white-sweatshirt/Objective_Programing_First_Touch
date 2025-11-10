#include "tractor.h"
void Tractor::changeDirection(string direction)
{
    this->direction = "powoli w " + direction;
}
void Tractor::drive()
{
    this->direction = "powoli na przod";
}
void Tractor::stopYourself()
{
    this->direction = "stop";
}