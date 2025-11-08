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

    ~node()
    {
        cout << "memory free for data -> " << data << endl;
        if(this -> next != NULL)
        {
            next = NULL;
            delete next;
        }
    }
};

void insertH(node* &head, node* &tail, int d, int &n)
{
    n = 1;
    if( head == NULL )
    {
        node* temp = new node(d);
        head = tail = temp;
    }
    else
    {
        node* temp = new node(d);
        temp -> next = head;
        head = temp;
    }
    n++;
}

void insertT(node* &head, node* &tail, int d, int &n)
{
    if(tail == NULL)
    {
        node* temp = new node(d);
        head = tail = temp;
    }
    else
    {
        node* temp = new node(d);
        tail -> next = temp;
        tail = temp;
    }
    n++;
}

void insertP(node* &head, node* &tail, int d, int p, int &n)
{
    if(p == 1)
    {
        insertH(head,tail,d,n);
        return;  
    }

    int cnt = 1;
    node* temp = head;
    while(cnt < p)
    {
        temp = temp -> next;
        cnt++;
    }

    if(temp == NULL)
    {
        insertT(head, tail, d, n);
        return;
    }
    node* toinsert = new node(d);
    toinsert -> next = temp -> next;
    temp -> next = toinsert;
    n++;

}

void deleteV(node* &head, node* &tail, int d, int &n)
{
    if(head == NULL)
    {
        cout << "empty linked list!" << endl;
        return;
    }

    else if(head -> data == d)
    {
        // node* temp = head;
        // head -> next = NULL;
        // temp = temp-> next;
        // head = temp;
         
        node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        n--;
        return;
    }

    else
    {
        node* temp = head;
        while(temp -> next -> data != d)
        {
            temp = temp -> next;
        }
        node* todelete = temp -> next;
        temp -> next = todelete -> next;
        todelete -> next = NULL;
        delete todelete;
        n--;
        return;
    }
    // node* temp = head;
    // while(temp -> data -> next -> data != d)
    // {
    //     temp = temp -> next;
    // }
}

// void reverse(node* & head, node* &tail, int &n)
// {
//     node* h = head;
//     node* t = tail;
//     int k = n/2;
//     int cnt = 1;
//     // while( )
//     while(k)
//     {
//         t -> next = head -> next;
//         cout << t -> data << "      ";
//         h -> next = NULL;
//         t = t -> next;
//         // k--;
//     }

    
//     // cout << t -> data << "      " << t -> next ->data << "      ";
//     // cout << h -> data << endl;

// }



void reverse_iteratively(node* &head, node* &tail)
{
    node* prev = NULL;
    node* current = head;
    node* forward = NULL;
    while(current != NULL)
    {
        forward = current -> next;
        current -> next = prev;
        prev = current;
        current = forward;
    }
    head = prev;
} 


void reverse_recursively(node* &head, node* current, node* prev)
{
    if(current == NULL)
    {
        head = prev;
        return;
    }

    
    node* forward = current -> next;
    current -> next = prev;
    reverse_recursively(head,forward,current);
    
}

node* reverse(node* head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    node* chotaHead = reverse(head -> next);

    head -> next -> next = head;
    head -> next = NULL;

    return chotaHead;
}


void print(node* &head, int &n)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << "   ";
        temp = temp -> next;
    }
    cout << endl << "no.of nodes: " << n << endl;
}


int main()
{
    cout << "hello babbyyy\n";
    node* n1 = new node(2);
    node* head = n1;
    node* tail = n1;

    int n = 1;

    insertH(head, tail, 1, n);
    print(head,n);
    
    insertP(head, tail, 3, 3, n);
    print(head,n);

    insertT(head, tail, 4, n);
    print(head,n);

    // deleteV(head, tail, 3, n);
    // print(head,n);

    cout << endl << "REVERSED recursively: "<< endl;

    reverse_recursively(head,head,NULL);
    print(head,n);

    cout << endl << "REVERSED iteratively: "<< endl;

    reverse_iteratively(head,tail);
    print(head,n);
    
    cout << endl << "REVERSED: "<< endl;

    node* cH = reverse(head);
    print(cH,n);

    return 0;
}
