#include<iostream>
#include<limits>
#include<cmath>
using namespace std;

struct Node
{
    Node* parent = nullptr;
    Node* left;
    Node* right;
    int data;
};

Node* goUpBy(Node* n, int delta)
{
    while(n && delta)
    {
        n = n->parent;
        --delta;
    }
    return n;
}

int depth(const Node* n)
{
    int counter = 0;
    while(n)
    {
        ++counter;
        n = n->parent;
    }
    return counter;
}

void firstCommonAncestor(Node* first, Node* second)
{
    int delta = depth(first) - depth(second);
    Node* shallower = delta > 0 ? second : first;
    Node* deeper = delta > 0 ? first : second;
    deeper = goUpBy(deeper, abs(delta));

    while(deeper && shallower && deeper != shallower)
    {
        deeper = deeper->parent;
        shallower = shallower->parent;
    }
    if(shallower) cout << "common ancestor=" << shallower->data << endl;
}

int main()
{
    Node *h = new Node();
    h->data = 6;

    Node* a = new Node();
    a->data = 10;
    Node* b = new Node();
    b->data = 20;
    Node* c = new Node();
    c->data = 4;
    Node* d = new Node();
    d->data = 30;
    Node* e = new Node();
    e->data = 5;

    h->left = a;
    h->right = b;
    b->left = c;
    b->right = d;
    d->left = e;

    a->parent = h;
    b->parent = h;
    c->parent = a;
    d->parent = a;
    e->parent = d;

    firstCommonAncestor(c, e);

    return 0;
}
