//prawdopodobnie dobrze-troche na szybko pisane
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

bool isPalindrom(const vector<int> &v)
{
    vector<int> temp;
    size_t vSize = v.size();
    temp.reserve(v.size());
    for(auto r = v.crbegin(); r != v.crend(); ++r)
    {
        temp.push_back(*r);
    }

    for(int i=0;i<vSize;++i)
    {
        if(temp[i] != v[i]) return false;
    }
    return true;
}

bool isPalindrom(Node *head)
{
    vector<int> v;
    while(head != nullptr)
    {
        v.push_back(head->data);
        head = head->next;
    }
    return isPalindrom(v);
}

int main()
{
    Node *n = new Node();
    n->data = 7;
    insertBack(&n, 1);
    insertBack(&n, 6);
    insertBack(&n, 6);
    insertBack(&n, 1);
    insertBack(&n, 7);

    Node *n2 = new Node();
    n2->data = 5;
    insertBack(&n2, 9);
    insertBack(&n2, 2);

    cout << boolalpha << "isPalindrom(n)=" << isPalindrom(n) << endl;
    cout << "isPalindrom(n)=" << isPalindrom(n2) << endl;

    deleteListWithoutRecursion(&n);
    deleteListWithoutRecursion(&n2);
}
