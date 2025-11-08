#include<iostream>
using namespace std;

class CircularQueue
{
    public:
    int *arr;
    int size, front, rear;
    CircularQueue(int size)
    {
        this -> size = size;
        arr = new int[size];
        front = rear = -1;
    }
    
    int enqueue(int element)
    {
        if((rear + 1) % size == front)
        {
            cout << "Overflow condition" << endl;
            return -1;
        }
        
        if(front == -1)
            front = 0;
            
        rear = (rear + 1) % size;
        arr[rear] = element;
        
        return element;
    }
    
    int dequeue()
    {
        if(front == -1)
        {
            cout << "Underflow\n";
            return -1;
        }
        
        int element = arr[front];
        arr[front] = -1;
        if(front == rear)
            front = rear = -1;
            
        else
            front = (front + 1) % size;
            
        return element;
    }

    int Front()
    {
        if(front == -1)
        {    
            cout << "No elements found!\n";
            return -1;
        }
            
        else
            return arr[front];
    }
    
    bool isEmpty()
    {
        return (front == -1);
    }
    
    void display()
    {
        if(front == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
    
        cout << "Queue elements: ";
        int i = front;
        while(true)
        {
            cout << arr[i] << " ";
            if(i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

};


int main()
{
    CircularQueue q(5);

    while (true)
    {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Front\n4.Empty?\n5.Display\n6.Exit\nEnter your choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int a;
                cout << "Enter element to enqueue: ";
                cin >> a;
                q.enqueue(a);
                break;
            }

            case 2:
                q.dequeue();
                break;

            case 3:
                cout << "Front element: " << q.Front() << endl;
                break;

            case 4:
                cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
                break;
                
            case 5:
                q.display();
                break;

            case 6:
                exit(0);
        }
    }
    return 0;
}





