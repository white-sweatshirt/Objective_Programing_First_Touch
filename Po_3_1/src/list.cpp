#include "List.h"
template <class t>
void ensureThatPointerWasCreated(t p)
{
	// assumptsions: well it assumes that p is pointer. and that its fine to stop working if doesnot exists
	// operation: checks wheter p is non zero pointer
	// result: terminates program in case of p being zero otherwise does nothing

	// alternative implementation:  less flashy implemation is (void *) in parametr list for p
	// but i wanted to use template
	if (!p)
		exit(1);
}
int ListHead::giveSize()
{
	return this->size;
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
	this->size++;
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
	this->size++;
	ListElement *elementToAdd = new ListElement(key);
	ensureThatPointerWasCreated(elementToAdd);
	if (!this->first)
	{
		this->first = elementToAdd;
		this->first->next = NULL;
		this->first->prev = NULL;
		return;
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
	// assumption: that we count indexes from zero.
	// operation: finds i element from start
	// result: returns 0 or addres of found element

	ListElement *walker = this->first;
	int i = 0;
	while (walker)
	{
		if (i == idx)
			return walker;
		walker = walker->next;
		i++;
	}
	return NULL;
}
ListElement *ListHead::getElement(string key)
{

	ListElement *walker = this->first;
	int i = 0;
	while (walker)
	{
		if (walker->key == key)
			return walker;
		walker = walker->next;
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
		this->first->prev=NULL;
		delete walker;
		return;
	}

	while (walker)
	{
		prev = walker;
		walker = walker->next;
		// this if uses special property that ListHead is friend of ListElement
		if (walker->key == key)
		{
			temp = walker;
			walker = walker->next;
			if (prev)
				prev->next = walker;
			if (walker)
				walker->prev = prev;
			delete temp;
			return;
		}
	}
}

void ListHead::clearAll()
{
	// assumes: that user might use it on empty list
	if (!this->first)
		return;
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
		cout << walker->getKey() << " ";
		walker = walker->next;
	}
	puts("");
}

void ListHead::printFromEnd()
{
	ListElement *walker = this->first;
	if (!walker)
		return;

	while (walker->next)
		walker = walker->next;
	while (walker)
	{
		cout << walker->getKey() << " ";
		walker = walker->prev;
	}
	puts("");
}

ListHead::~ListHead()
{
	clearAll();
}
