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

Node* getKthToLast(Node *head, int position)
{
	if (!head) return nullptr;

	Node *curr = head;
	uint32_t elementCounter = 0u;

	while (curr)
	{
		++elementCounter;
		curr = curr->next;
	}

	if (position > elementCounter) return nullptr;
	
	int indexToFind = elementCounter - position;
	elementCounter = 0;

	while (head)
	{
		if (elementCounter == indexToFind) return head;
		head = head->next;
		++elementCounter;
	}
	return nullptr;
}

//Node* getLastNode(Node *head)

Node* getKthToLastRecursion(Node *head, int kth, int &k)
{
	if (!head) return nullptr;
	Node *n = getKthToLastRecursion(head->next, kth, k);
	++k;
	return k == kth ? head : n;
}

Node* getKthToLastRecursion(Node *head, int kth)
{
	int k = 0;
	return getKthToLastRecursion(head, kth, k);
}

int main()
{
	Node *n = new Node();
	n->data = 8;
	insert(&n, 32);
	insert(&n, 64);
	insert(&n, 8);
	insert(&n, 128);
	insert(&n, 8);
	insert(&n, 128);

	printList(n);
	if (auto element = getKthToLast(n, 2)) cout << element->data << endl;
	if (auto element = getKthToLast(n, 5)) cout << element->data << endl;

	if (auto element = getKthToLastRecursion(n, 2)) cout << element->data << endl;
	if (auto element = getKthToLastRecursion(n, 5)) cout << element->data << endl;

	deleteListWithoutRecursion(&n);

	printList(n);
}