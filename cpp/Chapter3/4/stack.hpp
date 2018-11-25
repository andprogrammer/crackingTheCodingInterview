#include <utility>
#include <exception>


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

    void push(T &&value)
    {
        auto n = new Node(std::forward<T>(value), top);
        top = n;
        ++stackSize;
    }

    T &peek()
    {
        if (!top) throw StackIsEmptyException();
        return top->value;
    }

    T pop()
    {
        if (!top) throw StackIsEmptyException();
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

    class StackIsEmptyException : std::exception
    {
        virtual const char* what() const throw()
        {
            return "Stack is empty";
        }
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
