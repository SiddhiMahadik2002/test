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

void insertAtHead(Node *&tail, int d)
{
    Node *newNode = new Node(d);
    if (tail == NULL)
    {
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }
}

void insertAtTail(Node *&tail, int d)
{
    Node *newNode = new Node(d);
    if (tail == NULL)
    {
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = tail->next;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

void insertAtPosition(Node *&tail, int position, int d)
{
    if (tail == NULL || position == 1)
    {
        insertAtHead(tail, d);
        return;
    }

    Node *temp = tail->next;
    int cnt = 1;

    while (cnt < position - 1 && temp != tail)
    {
        temp = temp->next;
        cnt++;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;

    if (temp == tail)
    {
        tail = nodeToInsert;
    }
}

int main()
{
    Node *tail = NULL;

    insertAtTail(tail, 12);
    insertAtTail(tail, 42);
    insertAtPosition(tail, 3, 92);
    print(tail);

    insertAtHead(tail, 1);
    print(tail);

    insertAtPosition(tail, 2, 24);
    print(tail);

    return 0;
}
