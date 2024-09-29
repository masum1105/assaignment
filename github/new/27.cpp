#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert_head(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insert_tail(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void delete_node(Node *&head, Node *&tail, int idx) {
    if (head == NULL) return;  // If the list is empty
    if (idx == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) tail = NULL;  // If the list becomes empty
        return;
    }
    Node *current = head;
    for (int i = 0; i < idx - 1; ++i) {
        if (current == NULL || current->next == NULL) return;  // If the index is out of bounds
        current = current->next;
    }
    Node *nodeToDelete = current->next;
    if (nodeToDelete == NULL) return;  // If the index is out of bounds
    current->next = nodeToDelete->next;
    if (nodeToDelete == tail) tail = current;  // If the last node is deleted
    delete nodeToDelete;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;
    Node *head = NULL;
    Node *tail = NULL;
    while (Q--) {
        int X, V;
        cin >> X >> V;
        if (X == 0) {
            insert_head(head, tail, V);
        } else if (X == 1) {
            insert_tail(head, tail, V);
        } else if (X == 2) {
            delete_node(head, tail, V);
        }
        print_list(head);
    }
    return 0;
}
