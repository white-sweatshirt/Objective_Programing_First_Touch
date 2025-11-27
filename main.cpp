#include "DivisonOfBank.h"

void checkAllMethodsInDivision(DivisonOfBank &unit)
{
    int constexpr peopleInVector = 4;
    // fuction so that I wont have to wirte 2 times the same checks...
    // assumes that unit is refence to class of DivisonOfBank
    // there is no direct checking of isIt positive in this fuction only indriect by calling other
    cout << "przed zmianami: " << endl;
    string customerName = "Janek";
    Customer *dummyCustomer = new Customer("Janek", "tuts");
    unit.showAllInfo();
    for (int i = 0; i < peopleInVector; i++)
    {
        unit.hirePerson(new Worker("Stefamn", "Batory", 1000));
        
    }
    cout << "------------------" << endl
         << "po zmianach: " << endl;
    unit.showAllInfo();
}
int main(void)
{
    DivisonOfBank *unit1 = new DivisonOfBank(1,
                                             new Boss("janek", "wesoly", 100, "peudolino"), "Warszawa", 1000.1);
    checkAllMethodsInDivision(*unit1);

    cout << endl
         << "============================" << endl;
    delete unit1;
    return 0;
}