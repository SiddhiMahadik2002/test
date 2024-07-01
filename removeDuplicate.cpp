#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void removeDuplicate(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            Node *runner = temp->next;
            temp->next = temp->next->next;
            delete runner;
        }
        else
        {
            temp = temp->next;
        }
    }
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(9);

    print(head);

    removeDuplicate(head);
    cout << "after removing duplicate" << endl;

    print(head);
}