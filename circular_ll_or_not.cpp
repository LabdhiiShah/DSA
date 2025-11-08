#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }
};

void insert(node* tail, int p, int d)
{
    if(tail == NULL)
    {
        node* temp = new node(d);
        temp = temp -> next;
        tail = temp;
        return;
    }

    else
    {
        int cnt = 0;
        node* temp = tail -> next;
        node* toinsert = new node(d);
        while(cnt < p)
        {
            temp = temp -> next;
            cnt++;
        }
        toinsert -> next = temp -> next;
        temp -> next = toinsert;
        return;
        
    }
}

void print(node* tail)
{
    node* temp = tail -> next;
    do 
    {
        cout << temp -> data << "   ";
        temp = temp -> next;
    }while(temp != tail -> next);
    cout << endl;
}

bool check(node* head)
{
    // node* temp = tail;
    // if(tail -> next != NULL)
    // {
    //     return true;
    // }
    // return false;


    if(head == NULL)
    {
        return false;
    }

    node* temp = head -> next;
    while(temp != NULL && temp != head)
    {
        temp = temp -> next;
    }

    if(temp == head)
    {
        return true;
    }
    return false;
}

int main()
{
    node* n1 = new node(1);
    node* n2 = new node(1);
    n1 -> next = n2;
    node* tail = n2;
    // print(tail);
    // insert(tail,2,2);
    // print(tail);

    if(check(tail))
    {
        cout << "circular ll" << endl;
    }
    else
    {
        cout << "not a circular ll" << endl;
    }

}
