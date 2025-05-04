#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

void InsertAtHead(Node *&head, int value)
{
    Node *node1 = new Node(value);
    if (head == NULL)
    {
        head = node1;
        return;
    }
    node1->next = head;
    head->prev = node1;
    head = node1;
}
void InsertAtMiddle(Node *&head, int value, int position)
{
    if (position == 1)
    {
        InsertAtHead(head, value);
        return;
    }

    Node *temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }
    Node *node1 = new Node(value);
    if (temp->next != NULL)
    {
        temp->next->prev = node1;
    }
    node1->next = temp->next;
    temp->next = node1;
    node1->prev = temp;
}
void InsertAtEnd(Node *&head, int value)
{
    Node *node1 = new Node(value);
    if (head == NULL)
    {
        head = node1;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = node1;
    node1->prev = temp;
}
void backword_display(Node *head)
{
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    while (temp)
    {
        cout << temp->value << " <--> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}
void display(Node *head)
{
    if (head == NULL)
    {
        cout << "No node Found " << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " <--> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    int choice;
    cout << "1. Display " << endl;
    cout << "2. Insert At Head " << endl;
    cout << "3. Insert At End " << endl;
    cout << "4. Insert At Middle " << endl;
    Node *head = NULL;
    while (true)
    {
        cout << "Select Operation :";
        cin >> choice;
        if (choice == 1)
        {
            display(head);
        }
        else if (choice == 2)
        {
            int value;
            cout << "Enter the value to be added : ";
            cin >> value;
            InsertAtHead(head, value);
        }
        else if (choice == 3)
        {
            int value;
            cout << "Enter a value to be added at end :";
            cin >> value;
            InsertAtEnd(head, value);
        }
        if (choice == 4)
        {
            cout << "Enter the value to be inserted space seperated by location ";
            int value;
            int position;
            cin >> value >> position;
            InsertAtMiddle(head, value, position);
        }
    }

    display(head);

    return 0;
}