/*
Add numbers from two linked list given in reverse order.

T.C - O(N + M)
S.C - O(N)
*/

/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node *head = NULL;
    Node *ptr = NULL;
    int carry = 0, sum = 0;

    while(num1 || num2 || carry) {
        int x = 0, y = 0;
        if(num1) {
            x = num1->data;
            num1 = num1->next;
        }

        if(num2) {
            y = num2->data;
            num2 = num2->next;
        }
        sum = x + y + carry;
        carry = sum / 10;
        sum = sum % 10;
        Node *temp = new Node(sum);

        if(head == NULL) {
            head = temp;
            ptr = head;
        } else {
          ptr->next = temp;
          ptr = temp;
        }
    }

    return head;
}
