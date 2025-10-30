#include<iostream>
using namespace std;

class stack
{
    public:

    int top;
    int *arr;
    int size;

    stack(int size)
    {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    int push(int element)
    {
        if(top < size -1)
        {
            top++;
            arr[top] = element;
            return element;
        }
        else 
        {
            cout << "OVERFLOW CONDITION\n";
            return -1;
        }
    }

    int pop()
    {
        if(top >=0)
        {
            int val = arr[top];
            top--;
            return val;
        }
        else 
        {
            cout << "UNDERFLOW CONDITION\n";
            return -1;
        }
    }

    int peek()
    {
        if(top >= 0 && top < size)
        {
            // cout << "Peek element: " << arr[top] << endl;
            return arr[top];
        }
        else 
        {
            // cout << "STACK IS EMPTY\n";
            return -1;
        }
    }

    bool empty()
    {
        if(top == -1) return true;
        else return false;
    }
};

int main()
{
    stack s(5);
    cout << "\n1.Push\n2.Pop\n3.Peek\n4.Empty?\nEnter your choice: ";
    int n;
    cin >> n;
    switch(n)
    {
        case 1:
        {            
            int a;
            cout << "Enter the element to push: ";
            cin >> a;
            cout << s.push(a) << endl;
            break;
        }

        case 2:
            {
                cout << s.pop() << endl;
                break;
            }

        case 3:
            {
                cout << s.peek() << endl;
                break;
            }
        case 4:
        {
            cout << s.empty() << endl;
            break;
        }     
    }
    return 0;
}
