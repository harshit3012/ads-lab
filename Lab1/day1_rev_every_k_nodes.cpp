#include <iostream>

using namespace std;

class Node {
   public:
    int data;
    Node* next;
};

Node* reverse(Node* head, int k) {
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL)
        head->next = reverse(next, k);
    return prev;
}

void printList(Node* n) {
    while (n != NULL) {
        cout << n->data;
        n = n->next;
        if (n != NULL)
            cout << "->";
        else
            cout << endl;
    }
}

int main() {
    Node* head = new Node();
    Node* curr = head;
    int size, k;
    cout << "Enter the size of ll : ";
    cin >> size;
    cout << "Enter the " << size << " nodes : " << endl;
    for (int i = 0; i < size; i++) {
        cin >> curr->data;

        if (i + 1 < size) {
            curr->next = new Node();
            curr = curr->next;
        }
    }
    cout << "Enter k : ";
    cin >> k;
    cout << "The k reversed ll : ";
    printList(reverse(head, k));
    return 0;
}