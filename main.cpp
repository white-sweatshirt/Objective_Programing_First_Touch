#include "DivisonOfBank.h"

void checkAllMethodsInDivision(DivisonOfBank &unit)
{
    // meant for checking if all methods work correctly and wheter there is sth to repair
    // fuction so that I wont have to wirte 2 times the same checks...
    // assumes that unit is refence to class of DivisonOfBank
    // there is no direct checking of isIt positive in this fuction only indriect by calling other
    cout << "przed zmianami: " << endl;
    unit.showAllInfo();

    unit.changeBoss("Obleix");
    unit.changeNumberOfDivsion(2);

    unit.hirePeople(1000);
    unit.hirePeople(-0.1);
    unit.hirePeople(-1);
    unit.layOff(10);
    unit.layOff(-1);

    unit.depositFunds(1090);
    unit.depositFunds(-123);

    cout << "------------------" << endl
         << "po zmianach: " << endl;
    unit.showAllInfo();
}
int main(void)
{

}