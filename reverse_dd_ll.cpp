#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* prev;

    node(int d)
    {
        this -> data = d;
        this -> next = NULL;
        this -> prev = NULL;
    }
};

node* reverse(node* head)
{
    // NULL <- 1 <=> 2 <=> 3 <=> 4 <=> 5 <=> 6 -> NULL
    // here 2 ka next is pointing to 3 i.e 3 is ahead of 2 
    // NULL <- 6 <=> 5 <=> 4 <=> 3 <=> 2 <=> 1 -> NULL
    // but after reversing it 3 ka next is pointing to 2 
    // it means 2 is ahead of 3
    // so for that purpose to link them 
    // instead of 2 ka next pointing to 3
    // we need 2 ka prev to point 3 


    node* temp = NULL;
    node* curr = head;
    while(curr != NULL)
    {
        temp = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = temp;
        curr = curr -> prev;
    }

    if(temp != NULL)
    {
        head = temp -> prev;
    }

    return head;
}

void print(node* head)
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
    node* n1 = new node(1);
    node* head = n1;
    node* tail = n1;
    node* n2 = new node(2);
    node* n3 = new node(3);
    node* n4 = new node(4);
    node* n5 = new node(5);
    node* n6 = new node(6);

    n1 -> next = n2;
    n2 -> prev = n1;
    n2 -> next = n3;
    n3 -> prev = n2;
    n3 -> next = n4;
    n4 -> prev = n3;
    n4 -> next = n5;
    n5 -> prev = n4;
    n5 -> next = n6;
    n6 -> prev = n5;
    tail = n6; 
    print(head);
    head = reverse(head);
    print(head);
}
