// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "List.h"

int main()
{
    constexpr int AMOUNT_TO_ADD = 3;
    cout << "Hello World!\n";
    ListHead* list=new ListHead;
    string key="";
    for (int i = 0; i < AMOUNT_TO_ADD; i++)
    {
        key += "1";
        list->addToBegging(key);
    }
    key = "";
    for (int i = 0; i < AMOUNT_TO_ADD; i++)
    {
        key += "2";
        list->addToEnd(key);
    }
    list->contains("2") ? cout << "jest\n" :cout<<"niema\n";
    list->contains("4") ? cout << "jest\n" : cout << "niema\n";
    //list->remove("2");

    list->printList();
    list->clearAll();
    list->printList();
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
