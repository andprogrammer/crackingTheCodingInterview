#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <utility>

#include "stack.hpp"
using namespace std;

template<typename T>
class StackOfPlates
{
    Stack<Stack<T>> stacks;
    size_t singleStackCapacity;

public:
    StackOfPlates(size_t singleStackCapacity) : singleStackCapacity(singleStackCapacity)
    {
    }

    void push(T &&value)
    {
        if(stacks.isEmpty() || stacks.peek().isFull()) stacks.push(Stack<T>(singleStackCapacity));
        stacks.peek().push(forward<T>(value));
    }

    T& peek()
    {
        return stacks.peek().peek();
    }

    T pop()
    {
        T popValue = stacks.peek().pop();
        if(stacks.peek().isEmpty()) stacks.pop();
        return popValue;
    }

    bool isEmpty() const
    {
        return stacks.isEmpty();
    }

    bool isFull() const
    {
        return stacks.isFull();
    }

    size_t size() const
    {
        return stacks.size();
    }
};

int main()
{
    cout << boolalpha;

    StackOfPlates<int> s(4);
    cout << s.isEmpty() << endl;
    s.push(132);
    cout << s.isEmpty() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    s.push(256);
    s.push(16);
    s.push(32);
    s.push(64);
    s.push(888);
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.peek() << endl;
}
