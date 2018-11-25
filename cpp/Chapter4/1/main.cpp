#include <iostream>
#include <deque>
#include <memory>
using namespace std;

template <typename T> struct Node
{
    T value;
    deque<weak_ptr<Node<T>>> childs;
    bool visited = false;

    Node(T v) : value(v) {}
    void addChild(shared_ptr<Node<T>> &child) { childs.push_back(child); }
    bool operator==(const Node<T> &other) { return value == other.value; }
};

template <typename T> bool isRoute(Node<T> &startNode, Node<T> &endNode)
{
    deque<Node<T>> neighbours;
    startNode.visited = true;
    neighbours.push_back(startNode);

    while(!neighbours.empty())
    {
        auto node = neighbours.front();
        neighbours.pop_front();
        for(auto &child : node.childs)
        {
            if(auto childLocked = child.lock())
            {
                if(childLocked && !(*childLocked).visited)
                {
                    if(*childLocked == endNode) return true;
                    childLocked->visited = true;
                    neighbours.push_back(*childLocked);
                }
            }
        }
    }
    return false;
}

int main()
{
    auto node1 = make_shared<Node<int>>(1);
    auto node2 = make_shared<Node<int>>(2);
    auto node3 = make_shared<Node<int>>(3);
    auto node4 = make_shared<Node<int>>(4);
    auto node5 = make_shared<Node<int>>(5);
    auto node6 = make_shared<Node<int>>(6);
    node1->addChild(node2);
    node1->addChild(node3);
    node2->addChild(node4);
    node2->addChild(node5);
    node3->addChild(node4);
    node3->addChild(node6);
    node4->addChild(node1);
    node5->addChild(node4);
    cout << boolalpha << isRoute(*node1.get(), *node6.get()) << endl;
    return 0;
}
