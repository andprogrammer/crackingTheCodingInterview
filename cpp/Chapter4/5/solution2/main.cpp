#include<iostream>
#include<limits>
using namespace std;

template <typename T> struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <typename T> bool inOrder(Node<T> *root, int &lastVisited)
{
    if(!root) return true;

    inOrder(root->left, lastVisited);

    if(root->data < lastVisited) return false;
    lastVisited = root->data;

    inOrder(root->right, lastVisited);

    return true;
}

template <typename T> bool isBST(Node<T> *root)
{
    if(!root) return true;
    int lastVisited = numeric_limits<int>::min();
    return inOrder(root, lastVisited);
}

int main()
{
    Node<int> *head = new Node<int>();
    head->data = 16;
    Node<int> *n1 = new Node<int>();
    n1->data = 4;
    Node<int> *n2 = new Node<int>();
    n2->data = 32;
    Node<int> *n3 = new Node<int>();
    n3->data = 2;
    Node<int> *n4 = new Node<int>();
    n4->data = 8;

    head->left = n1;
    head->right = n2;
    head->left->left = n3;
    head->left->right = n4;
/*
      16
     / \
     4  32
    / \
    2 8
 */

    cout << boolalpha << isBST(head) << endl;

    return 0;
}
