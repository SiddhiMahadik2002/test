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

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *current = head;
    Node *previous = NULL;
    Node *runner = NULL;
    while (current != NULL)
    {
        runner = current->next;
        current->next = previous;
        previous = current;
        current = runner;
    }
    return previous;
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

    Node *head = new Node(5);
    head->next = new Node(2);
    head->next->next = new Node(9);

    print(head);

    head = reverse(head);

    print(head);
}
