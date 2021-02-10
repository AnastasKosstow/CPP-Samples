
#include <iostream>

#include "linkedList.h"

int main()
{
    linkedList::LinkedList<int>* list = new linkedList::LinkedList<int>();
    list->Add(1);
    list->Add(2);
    list->Add(3);
    list->Add(4);

    for (int& value : *list)
    {
        _STD cout << value << _STD endl;
    }

    list->Remove(3);
    _STD cout << std::boolalpha << list->Contains(3) << _STD endl;

    for (int& value : *list)
    {
        _STD cout << value << _STD endl;
    }

    // Delete all data from memory
    delete list;

    return 0;
}
