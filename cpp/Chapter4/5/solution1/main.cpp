#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template <typename T> struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <typename T> void inOrder(const Node<T> *root, vector<int> &container)
{
    if(!root) return;
    inOrder(root->left, container);
    container.push_back(root->data);
    inOrder(root->right, container);
}

template <typename T> bool isBST(const Node<T> *root)
{
    if(!root) return true;
    vector<int> container;
    inOrder(root, container);
    return is_sorted(container.begin(), container.end());
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
