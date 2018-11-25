#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <utility>

#include "stack.hpp"
using namespace std;

template<typename T>
class MyQueue
{
    Stack<T> newValues;
    Stack<T> reversedValues;

public:
    void add(T &&value)
    {
        newValues.push(forward<T>(value));
    }

    T& peek()
    {
        if(reversedValues.isEmpty()) move(newValues, reversedValues);
        return reversedValues.peek();
    }

    T remove()
    {
        if(reversedValues.isEmpty()) move(newValues, reversedValues);
        return reversedValues.pop();
    }

    bool isEmpty() const
    {
        return newValues.isEmpty() && reversedValues.isEmpty();
    }

private:
    void move(Stack<T> &source, Stack<T> &destination)
    {
        while(!source.isEmpty()) destination.push(source.pop());
    }
};

int main()
{
    cout << boolalpha;

    MyQueue<int> q;
    cout << q.isEmpty() << endl;
    q.add(132);
    cout << q.isEmpty() << endl;
    cout << q.remove() << endl;
    cout << q.isEmpty() << endl;
    q.add(256);
    q.add(16);
    q.add(32);
    q.add(64);
    q.add(7);
    while(!q.isEmpty()) cout << q.remove() << " ";
    cout << endl;
}
