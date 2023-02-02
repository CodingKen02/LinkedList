#pragma once

class Node
{
    public:

        // Integer Data and Next Pointer
        int data;
        Node *next;

        //--Default Node constructor--//

        // Data is set to 0
        // Next is simply a nullptr
        Node(): 
            data(0), next(nullptr) {}

        //--Data Node constructor--//

        // Data is set to a integer value
        // Next is simply a nullptr
        Node(int data):
            data(data), next(nullptr) {}
};
