//mozna by poprawic
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
    Node *next = nullptr;
    int data;
};

void insert(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
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

void deleteNode(Node **head, int data)
{
    if (*head == nullptr) return;

    Node *headTemp = *head;
    Node *prev = nullptr;

    if (headTemp && headTemp->data == data)
    {
        *head = headTemp->next;
        delete headTemp;
        return;
    }

    while (headTemp && headTemp->data != data)
    {
        prev = headTemp;
        headTemp = headTemp->next;
    }

    if (headTemp == nullptr) return;

    prev->next = headTemp->next;
    delete headTemp;
}

void deleteList(Node **head)
{
    if (*head == nullptr) return;

    deleteList(&(*head)->next);
    if((*head)->next) deleteNode(&(*head)->next, (*head)->next->data);
}
//delete head;
//head = nullptr;

void deleteListWithoutRecursion(Node **head)
{
    while (*head)
    {
        Node *curr = (*head)->next;
        delete *head;
        *head = curr;
    }
}

bool isOdd(int number)
{
    return number & 1;
}

uint32_t getNumberOfElements(Node *head)
{
    if (!head) return 0;
    uint32_t numberOfElements = 0u;
    while(head != nullptr)
    {
        ++numberOfElements;
        head = head->next;
    }
    return numberOfElements;
}

void deleteAtGivenPosition(struct Node **head_ref, int position)
{
   // If linked list is empty
   if (*head_ref == nullptr)
      return;

   // Store head node
   struct Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0)
    {
        *head_ref = temp->next;   // Change head
        delete temp;               // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i=0; temp!=nullptr && i<position-1; i++)
         temp = temp->next;

    // If position is more than number of ndoes
    if (temp == nullptr || temp->next == nullptr)
         return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node *next = temp->next->next;

    // Unlink the node from linked list
    delete temp->next;  // Free memory

    temp->next = next;  // Unlink the deleted node from list
}

void deleteMiddleElement(Node *head)
{
    uint32_t numberOfElements = getNumberOfElements(head);
    uint32_t middleElement = numberOfElements / 2;
    if(!isOdd(middleElement) && middleElement != 0)
    {
        --middleElement;
    }
    deleteAtGivenPosition(&head, middleElement);
}

int main()
{
    Node *n = new Node();
    n->data = 2;
    insert(&n, 4);
    insert(&n, 8);
    insert(&n, 16);
    insert(&n, 32);
    insert(&n,64);
    insert(&n, 128);

    printList(n);
    deleteMiddleElement(n);
    printList(n);}
