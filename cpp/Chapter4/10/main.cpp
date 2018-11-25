#include<iostream>
#include<limits>
#include<cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int BIG_NUMBER = 99999;

struct Node
{
    Node* left;
    Node* right;
    int data;
};

void preOrder(Node* root, vector<int> &path)
{
    if(!root)
    {
        path.push_back(BIG_NUMBER);
        return;
    }
    path.push_back(root->data);
    preOrder(root->left, path);
    preOrder(root->right, path);
}

bool isSubTree(const vector<int> &bigger, const vector<int> &smaller)
{
    if(!smaller.size()) return true;
    int first = smaller.front();

    for(int i=0; i<bigger.size(); ++i)
    {
        if(bigger[i] == first)
        {
            int shift = i;
            for(int j=1;j<smaller.size();++j)
            {
                ++shift;
                if(shift < bigger.size() && bigger[shift] != smaller[j]) return false;
                if(j == smaller.size() - 1) return true;
            }
        }
    }
    return false;
}

template<typename T> void print(const vector<T> &data)
{
    for(const auto &i : data)
        cout << i << " ";
    cout << endl;
}

bool checkSubtree(Node *left, Node *right)
{
    vector<int> leftPath;
    vector<int> rightPath;
    preOrder(left, leftPath);
    preOrder(right, rightPath);
//    print(leftPath);
//    print(rightPath);
    return isSubTree(leftPath, rightPath);
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

    cout << boolalpha << checkSubtree(h, a) << endl;//a has not assign any nodes!

    return 0;
}
