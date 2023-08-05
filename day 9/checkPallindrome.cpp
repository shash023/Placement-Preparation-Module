/*
Check whether the given linked list is a pallindrome.

T.C - O(N/2) + O(N/2) + O(N/2)
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
LinkedListNode<int> *reverseList(LinkedListNode<int> *head) {
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;
    LinkedListNode<int> *next = NULL;

    while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL)
        return true;
        
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    LinkedListNode<int> *mid = slow;
    slow = reverseList(slow->next);
    mid->next = slow;

    while(slow) {
        if(slow->data != head->data) {
            return false;
        }
        slow = slow->next;
        head = head->next;
    }

    return true;
}