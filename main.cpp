#include "DivisonOfBank.h"

void checkAllMethodsInDivision(DivisonOfBank &unit)
{
    int constexpr peopleInVector = 4;
    // fuction so that I wont have to wirte 2 times the same checks...
    // assumes that unit is refence to class of DivisonOfBank
    // there is no direct checking of isIt positive in this fuction only indriect by calling other
    cout << "przed zmianami: " << endl;
    Customer *customers[peopleInVector];
    string exampleName = "Jan";
    string exampleLastName = "Duda";
    for (int i = 0; i < peopleInVector; i++)
    {
        customers[i] = new Customer(exampleName, exampleLastName, i + 100);
        exampleLastName += "1";
        exampleName += "1";
    }
    string nameWorker = "Stefamn";
    string lastNameWorker = "Batory";
    unit.showAllInfo();
    for (int i = 0; i < peopleInVector; i++)
    {
        unit.hirePerson(new Worker(nameWorker, lastNameWorker, 1000));
        unit.depositFunds(customers[i]->giveMoneyFromHand(), customers[i]->giveId());
        nameWorker+="2";
        lastNameWorker+="2";
    }

    cout << "------------------" << endl
         << "po zmianach: " << endl;
    unit.showAllInfo();
    for (int i = 0; i < peopleInVector; i++)
        delete customers[i];
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