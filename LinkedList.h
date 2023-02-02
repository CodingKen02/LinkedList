#pragma once
#include "Node.h"

class LinkedList
{
    // Private variables only accessible from the class
    private:
        Node *head;
        Node *tail;
        int length;

    // Public methods accessible from anywhere
    public:

        // Constructor (this is a blank slate List)
        LinkedList():
            head(nullptr),tail(nullptr), length(0) {}
        
        // Deconstructor
        ~LinkedList();

        // Inserting and Removing Node Methods
        void insertStart(int data);
        void insertEnd(int data);
        void insertAt(int index, int data);
        void removeStart();
        void removeEnd();
        void removeAt(int index);

        // Interface Methods (display, search, update, and reverse)
        void displayList();
        void updateList(int oldData, int newData);
        bool searchList(int data);
        void reverseList();
};


