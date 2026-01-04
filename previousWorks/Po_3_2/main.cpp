#include "clients.h"
#include "employes.h"
#include <vector>

// plans: I am thinking about large General Class of Making a visit with vet i.e abstract way of cabinet
void sperateConversions(void)
{
    int constexpr numberOfSeperators = 20;
    for (int i = 0; i < numberOfSeperators; i++)
        cout << "=";
    cout << endl;
}
void addPlaceHoleders(vector<Customer *> &waitingLine)
{
    string customerName = "Andrzej";
    string dogName = "Reksio";
    string parrotName = "Jack";
    int constexpr numberOfCustomersToAdd = 3;
    int constexpr numberOfAnimalsToAdd = 3;
    for (int i = 0; i < numberOfCustomersToAdd; i++)
    {
        Customer *customerToAdd = new Customer(new Parrot(parrotName), 1000, customerName, 23);
        dogName = "Pimpek";
        for (int i = 0; i < numberOfAnimalsToAdd; i++)
        {
            customerToAdd->addAnimal(new Dog(dogName));
            dogName += "Maly";
        }
        waitingLine.push_back(customerToAdd);
    }
}
void serveCustomers(vector<Customer *> &waitingLine, Vet *vet)
{
    static int visitNumber = 0;

    for (auto customerCurrentlyServed : waitingLine)
    {
        cout << "wizyta w klinice nr : " << visitNumber++ << endl;
        customerCurrentlyServed->askForHelpWithAnimals(vet);
        sperateConversions();
    }
}

int main(void)
{
    vector<Customer *> waitingLine;
    Vet *flitz;
    waitingLine.push_back(new Customer(new Dog("Reksio"), 2000, "alex", 19));
    waitingLine.push_back(new Customer(new Parrot("Jack Sparrow"), 90000, "Jhony Deep", 62));

    addPlaceHoleders(waitingLine);

    waitingLine[2]->removeAnimal("Pimpek");
    waitingLine[3]->removeAnimal("PimpekMaly");
    auto start = waitingLine.begin();

    flitz = new Vet("Fryderyk", 34, "doctor");
    Vet *filp = new Vet("Filip", 23, "masters");
    flitz->introduceYourself();

    serveCustomers(waitingLine, flitz);
    serveCustomers(waitingLine, filp);

    flitz->sayHowMuchHaveYouMade();
    filp->sayHowMuchHaveYouMade();
    for (auto pToDelete : waitingLine)
        pToDelete->~Customer();

    waitingLine.clear();
    delete flitz;
    delete filp;
}