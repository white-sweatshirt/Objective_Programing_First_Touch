#include "clients.h"
#include "employes.h"

int main(void)
{
    Customer ala(new Dog("Pimpek"), 1000, "ala", 21);
    Vet *flitz;
    flitz = new Vet("Fryderyk", 34, "masters");
    ala.askForHelpWithAnimal(flitz);
}