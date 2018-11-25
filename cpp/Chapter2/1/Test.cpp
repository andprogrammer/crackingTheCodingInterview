#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node
{
	Node *next = nullptr;
	int32_t data;
};

void insert(Node **head, int32_t data)
{
	Node *newNode = new Node();
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

void printList(const Node *head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void deleteNode(Node **head, int data)
{
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

void removeDups(Node **head)
{
	if ((*head == nullptr) || (*head && (*head)->next == nullptr)) return;

	unordered_map<int, int> values;
	Node *headTemp = *head;
	while (headTemp)
	{
		++values[headTemp->data];
		headTemp = headTemp->next;
	}

	for (auto i : values)
	{
		while (i.second > 1)
		{
			deleteNode(head, i.first);
			--i.second;
		}
	}
}

void removeDupsDifferentSolution(Node **head)
{
	if ((*head == nullptr) || (*head && (*head)->next == nullptr)) return;

	unordered_map<int, int> values;
	Node *curr = (*head)->next;
	Node *prev = *head;

	++values[(*head)->data];

	while (curr)
	{
		if (values.find(curr->data) == values.end())
		{
			++values[curr->data];
			curr = curr->next;
			prev = prev->next;
		}
		else
		{
			Node *temp = curr;
			prev->next = curr->next;
			curr = curr->next;
			delete temp;
		}
	}
}

void removeDupsWithoutDataStructer(Node **head) 
{
	if (head == nullptr || (head && ((*head)->next == nullptr))) return;

	Node *curr = *head;
	while (curr) 
	{
		Node *runner = curr;
		while (runner->next) 
		{
			if (runner->next->data == curr->data) 
			{
				Node *runnerNextTemp = runner->next;
				runner->next = runner->next->next;
				delete runnerNextTemp;
			}
			else runner = runner->next;
		}
		curr = curr->next;
	}
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

	removeDupsWithoutDataStructer(&n);

	printList(n);
}