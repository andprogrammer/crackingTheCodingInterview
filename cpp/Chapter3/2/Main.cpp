//prawie w pelni z rozwiazan
#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <cstdlib>
#include <utility>
using namespace std;


template <typename T>
class Stack
{
public:
    Stack() : top(nullptr), stackSize(0)
    {
    }

    Stack(Stack &&other) : top(std::move(other.top)), stackSize(std::move(other.stackSize))
    {
    }

    ~Stack()
    {
        while (!isEmpty())
            pop();
    }

    template <typename U>
    void push(U &&value)
    {
        auto n = new Node(std::forward<U>(value), top);
        top = n;
        ++stackSize;
    }

    T &peek()
    {
        if (!top)
            throw StackIsEmptyException();
        return top->value;
    }

    T pop()
    {
        if (!top)
            throw StackIsEmptyException();
        auto value(std::move(top->value));
        auto n = top;
        top = n->next;
        delete n;
        --stackSize;
        return value;
    }

    bool isEmpty() const
    {
        return !top;
    }

    size_t size() const
    {
        return stackSize;
    }

    class StackIsEmptyException
    {
    };

private:
    struct Node
    {
        Node(T &&v, Node *n): value(std::move(v)), next(n)
        {
        }

        Node(const T &v, Node *n): value(v), next(n)
        {
        }

        T value;
        Node *next;
    };

    Node *top;
    size_t stackSize;
};

template<typename T>
class StackMin
{
    Stack<T> stack;
    Stack<T> minStack;

public:
    void push(T &&value)
    {
        if(minStack.isEmpty() || value <= minStack.peek()) minStack.push(value);
        stack.push(move(value));
    }

    T& peek()
    {
        return stack.peek();
    }

    T pop()
    {
        T value = stack.pop();
        if(value == minStack.peek()) minStack.pop();
        return value;
    }

    T& min()
    {
        return minStack.peek();
    }

    bool isEmpty() { return stack.isEmpty(); }
};

int main()
{
    StackMin<int> s;
    s.push(2);
    s.push(256);
    s.push(16);
    s.push(32);
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.min() << endl;
};
