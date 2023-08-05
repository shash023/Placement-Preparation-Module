/*
Flatten the linked list.

T.C - O(N*N*M)
S>C - O(1)
*/

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node *mergeList(Node *a, Node *b) {
	Node *temp = new Node(0);
	Node *res = temp;

	while(a && b) {
		if(a->data <= b->data) {
			temp->child = a;
			temp = temp->child;
			a = a->child;
		}
		else {
			temp->child = b;
			temp = temp->child;
			b = b->child;
		}
	}

	if(a) temp->child = a;
	else temp->child = b;

	return res->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL) 
		return head;

	Node *l2 = flattenLinkedList(head->next);
	head->next = NULL;
	head = mergeList(head, l2);

	return head;
}
