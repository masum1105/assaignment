#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void remove_duplicates(Node *&head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *run = curr;
        while (run->next != NULL)
        {
            if (run->next->val == curr->val)
            {
                Node *temp = run->next;
                run->next = run->next->next;
                delete temp;
            }
            else
            {
                run = run->next;
            }
        }
        curr = curr->next;
    }
}

void print_list(Node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (cin >> val && val != -1)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    remove_duplicates(head);
    print_list(head);
    return 0;
}