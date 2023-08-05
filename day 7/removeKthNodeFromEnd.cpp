/*
Remove Kth node from the end.

T.C - O(N)
S.C - O(1)
*/

/*
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
*/

Node* removeKthNode(Node* head, int K)
{
    Node *start = new Node();
    start->next = head;
    Node *point1 = start;
    Node *point2 = start;
    
    while(K--) {
        point2 = point2->next;
    }

    while(point2->next != NULL) {
        point1 = point1->next;
        point2 = point2->next;
    }

    point1->next = point1->next->next;

    return start->next;
}
