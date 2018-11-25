#include<iostream>
using namespace std;

template <typename T> struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <typename T> int height(const Node<T> *root)
{
    if(!root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}
//O(N log N)
template <typename T> bool isBalanced(const Node<T> *root)
{
    if(!root) return true;
    int heightLeft = height(root->left);
    int heightRight = height(root->right);
    return (abs(heightLeft - heightRight) > 1) ? false : isBalanced(root->left) && isBalanced(root->right);
}

int main()
{
    Node<int> *head = new Node<int>();
    head->data = 2;
    Node<int> *n1 = new Node<int>();
    n1->data = 4;
    Node<int> *n2 = new Node<int>();
    n2->data = 8;
    head->left = n1;
    head->right = n2;
    cout << height(head) << endl;
    cout << isBalanced(head) << endl;

    return 0;
}
