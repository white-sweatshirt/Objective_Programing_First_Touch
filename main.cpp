#include "clients.h"
#include "employes.h"
void sperateConversions(void)
{
    int constexpr numberOfSeperators = 20;
    for (int i = 0; i < numberOfSeperators; i++)
        cout << "=";
    cout << endl;
}
int main(void)
{
    Customer ala(new Dog("Pimpek"), 1000, "Ala", 21);
    Vet *flitz;
    Customer *basa = new Customer(new Parrot("Jack Sparoow"), 100, "Basa", 30);
    flitz = new Vet("Fryderyk", 34, "masters");
    ala.askForHelpWithAnimal(flitz);
    sperateConversions();

    basa->askForHelpWithAnimal(flitz);
    sperateConversions();

    ala.askForHelpWithAnimal(flitz);
    sperateConversions();

    flitz->sayHowMuchHaveYouMade();
}