//zrobiona na podstawie:
//https://github.com/careercup/CtCI-6th-Edition-cpp/blob/a68ba3e1c630a4d218ff1294f3eaf5aeced449ec/chapter-2-Linked-Lists/2-7-intersection.cpp
#include <iostream>
#include <cmath>
#include <vector>
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

Node* Intersection(Node *head1, Node *head2)
{
    int lenHead1 = len(head1);
    int lenHead2 = len(head2);

    Node *p1 = (lenHead1 > lenHead2) ? head1 : head2;
    Node *p2 = (lenHead1 > lenHead2) ? head2 : head1;

    int i = 0;
    while(i < abs(lenHead1 - lenHead2))
    {
        ++i;
        p1 = p1->next;
    }

    while(p1 && p2)
    {
        if(p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return nullptr;
}

int main()
{
    Node *head1 = new Node();
    head1->data = 2;
    Node *n2 = new Node();
    n2->data = 4;
    Node *n3 = new Node();
    n3->data = 8;
    Node *n4 = new Node();
    n4->data = 16;
    head1->next = n2;
    n2->next = n3;
    n3->next = n4;

    Node *head2 = new Node();
    head2->data = 1;
    head2->next = n3;

    printList(Intersection(head1, head2));

    deleteListWithoutRecursion(&head1);
    deleteListWithoutRecursion(&head2);
}
