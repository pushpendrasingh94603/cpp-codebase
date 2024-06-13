#include <iostream>
#include <stack>
using namespace std;
class Stack
{
public:
    // properties
    int top;
    int size;
    int *arr;
    // behaviour
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        this->top = -1;
    }

    void push(int number)
    {
        if ((size - top) > 1)
        {
            top++;
            arr[top] = number;
        }
        else
        {
            cout << "\nWARNING: Stack overflow !\n";
        }
    }

    void pop()
    {
        if (top >= 0)
            top--;
        else
            cout << "\nWARNING: Stack underflow !\n";
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "\nWARNING: Stack is empty\n";
            return -1;
        }
    }
    bool isEmpty()
    {
        return (top >= 0) ? false : true;
    }
};
int main()
{
    cout << "\nhello\n";
    Stack st(5);
    st.push(1);
    st.pop();
    st.peek();
    cout << "\n------------\n";
    cout << st.peek();

    // stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.pop();
    // cout<<s.size();
    return 0;
}