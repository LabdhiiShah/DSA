#include<iostream>
using namespace std;

class queue
{
    public:
    int *arr;
    int size;
    int front, rear;

    queue(int size)
    {
        this -> size = size;
        arr = new int[size];
        front = rear = 0;
    }

    int enqueue(int element)
    {
        if(rear == size)
        {
            cout << "Overflow Condition\n";
            return -1;
        }

        arr[rear] = element;
        rear++;
        return element;
    }

    int dequeue()
    {
        if(front == rear)
        {
            cout << "Underflow Condition\n";
            return -1;
        }

        int element = arr[front];
        arr[front] = -1;
        front++;

        if(front == rear)
        {
            front = rear = 0;
        }
        return element;
    }
    
    int Front()
    {
        if(front == rear)
        {
            cout << "No elements found!!\n";
            return -1;
        }
        return arr[front];
    }
    
    int isEmpty()
    {
        if(front == rear)
        {
            return 1;   
        }
        return -1;
    }

};

int main()
{
    queue q(5);
    
    while(true)
    {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Front\n4.Empty?\n5.Exit\nEnter your choice: ";
        int n;
        cin >> n;
        switch(n)
        {
            case 1:
            {            
                int a;
                cout << "Enter the element to push: ";
                cin >> a;
                cout << q.enqueue(a) << endl;
                break;
            }
    
            case 2:
            {
                cout << q.dequeue() << endl;
                break;
            }
    
            case 3:
            {
                cout << q.Front() << endl;
                break;
            }
            case 4:
            {
                cout << q.isEmpty() << endl;
                break;
            } 
            case 5: exit(0);
        }
    }
    return 0;
}
