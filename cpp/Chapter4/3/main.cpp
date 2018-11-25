#include<iostream>
#include<vector>
using namespace std;

template <typename T> struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
};

template <typename T> void createLevelLinkedList(Node<T> *root, vector<vector<Node<T>*>> &lists, int level)
{
    if(!root) return;

    if(lists.size() == level)
    {
        vector<Node<T>*> list;
        list.push_back(root);
        lists.push_back(list);
    }
    else
    {
        lists[level].push_back(root);
    }
    createLevelLinkedList(root->left, lists, level + 1);
    createLevelLinkedList(root->right, lists, level + 1);
}

template <typename T> vector<vector<Node<T>*>> createLevelLinkedList(Node<T> *root)
{
    vector<vector<Node<T>*>> lists;
    createLevelLinkedList(root, lists, 0);
    return lists;
}

int main()
{
    Node<int> *head = new Node<int>();
    head->data = 2;
    Node<int> *n1 = new Node<int>();
    n1->data = 4;
    Node<int> *n2 = new Node<int>();
    n2->data = 8;
    Node<int> *n3 = new Node<int>();
    n3->data = 16;
    Node<int> *n4 = new Node<int>();
    n4->data = 32;

/*
      2
     / \
     4  8
    / \
    16 32
 */

    head->left = n1;
    head->right = n2;
    head->left->left = n3;
    head->left->right = n4;

    auto listOfDepths = createLevelLinkedList(head);
    for(const auto &lists : listOfDepths)
    {
        for(const auto &list : lists)
        {
            if(list->left) cout << list->left->data << " : ";
            if(list->right) cout << list->right->data << endl;
        }
    }

    return 0;
}
