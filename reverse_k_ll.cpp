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
   

node* reversek(node* head, int k)
{
    //if one node
    if(head == NULL)
    {
        return head;
    }

    node* prev = NULL;
    node* curr = head;
    node* next = NULL;
    int cnt = 0;

    while(cnt < k && curr != NULL)
    { 
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }
    
    if(next != NULL)
    {
        cout << "recursion:: \n";
        cout << "nnext ka data" << next -> data << endl;
        head -> next = reversek(next,k);
    }

    return prev;
}

void print(node* head, int n)
{
    node* temp = head;
    cout << endl << "Data of nodes: " << endl;
    while(temp != NULL)
    {
        cout << temp -> data << "   ";
        temp = temp -> next;
    }
    cout << endl << "no.of nodes: " << n << endl;
}
int main()
{
    cout << "Hello World main" << endl;  
    node* n1 = new node(1);
    int n = 1;
    node* head = n1;
    node* tail = n1;
    print(head,n);

    // node* n2 = new node(2);
    // node* n3 = new node(3);
    // node* n4 = new node(4);
    // node* n5 = new node(5);
    // node* n6 = new node(6);

    // n1->next = n2;
    // n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    // n5->next = n6;
    // n = 6;
    // tail = n6;
    print(head,n);
    head = reversek(head,4);
    print(head,n);
}
