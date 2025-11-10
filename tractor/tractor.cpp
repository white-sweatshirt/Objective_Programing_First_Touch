#include "tractor.h"
Tractor::Tractor() : Velichcale()
{
}
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
void Tractor::sayDirection()
{
    cout << "obecnie jade " << this->direction<<endl;
}