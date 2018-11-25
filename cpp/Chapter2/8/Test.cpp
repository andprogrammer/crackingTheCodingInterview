//po mojemu wedlug mojej rozkminy
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
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

int len(Node *head, int &number)//recursion version
{
    if(!head) return 0;
    return len(head->next, ++number);
}

int len(Node *head)
{
    int numberOfElements = 0;
    while(head != nullptr)
    {
        head = head->next;
        ++numberOfElements;
    }
    return numberOfElements;
}

int LoopDetection(Node *head)
{
    unordered_set<int> elements;
    elements.insert(head->data);
    head = head->next;
    while(head)
    {
        if(elements.find(head->data) != elements.end()) return head->data;
        elements.insert(head->data);
        head = head->next;
    }
    return 0;
}

int main()
{
    Node *head = new Node();
    head->data = 2;
    insertBack(&head, 4);
    insertBack(&head, 8);
    insertBack(&head, 16);
    insertBack(&head, 4);
    insertBack(&head, 32);

    printList(head);
    cout << LoopDetection(head) << endl;

    deleteListWithoutRecursion(&head);
}
