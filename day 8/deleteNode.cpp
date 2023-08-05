/*
Delete a given node from the linked list.
[Note: head is node given]

T.C - O(1)
S.C - O(1)
*/

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void deleteNode(LinkedListNode<int> * node) {
    LinkedListNode<int> * ptr = node->next;
    node->data = ptr->data;
    node->next = ptr->next;
    delete ptr;
}