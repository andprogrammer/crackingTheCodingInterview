#include<iostream>
#include<limits>
#include<cmath>
using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;
};

int countPathsWithSumFromNode(Node *root, int targetSum, int &currentSum)
{
    if(!root) return 0;
    currentSum += root->data;
    int totalPaths = 0;
    if(currentSum == targetSum) ++totalPaths;

    totalPaths += countPathsWithSumFromNode(root->left, targetSum, currentSum);
    totalPaths += countPathsWithSumFromNode(root->right, targetSum, currentSum);
    return totalPaths;
}

int countPathsWithSum(Node *root, int targetSum)
{
    if(!root) return 0;
    int sum = 0;
    int pathsFromRoot = countPathsWithSumFromNode(root, targetSum, sum);
    int pathsOnLeft = countPathsWithSum(root->left, targetSum);
    int pathsOnRight = countPathsWithSum(root->right, targetSum);
    return pathsFromRoot + pathsOnLeft + pathsOnRight;
}

//moja implementacja
//void sumPreOrder(Node *root, int &sum, int expectedSum)
//{
//    if(!root) return;
//    sum += root->data;
//    if(sum == expectedSum) return;
//    sumPreOrder(root->left, sum, expectedSum);
//    sumPreOrder(root->right, sum, expectedSum);
//}

//void preOrder(Node *root, int expectedSum, int &numberOfExpectedSum)
//{
//    if(!root) return;
//    int sum = 0;
//    sumPreOrder(root, sum, expectedSum);
//    if(sum == expectedSum) ++numberOfExpectedSum;
//    preOrder(root->left, expectedSum, numberOfExpectedSum);
//    preOrder(root->right, expectedSum, numberOfExpectedSum);
//}

//int pathWithSum(Node *root, int expectedSum)
//{
//    int numberOfExpectedSum = 0;
//    preOrder(root, expectedSum, numberOfExpectedSum);
//    return numberOfExpectedSum;
//}

int main()
{
    Node *h = new Node();
    h->data = 6;

    Node* a = new Node();
    a->data = 8;
    Node* b = new Node();
    b->data = 10;
    Node* c = new Node();
    c->data = 4;
    Node* d = new Node();
    d->data = 6;
    Node* e = new Node();
    e->data = 30;

    h->left = a;
    h->right = b;
    b->left = c;
    b->right = d;
    d->left = e;

    cout << countPathsWithSum(h, 64) << endl;

    return 0;
}
