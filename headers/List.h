#pragma once
#include <iostream>
using namespace std;
class ListHead;
class ListElement
{
private:
    friend ListHead;
    ListElement* next;
    string key;
    ListElement* prev;
public:
    ListElement(string key);
    string getKey();
};
class ListHead
{
private:
    ListElement* first;
    int size;
public:
    void addToBegging(string key);
    void addToEnd(string key);
    bool contains(string key);
    ListElement* getIndex(int idx);
    void remove(string key);
    void clearAll();
    void printList();
    ListHead();
    ~ListHead();
};

