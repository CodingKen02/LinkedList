#include "LinkedList.h"
#include <iostream>

//###########################################################################//

//--LinkedList Deconstructor--//
LinkedList::~LinkedList()
{
    // Initialize a node set to the head
    Node *node = head;

    // Loop through list until your current node is a nullpt
    while (node != nullptr)
    {
        // Set head to the next node
        head = head->next;
        // Delete current node
        delete node;
        // Set current node to new head
        node = head;
    }

    // Set tail to nullptr
    tail = nullptr;
}

//###########################################################################//

void LinkedList::insertStart(int data)
{
    // Create a new Node in memory that contains
    // our data attribute
    Node *node = new Node(data);

    // Increase the size of our list accordingly
    length++;

    // Check if List is empty
    if (head == nullptr)
    {
        // Set head and tail to our new Node
        head = node;
        tail = node;

        // Return from function
        return;
    }
    
    // Point new node to the head
    node->next = head;

    // Set head to the new node
    head = node;
}

//###########################################################################//

void LinkedList::insertEnd(int data)
{
    // Create a new Node in memory that contains
    // our data attribute
    Node *node = new Node(data);

    // Increase the size of our list accordingly
    length++;

    // Check if List is empty
    if (head == nullptr)
    {
        // Set head and tail to our new Node
        head = node;
        tail = node;

        // Return from function
        return;
    }
    
    // Point our current tail to the new Node
    tail->next = node;

    // Set our tail to the new Node
    tail = node;
}

//###########################################################################//

void LinkedList::insertAt(int index, int data)
{
    // If index is not within our List's bounds, return
    if (index > length || index < 0)
    {
        std::cout << "Index Out of Bounds" << std::endl;
        return;
    }

    // If index is at start, call insertStart and return
    if (index == 0)
    {
        insertStart(data);
        return;
    }

    // If index is at end, call insertEnd and return
    if (index == length)
    {
        insertEnd(data);
        return;
    }

    // Create a new Node in memory that contains
    // our data attribute
    Node *node = new Node(data);

    // Increase the size of our list accordingly
    length++;

    // Initialize node to keep track of our location
    Node *current = head;

    // Loop (index - 1) times
    for (int i = 0; i < (index - 1); i++)
    {
        // Adjust our current node as we loop
        current = current->next;
    }

    // Initialize a temp node set to the node after our loop
    Node *temp = current->next;

    // Set our current node to point to our new node
    current->next = node;

    // Set our new node to point to our temp node
    node->next = temp;
}

//###########################################################################//

void LinkedList::removeStart()
{
    // If list is empty, return
    if (head == nullptr)
    {
        std::cout << "No data to delete" << std::endl;
        return;
    }

    // Adjust length accordingly
    length--;

    // Initialize node set to head
    Node *node = head;

    // Adjust our head to what it points to
    head = head->next;

    // Delete original head
    delete node;
}

//###########################################################################//

void LinkedList::removeEnd()
{
    // If list is empty, return
    if (head == nullptr)
    {
        std::cout << "No data to delete" << std::endl;
        return;
    }

    // Adjust length accordingly
    length--;

    // Initialize node set to head to keep track of location
    Node *current = head;

    // Checks if head points to nullptr
    if (head->next == nullptr)
    {
        // Set head and tail to nullptr
        head = nullptr;
        tail = nullptr;

        // Delete original head
        delete current;
        return;
    }

    // Loop through LinkedList until we get to the second to last Node
    while (current->next->next != nullptr)
    {
        // Adjust our current node as we loop
        current = current->next;
    }

    // Delete the data of what we're currently pointing to
    delete current->next;

    // Set what we're pointing at to a nullptr
    current->next = nullptr;

    // Set our current location as the new tail
    tail = current;
}

//###########################################################################//

void LinkedList::removeAt(int index)
{
    // If list is empty, return
    if (head == nullptr)
    {
        std::cout << "No data to delete" << std::endl;
        return;
    }

    // If index is not within our List's bounds, return
    if (index > length || index < 0)
    {
        std::cout << "Index Out of Bounds" << std::endl;
        return;
    }

    // If index is at start, call removeStart and return
    if (index == 0)
    {
        removeStart();
        return;
    }

    // If index is at end, call removeEnd and return
    if (index == length)
    {
        removeEnd();
        return;
    }

    // Adjust length accordingly
    length--;

    // Initialize node set to head to keep track of location
    Node *current = head;

    // Loop (index - 1) times
    for (int i = 0; i < (index - 1); i++)
    {
        // Adjust our current node as we loop
        current = current->next;
    }

    // Initialize a temporary node set the node after our loop
    Node *temp = current->next;

    // Set what we're pointing to 
    current->next = current->next->next;

    // Delete the data of what we're currently pointing to
    delete temp;
}

//###########################################################################//

void LinkedList::displayList()
{
    // Initialize node set to head to keep track of location
    Node *current = head;

    // Loop through list
    while (current != nullptr)
    {
        // Print current node's data and move to the next node
        std::cout << "[ " << current->data << " ] -> ";
        current = current->next;
    }

    // Print a newline for formatting
    std::cout << std::endl;
}

// NEW FUNCTION ###########################################################################//

void LinkedList::updateList(int oldData, int newData)
{
    // Initialize starting index to update 
    int index = 0;

    // If the list is empty, return
    if (head == nullptr)
    {
        std::cout << "No data to update" << std::endl;
        return;
    }

    // Initialize node set to head to keep track of location
    Node *current = head;

    //Initialize node set to tail for the list's last data inserted
    Node *temp = tail;

    // Loop through list
    while (current->next != nullptr)
    {
        // If the data is found in the list, update the data and return
        if (current->data == oldData)
        {
            current->data = newData;
            std::cout << oldData << " was stored in index " << index << ", now replaced with " << newData << std::endl;
            return;
        }

        // If the data is found at the end, update the data and return
        if (temp->data == oldData)
        {
            temp->data = newData;
            std::cout << oldData << " was stored at the end, now replaced with " << newData << std::endl;
            return;

        }

        // Adjust our current node
        current = current->next;

        // Adjust length accordingly
        index++;
    }
    // Else, print if data is not in the list
    std::cout << oldData << " does not exist in the list" << std::endl;
}

// NEW FUNCTION ###########################################################################//

bool LinkedList::searchList(int data)
{

    // Initialize node set to head to keep track of location
    Node *current = head;

    // Loop through list
    while (current != nullptr)
    {
        // If the data is found in the list, update the data and return
        if (current->data == data)
        {
            return true;
        }

        // Adjust our current node
        current = current->next;

    }
    // Else, print if data is not in the list
    return false;

}

// NEW FUNCTION ###########################################################################//

void LinkedList::reverseList()
{
    // If the list is empty, return
    if (head == nullptr)
    {
        std::cout << "No data to reverse" << std::endl;
        return;
    }

    // Initialize pointers for the new order
    Node *temp = nullptr;
    Node *prev = nullptr;

    // Initialize node set to head to keep track of location
    Node *current = head;

    // Loop through list
    while(current != nullptr)
    {
        // Assign temp to current's next node
        temp = current->next;
        // Assign current's node to previous's next node
        current->next = prev;
        // Increment previous node to current node
        prev = current;
        // Increment current node to temp node
        current = temp;
    }
    // List and head is now reversed and ready to display (incremented head to previous node)
    head = prev;
}


