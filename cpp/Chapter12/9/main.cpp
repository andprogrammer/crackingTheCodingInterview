#include<iostream>
using namespace std;

template <typename T> class SmartPointer
{
    T *ref;
    unsigned *ref_count;

public:
    SmartPointer(T *pointer)
    {
        ref = pointer;
        ref_count = new unsigned(sizeof(unsigned));
        ref_count = 1u;
    }

    SmartPointer(SmartPointer<T> &smartPointer)
    {
        ref = smartPointer;
        ref_count = smartPointer.ref_count;
        ++(*ref_count);
    }

    SmartPointer<T>& operator=(SmartPointer<T> &smartPointer)
    {
        if(this == &smartPointer) return *this;
        remove();
        ref = smartPointer.ref;
        ref_count = smartPointer.ref_count;
        ++(*ref_count);
        return *this;
    }

    ~SmartPointer()
    {
        remove();
    }

    T getValue()
    {
        return *ref;
    }

protected:
    void remove()
    {
        if(*ref_count == 0) return;
        --(*ref_count);

        if(*ref_count == 0)
        {
            delete ref;
            delete ref_count;
            ref = nullptr;
            ref_count = nullptr;
        }
    }
};

int main()
{
    return 0;
}
