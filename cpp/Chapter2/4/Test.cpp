//prawdopodobnie dobrze-troche na szybko pisane
#include <iostream>
using namespace std;

struct Node
{
    Node *next = nullptr;
    int data;
};

void insertFront(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void insertBack(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    Node *temp = *head;
    Node *prev = temp;
    while(temp != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = newNode;
}

void printList(const Node *head)
{
    cout << "printList()" << endl;
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteListWithoutRecursion(Node **head)
{
    while (*head)
    {
        Node *curr = (*head)->next;
        delete *head;
        *head = curr;
    }
}

Node* partition(Node *head, int partition)
{
    Node *newList = nullptr;
    while(head != nullptr)
    {
        if(head->data >= partition) insertBack(&newList, head->data);
        else insertFront(&newList, head->data);
        head = head->next;
    }
    return newList;
}

int main()
{
    Node *n = new Node();
    n->data = 3;
    insertFront(&n, 5);
    insertFront(&n, 8);
    insertFront(&n, 5);
    insertBack(&n, 99);
    insertFront(&n, 10);
    insertFront(&n,2);
    insertFront(&n, 1);

    insertBack(&n, 99);
    cout << "BEFORE PARTIOTIONING" << endl;
    printList(n);
    cout << "AFTER PARTIOTIONING" << endl;
    printList(partition(n, 5));

    deleteListWithoutRecursion(&n);
}
