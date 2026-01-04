#include "paitients.h"
void Animal::giveVoice()
{
    cout << "generic sound " << endl;
}
void Animal::sayName()
{
    cout << "zwierzatko  " << name << endl;
}
string Animal::giveName()
{
    return this->name;
}
int Animal::beHealed()
{
    int illnessCured = 0;
    illnessCured += stomAche ? 1 : 0;
    stomAche = 1;
    return illnessCured;
}
Dog::Dog(string name)
{
    this->name = name;
    this->hasCold = 1;
    this->illPawn = 1;
    this->stomAche = 1;
    this->tailHurts = 1;
}
void Dog::sayName()
{
    cout << "pieska " << name << endl;
}
int Dog::beHealed()
{
    int illnessHealed = 0;
    if (this->hasCold)
        illnessHealed++;
    if (this->illPawn)
        illnessHealed++;
    if (this->stomAche)
        illnessHealed++;
    if (this->tailHurts)
        illnessHealed++;
    hasCold = 0;
    stomAche = 0;
    illPawn = 0;
    tailHurts = 0;
    return illnessHealed;
}
void Dog::giveVoice()
{
    cout << "Hau Hau";
}
Parrot::Parrot(string name)
{
    this->name = name;
    this->brokenWing = 1;
    this->feathersWithoutColor = 1;
    this->stomAche = 1;
}
void Parrot::sayName()
{
    cout << "papuge  " << this->name << endl;
}
void Parrot::giveVoice()
{
    cout << "krau krau" << endl;
}
int Parrot::beHealed()
{
    int illnessHealed = 0;
    if (this->brokenWing)
        illnessHealed++;
    if (this->feathersWithoutColor)
        illnessHealed++;
    if (this->stomAche)
        illnessHealed++;
    brokenWing = 0;
    feathersWithoutColor = 0;
    stomAche = 0;
    return illnessHealed;
}