#include <iostream>
#include <cstdlib>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *hd);
void addFront(Node *&head, float value);
void addTail(Node *&head, float value);
bool insertAfterPos(Node *&head, int position, float value);
bool removeAt(Node *&head, int position); // remove @ given position
void clearList(Node *&head);

int main() {
    Node *head = nullptr;
    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int val = rand() % 100;
        addFront(head, val)
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int choice;
    cout << "Choice --> ";
    cin >> choice;
    if (!removeAt(head, choice)) // returns boolean
        cout << "Could not delete node " << choice << ".\n";
    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> choice;
    if (!insertAfterPos(head, choice, 10000)){
        cout << "Could not insert after node " << choice << ".\n";
    }
    output(head);

    // deleting the linked list
    clearList(head);
    output(head);

    return 0;
}

void output(Node *hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node *current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addFront(Node *&head, float value) {
    Node *n = new Node;
    n->value = value;
    n->next = head;
    head = n;
}

void addTail(Node *&head, float value) {
    Node *n = new Node;
    n->value = value;
    n->next = nullptr;
    if (!head) {
        head = n;
        return;
    }
    Node *cur = head;
    while (cur->next){
        cur = cur->next;
    }
    cur->next = n;
}

bool insertAfterPos(Node *&head, int position, float value) {
    if (position <= 0 || !head)
        return false;
    Node *cur = head;
    for (int i = 1; i < position && cur; ++i)
        cur = cur->next;
    if (!cur)
        return false;
    Node *n = new Node;
    n->value = value;
    n->next = cur->next;
    cur->next = n;
    return true;
}

bool removeAt(Node *&head, int position) {
    if (!head || position <= 0)
        return false;
    if (position == 1) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return true;
    }
    Node *prev = head;
    for(int i = 1; i < position - 1 && prev; ++i){
        prev = prev->next;
    }
    if(!prev || !prev->next){
        return false;
    }
    Node *toDelete = prev->next;
    prev->next = toDelete->next;
    delete toDelete;
    return true;
}

void clearList(Node *&head){
    Node *cur = head;
    while (cur) {
        Node *next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
}
