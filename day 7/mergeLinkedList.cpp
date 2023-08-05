/*
Merge two sorted linked list. Do it in-place.

T.C - (N + M)
S.C - O(1)
*/

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL) return second;
    if(second == NULL) return first;

    Node<int> *head = new Node<int>(0);
    Node<int> *temp = head;

    while(first && second) {
        if(first->data <= second->data) {
            temp->next = first;
            temp = first;
            first = first->next;
        }
        else {
            temp->next = second;
            temp = second;
            second = second->next;
        }
    }

    while(first) {
        temp->next = first;
        temp = first;
        first = first->next;
    }

    while(second) {
        temp->next = second;
        temp = second;
        second = second->next;
    }

    return head->next;
}
