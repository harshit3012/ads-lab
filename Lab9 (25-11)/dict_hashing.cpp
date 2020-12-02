#include <stdlib.h>

#include <iostream>
#define YELLOW "\033[33m"
#define RESET "\033[0m"

using namespace std;

#define max 10

typedef struct list {
    int data;
    struct list *next;
} node;
node *ptr[max], *root[max], *temp[max];

class Dictionary {
   public:
    int index;
    Dictionary();
    void insert(int);
    int search(int);
    void del(int);
};

Dictionary::Dictionary() {
    index = -1;
    for (int i = 0; i < max; i++) {
        root[i] = NULL;
        ptr[i] = NULL;
        temp[i] = NULL;
    }
}

void Dictionary::insert(int key) {
    index = int(key % max);
    ptr[index] = (node *)malloc(sizeof(node));
    ptr[index]->data = key;
    if (root[index] == NULL) {
        root[index] = ptr[index];
        root[index]->next = NULL;
        temp[index] = ptr[index];
    } else {
        temp[index] = root[index];
        while (temp[index]->next != NULL) temp[index] = temp[index]->next;
        temp[index]->next = ptr[index];
    }
}
int Dictionary::search(int key) {
    int flag = 0;
    index = int(key % max);
    temp[index] = root[index];
    while (temp[index] != NULL) {
        if (temp[index]->data == key) {
            flag = 1;
            break;
        } else
            temp[index] = temp[index]->next;
    }
    return flag;
}
void Dictionary::del(int key) {
    index = int(key % max);
    temp[index] = root[index];
    if (search(key) == 0) {
        cout << "Key not found in dictionary. Did not delete anything" << endl;
        return;
    }
    while (temp[index]->data != key && temp[index] != NULL) {
        ptr[index] = temp[index];
        temp[index] = temp[index]->next;
    }
    ptr[index]->next = temp[index]->next;
    cout << temp[index]->data << " has been deleted." << endl;
    temp[index]->data = -1;
    temp[index] = NULL;
    free(temp[index]);
}
int main() {
    int val, ch, n, num;
    char c;
    Dictionary d;
    do {
        cout << YELLOW << "1. Create\n2. Search for a value\n3. Delete an value" << RESET;
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "Enter the number of elements to be inserted: ";
                cin >> n;
                cout << "Enter the elements to be inserted: " << endl;
                for (int i = 0; i < n; i++) {
                    cin >> num;
                    d.insert(num);
                }
                break;
            case 2:
                cout << "Enter the element to be searched: ";
                cin >> n;
                if (d.search(n) == 1)
                    cout << "Search key found" << endl;
                else
                    cout << "Search key not found" << endl;
                break;
            case 3:
                cout << "Enter the element to be deleted: ";
                cin >> n;
                d.del(n);
                break;
            default:
                cout << "Invalid Choice." << endl;
        }
        cout << "Continue? (y/n): ";
        cin >> c;
    } while (c == 'y');
    return 0;
}