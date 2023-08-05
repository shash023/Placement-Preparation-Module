/*
Find the intersection node of two linked list.
[Optimal approach -- find difference in length]

T.C - O(M) + O(M - N) + O(N) = O(2M)
S.C - O(1)
*/

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    if(firstHead == NULL || secondHead == NULL) return 0;

    Node *a = firstHead;
    Node *b = secondHead;

    while(a != b) {
        a = a == NULL ? secondHead : a->next;
        b = b == NULL ? firstHead : b->next;
    }

    return a;
}