//prawdopodobnie dobrze-troche na szybko pisane
#include <iostream>
#include <cmath>
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

int getSumOfList(Node *head, int numberOfElements)
{
    int multipler = pow(10, numberOfElements - 1);
    int result = 0;
    while(head != nullptr)
    {
        result += (head->data * multipler);
        head = head->next;
        multipler /= 10;
    }
    return result;
}

void createListBasedOnNumber(Node **head, int number)
{
    while(number > 0)
    {
        int current = number % 10;
        insertBack(head, current);
        number /= 10;
    }
}

void deleteFirstElement(Node **head)
{
    if(!head) return;
    Node *temp = *head;
    *head = (*head)->next;
    delete temp;
}

Node* sumList(Node *head1, Node *head2)
{
    Node *newList1 = nullptr;
    int numberOfElements = 0;
    while(head1 != nullptr)
    {
        ++numberOfElements;
        insertFront(&newList1, head1->data);
        head1 = head1->next;
    }
    int leftNumber = getSumOfList(newList1, numberOfElements);

    Node *newList2 = nullptr;
    numberOfElements = 0;
    while(head2 != nullptr)
    {
        ++numberOfElements;
        insertFront(&newList2, head2->data);
        head2 = head2->next;
    }
    int rightNumber = getSumOfList(newList2, numberOfElements);

    int finalNumber = leftNumber + rightNumber;
    cout << "finalNumber=" << finalNumber << endl;

    Node *resultList = new Node();//initialize first element to 0. Force to delete first element later
    createListBasedOnNumber(&resultList, finalNumber);
    deleteFirstElement(&resultList);
    return resultList;
}

int main()
{
    Node *n = new Node();
    n->data = 7;
    insertBack(&n, 1);
    insertBack(&n, 6);
    //printList(n);

    Node *n2 = new Node();
    n2->data = 5;
    insertBack(&n2, 9);
    insertBack(&n2, 2);
    //printList(n2);

    printList(sumList(n, n2));

    deleteListWithoutRecursion(&n);
    deleteListWithoutRecursion(&n2);
}
