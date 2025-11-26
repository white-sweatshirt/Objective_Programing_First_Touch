#include "DivisonOfBank.h"

void checkAllMethodsInDivision(DivisonOfBank &unit)
{
    // meant for checking if all methods work correctly and wheter there is sth to repair
    // fuction so that I wont have to wirte 2 times the same checks...
    // assumes that unit is refence to class of DivisonOfBank
    // there is no direct checking of isIt positive in this fuction only indriect by calling other
    cout << "przed zmianami: " << endl;
    unit.showAllInfo();


    unit.depositFunds(1090);
    unit.depositFunds(-123);

    cout << "------------------" << endl
         << "po zmianach: " << endl;
    unit.showAllInfo();
}
int main(void)
{
    DivisonOfBank *unit1 = new DivisonOfBank(1, new Boss("janek", "wesoly", 100, "peudolino"), "Warszawa", 1000.1, 10, 20.1);
    checkAllMethodsInDivision(*unit1);
    cout << endl
         << "============================" << endl;
    delete unit1;
    return 0;
}