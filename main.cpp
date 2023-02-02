// Add our class header files
#include "LinkedList.h"
#include <iostream>

int main()
{
    LinkedList a;
	
    a.insertStart(1);
    a.insertStart(2);
    a.insertEnd(5);
    a.insertStart(0);
    a.insertAt(3, 7);

    a.removeAt(3);

	a.displayList();
    a.updateList(5, 6);
    a.displayList();

    int data = 3;
    if (a.searchList(3))
    {
        std::cout << data << " exists in the list" << std::endl;
    }
    else 
    {
        std::cout << data << " does NOT exist in the list" << std::endl;
    }

    a.reverseList();
    a.displayList();
    return 0;
}