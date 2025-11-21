#pragma once
#include <iostream>
using namespace std;
class ListHead;
class ListElement
{
private:
    friend ListHead;
    ListElement *next;
    string key;
    ListElement *prev;

public:
    ListElement(string key);
    string getKey();
};
class ListHead
{
private:
    ListElement *first;
    int size;

public:
    // give size is for janks
    int giveSize();
    void addToBegging(string key);
    void addToEnd(string key);
    bool contains(string key);
    ListElement *getIndex(int idx);
    ListElement *getElement(string key);
    void remove(string key);
    void clearAll();
    void printList();
    ListHead();
    ~ListHead();
};
