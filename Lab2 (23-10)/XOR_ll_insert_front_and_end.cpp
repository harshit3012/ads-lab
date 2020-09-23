#include <inttypes.h>

#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node* npx;
};
Node* XOR(Node* a, Node* b) {
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}
void insertHead(Node** head, int data) {
    Node* new_node = new Node();
    new_node->data = data;

    new_node->npx = *head;

    if (*head != NULL) {
        (*head)->npx = XOR(new_node, (*head)->npx);
    }

    (*head) = new_node;
}

void insertEnd(Node** head, int data) {
    Node* new_node = new Node();
    new_node->data = data;

    if (*head == NULL) {
        new_node->npx = *head;
        *head = new_node;
    }

    else {
        Node* curr = *head;
        Node* prev = NULL;
        Node* next;

        while (XOR(prev, curr->npx) != NULL) {
            next = XOR(prev, curr->npx);

            prev = curr;
            curr = next;
        }
        new_node->npx = curr;
        curr->npx = XOR(prev, new_node);
    }
}
void printList(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next;
    if (head == NULL) {
        cout << "Empty XOR Linked List" << endl;
        return;
    }
    cout << "Following are the nodes of XOR Linked List: " << endl;

    while (curr != NULL) {
        cout << curr->data << " ";
        next = XOR(prev, curr->npx);

        prev = curr;
        curr = next;
    }
    cout << endl;
}
int main() {
    int choice, ele;
    Node* head = NULL;
    cout << "1. Insert at beginning\n2. Insert at end\n3. Display\n4. Exit" << endl;
    do {
        cout << "Enter option : "
             << " ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter integer to insert : "
                     << " ";
                cin >> ele;
                insertHead(&head, ele);
                break;
            case 2:
                cout << "Enter integer to insert : "
                     << " ";
                cin >> ele;
                insertEnd(&head, ele);
                break;
            case 3:
                printList(head);
                break;
            case 4:
                return 0;
        }
    } while (choice != 4);
    return 0;
}