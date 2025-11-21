// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "List.h"

int main()
{
    constexpr int AMOUNT_TO_ADD = 3;
    cout << "Hello World!\n";
    ListHead *list = new ListHead;
    string key = "";
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
    list->contains("2") ? cout << "jest\n" : cout << "niema\n";
    list->contains("4") ? cout << "jest\n" : cout << "niema\n";
    list->remove("2");

    list->printList();
    list->clearAll();
    list->printList();
}
