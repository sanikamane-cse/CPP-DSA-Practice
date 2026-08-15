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
    Node* second = new Node(20);

    head->next = second;

    Node* newNode = new Node(5);

    newNode->next = head;
    head = newNode;

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}