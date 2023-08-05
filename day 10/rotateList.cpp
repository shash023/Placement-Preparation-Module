/*
Rotate a list to the right by k.

T.C - O(N) + O(N - (k % N)) = O(N)
S.C - O(1)
*/

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k) {
     if(head == NULL || head->next == NULL || k == 0)
          return head;

     int len = 1;
     Node *ptr = head;
     while(ptr->next) {
          len++;
          ptr = ptr->next;
     }
     ptr->next = head;

     k = k % len;
     int pos = len - k;

     while(pos--) {
          ptr = ptr->next;
     }

     head = ptr->next;
     ptr->next = NULL;

     return head;
}