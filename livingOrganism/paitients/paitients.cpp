#include "paitients.h"
void Animal::giveVoice()
{
    cout<<"generic sound "<<endl;
}
void Animal::giveName()
{
    cout << "zwierzatko ma na imie : " << name<<endl;
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
void Dog::giveName()
{
    cout << "pies ma na imie: " << name<<endl;
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
    return illnessHealed;
}
void Dog::giveVoice()
{
    cout << "Hau Hau";
}
void Parrot::giveName()
{
    cout << "papuga ma na imie: " << endl;
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