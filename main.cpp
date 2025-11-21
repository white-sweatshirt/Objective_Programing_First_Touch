// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "List.h"
void testList(ListHead *list)
{
    // tests lists using all the function combained for full range of list
    // if any fuction wont work it means that some element has failed
    // returns fully printed list into stdout
    list->printList();
    list->contains("111") ? cout << "jest 2\n" : cout << "nie ma 2\n";
    list->contains("4") ? cout << "jest 4\n" : cout << "nie ma 4\n";
    list->remove("2");

    if (!list)
        return;
    for (int i = 0; i < list->giveSize(); i++)
    {
        ListElement *element = list->getIndex(i);
        if (element)
        {
            element = list->getElement(element->getKey());
            cout << element->getKey() << " ";
        }
    }
    puts("");
}
void printSeparator()
{
    constexpr int numberOfSeparators = 20;
    for (int i = 0; i < numberOfSeparators; i++)
        cout << "=";
    puts("");
}
int main()
{

    ListHead *list = new ListHead;
    string key = "";
    testList(list);
    printSeparator();
    constexpr int elementsToAdd = 3;
    for (int i = 0; i < elementsToAdd; i++)
    {
        key += "1";
        list->addToBegging(key);
    }
    key = "";
    for (int i = 0; i < elementsToAdd; i++)
    {
        key += "2";
        list->addToEnd(key);
    }
    testList(list);
    // checking of function of get index , get key and give size
    list->clearAll();
    list->printList();
    delete list;
}
