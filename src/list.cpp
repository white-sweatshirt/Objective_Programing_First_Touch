#include "List.h"
template <class t>
void ensureThatPointerWasCreated(t p)
{
	// other less flashy implemation is (void *) in parametr list
	if (!p)
		exit(1);
}
ListHead::ListHead()
{
	this->first = NULL;
	this->size = 0;
}
ListElement::ListElement(string key)
{
	this->key = key;
	this->next = NULL;
	this->prev = NULL;
}
string ListElement::getKey()
{
	return this->key;
}
void ListHead::addToBegging(string key)
{
	ListElement *startNew = new ListElement(key);
	ensureThatPointerWasCreated(startNew);
	if (!this->first)
	{
		this->first = startNew;
		startNew->next = NULL;
		startNew->prev = NULL;
		return;
	}
	this->first->prev = startNew;
	startNew->next = this->first;
	this->first = startNew;
	this->first->prev = NULL;
}
void ListHead::addToEnd(string key)
{
	// i dont have to do anything constructor does job
	ListElement *elementToAdd = new ListElement(key);
	ensureThatPointerWasCreated(elementToAdd);
	if (!this->first)
	{
		this->first = elementToAdd;
		this->first->next = NULL;
		this->first->prev = NULL;
	}
	ListElement *walker, *prev;
	walker = prev = this->first;
	while (walker)
	{
		prev = walker;
		walker = walker->next;
	}
	prev->next = elementToAdd;
	elementToAdd->prev = prev;
}

bool ListHead::contains(string key)
{
	ListElement *walker;
	walker = this->first;
	while (walker)
	{
		if (walker->getKey() == key)
			return 1;
		walker = walker->next;
	}
	return 0;
}

ListElement *ListHead::getIndex(int idx)
{
	ListElement *walker = this->first;
	int i = 0;
	while (walker)
	{
		i++;
		if (i == idx)
			return walker;
	}
	return NULL;
}

void ListHead::remove(string key)
{
	// assumptions: so far none for me to write
	// operation: finds and deletetes first matching key
	// result: removing first element with matching key, mantains structure of list

	if (!this->first)
		return;

	ListElement *prev, *walker, *temp = this->first;
	walker = this->first;
	if (walker->getKey() == key)
	{
		this->first = walker->next;
		delete walker;
		return;
	}

	while (walker)
	{
		prev = walker;
		walker = walker->next;
		// this if uses special property that ListHead is friend of ListElement
		if(walker->key==key)
		{
			temp=walker;
			walker=walker->next;
			prev->next=walker;
			walker->prev=prev;
			delete temp;
			return;
		}

	}
}

void ListHead::clearAll()
{

	ListElement *walker = this->first;
	ListElement *temp = walker;
	walker = walker->next;
	while (temp)
	{
		walker = walker->next;
		delete temp;
		temp = walker;
	}
	this->first = NULL;
}

void ListHead::printList()
{
	ListElement *walker = this->first;
	while (walker)
	{
		cout << walker->getKey() << "  ";
		walker = walker->next;
	}
	puts("");
}

ListHead::~ListHead()
{
	clearAll();
}
