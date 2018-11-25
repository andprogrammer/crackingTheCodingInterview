#include <utility>
#include <exception>


template <typename T>
class Stack
{
public:
    Stack(size_t capacity) : capacity(capacity), top(nullptr), stackSize(0)
    {
        if(capacity <= 0) throw InvalidCapacityException();
    }

    Stack() : capacity(4), top(nullptr), stackSize(0)
    {
    }

    Stack(Stack &&other) : capacity(std::move(other.capacity)), top(std::move(other.top)), stackSize(std::move(other.stackSize))
    {
    }

    ~Stack()
    {
        while (!isEmpty())
            pop();
    }

    void push(T &&value)
    {
        if(isFull()) throw StackIsEmptyException();
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

    bool isFull() const
    {
        return stackSize == capacity;
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

    class InvalidCapacityException : std::exception
    {
        virtual const char* what() const throw()
        {
            return "Invalid capacity";
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
    size_t capacity;
    size_t stackSize;
};
