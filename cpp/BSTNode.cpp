#include<iostream>
using namespace std;

class BSTNode
{
    BSTNode *left = nullptr;
    BSTNode *right = nullptr;
    int data;
    int size = 1;

public:
    BSTNode(int data);

    void insertInOrder(int d);
    BSTNode* find(int d);

    int getData() const { return data; }
    int getSize() const { return size; }
};

BSTNode::BSTNode(int d) : data(d)
{}

void BSTNode::insertInOrder(int d)
{
    if(d <= data)
    {
        if(left) left->insertInOrder(d);
        else left = new BSTNode(d);
    }
    else
    {
        if(right) right->insertInOrder(d);
        else right = new BSTNode(d);
    }
    ++size;
}

BSTNode* BSTNode::find(int d)
{
    if(data == d) return this;
    if(d < data) return left ? left->find(d) : nullptr;
    return right ? right->find(d) : nullptr;
}

int main()
{
    BSTNode n(4);
    n.insertInOrder(8);
    n.insertInOrder(2);
    n.insertInOrder(32);
    n.insertInOrder(0);
    cout << "size= " << n.getSize() << endl;
    auto node = n.find(32);
    if(node) cout << "element found=" << node->getData() << endl;

    return 0;
}
