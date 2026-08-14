#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

int main() {

   
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    
    cout << "Linked List: ";

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;

    
    int key;
    cout << "Enter element to search: ";
    cin >> key;

    temp = head;
    int position = 1;
    bool found = false;

    while (temp != NULL) {

        if (temp->data == key) {
            cout << "Element found!" << endl;
            cout << "Position: " << position << endl;
            found = true;
            break;
        }

        temp = temp->next;
        position++;
    }

    if (!found) {
        cout << "Element not found!" << endl;
    }

    return 0;
}