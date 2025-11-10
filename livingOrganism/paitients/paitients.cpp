#include "paitients.h"
void Animal::giveName()
{
    cout << "zwierzatko ma na imie : " << name;
}
int Animal::beHealed()
{
    int illnessCured = 0;
    illnessCured += stomAche ? 1 : 0;
    stomAche = 1;
    return illnessCured;
}
void Dog::giveName()
{
    cout << "pies ma na imie: " << name;
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
    cout<<"Wof Wof";
}