#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

int push(node* &head, int d)
{
    if(head == NULL)
    {
        node* n1 = new node(d);
        head = n1;
        return d;
    }
    node* temp = new node(d);
    temp -> next = head;
    head = temp;
    return d;
}

int pop(node* &head)
{
    if(head == NULL) 
    {
        cout << "UNDERFLOW Condition\n";
        return -1;
    }
    else
    {
        int n = head -> data;
        head = head -> next;
        return n;
    }

}

void print(node* &head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << "   ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    node* head = NULL;

    while(true)
    {
        int choice;
        cout << "\n1.Push\n2.Pop\n3.Empty\n4.Peek\n5.Display\n6.Exit\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter the element you want to add: ";
                int n;
                cin >> n;
                cout << push(head,n) << endl;
                break;
            
            case 2:cout << pop(head) << endl;
                break;

            case 3: 
                if(head == NULL)
                    cout << "Stack is empty\n";
                else
                    cout << "Stack is not Empty\n";
                break;

            case 4: cout << head -> data << endl;
                break;

            case 5: print(head);
                break;

            case 6: exit(0);
        }
    }
    return 0;
}
