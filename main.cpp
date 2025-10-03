#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addFront(Node *&head, float value);
void addTail(Node *&head, float value);
bool insertAfterPost(Node *&head, int position, float value);
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
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
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

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
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

void clearList(Node *&head){
    Node *cur = head;
    while (cur) {
        Node *next = cur->next;
        delete cur;
        cur = next;
    }
    head = nullptr;
}
