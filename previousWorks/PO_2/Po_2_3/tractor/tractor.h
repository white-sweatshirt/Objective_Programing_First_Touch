#ifndef TRACTOR_H
#define TRACTOR_H
#include "car.h"
class Tractor : public Velichcale
{
public:
    Tractor();
    void drive();
    void stopYourself();
    void changeDirection(string direction);
    void sayDirection();
};
#endif