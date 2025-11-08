#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node(int d)
    {
        this-> data = d;
        this -> next = NULL;
    }

    ~node(){}
    
};

void insertH(node* &head, node* &tail, int d, int &n)
{
    if( head == NULL )
    {
        node* temp = new node(d);
        head = tail = temp;
        n++;
        return;
    }
    node *temp = new node(d);
    temp -> next = head;
    head = temp;
    n++;
}

void insertT(node* &head, node* &tail, int d, int &n)
{
    if( tail == NULL )
    {
        node* temp = new node(d);
        head = tail = temp;
        n++;
        return;
    }
    node* temp = new node(d);
    tail -> next = temp;
    tail = temp;
    n++;
}

void insertP(node* &head, node* &tail, int p, int d, int &n)
{
    // if head
    if( p == 1)
    {
        insertH(head,tail, d,n);
        return;
    }

    if(p < 1 || p > n+1)
    {
        cout << "Invalid position to insert!" << endl;
        return;
    }

    // random
    int cnt = 1;
    node* temp = head;
    while( cnt < p-1)
    {
        temp = temp -> next;
        cnt++;
    }

    if(temp -> next == NULL)
    {
        insertT(head,tail,d,n);
        return;
    }

    node *insert = new node(d);
    insert -> next = temp -> next;
    temp -> next = insert;
    n++;
 
}

void deleteP(node* &head, node* &tail, int p, int &n)
{
    if(p > n || p < 1)
    {
        cout << "Invalid position to delete!" << endl;
        return;
    }

    if( p == 1)
    {
        node *temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
        n--;
        return;
    }


    // mera

    else
    {
        node *current = head;
        int cnt = 1;
        while(cnt < p-1)
        {
            current = current -> next;
            cnt++;
        }
        node* todelete = current -> next;
        if(todelete == tail)
        {
            tail = current;
        }
        current -> next = todelete -> next;
        todelete -> next = NULL;
        delete todelete;
        n--;    
    }

    // sir ka (yt)
    // else
    // {
    //     node *current = head;
    //     node *previous = NULL;
    //     int cnt = 1;
    //     while(cnt < p)
    //     {
    //         previous = current;
    //         current = current -> next;
    //         cnt++;
    //     }
    //     previous -> next = current -> next;
    //     current -> next = NULL;
    //     delete current;
    //     n--;
    // }
    
}


void print(node* head)
{
    node *temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << "   ";
        temp = temp -> next;
    }
    cout << endl;
}

// int main()
// {
//     cout << "Hello World" << endl;
   
//     node *n1 = new node(20);
//     int nodecnt = 1;
//     node *head = n1;
//     node *tail = n1;
//     print(head);

//     cout << "Head: " << head -> data << endl;
//     cout << "Tail: " << tail -> data << endl;

//     insertH(head,tail,10,nodecnt);
//     print(head);
    
//     insertP(head,tail,2,30,nodecnt);
//     print(head);

//     insertT(head,tail,40,nodecnt);
//     print(head);

//     insertT(head,tail,100,nodecnt);
//     print(head);

//     deleteP(head,tail,3,nodecnt);
//     print(head);

//     insertT(head,tail,420,nodecnt);
//     print(head);

//     insertT(head,tail,1010,nodecnt);
//     print(head);

//     deleteP(head,tail,6,nodecnt);
//     print(head);

//     cout << "Head: " << head -> data << endl;
//     cout << "Tail: " << tail -> data << endl;

//     cout << "size of node: " << sizeof(node)*nodecnt << endl;

// }

int main()
{
    node* head = NULL;
    node* tail = NULL;
    int nodecnt = 0;

    while(true)
    {
        cout << "\n1. Insert at Head\n2. Insert at Tail\n3. Insert at Position\n";
        cout << "4. Delete at Position\n5. Print List\n6. Show Head & Tail\n";
        cout << "7. Size of List\n8. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        int value, pos;

        switch(choice)
        {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                insertH(head, tail, value, nodecnt);
                break;

            case 2:
                cout << "Enter value to insert at tail: ";
                cin >> value;
                insertT(head, tail, value, nodecnt);
                break;

            case 3:
                cout << "Enter position and value to insert: ";
                cin >> pos >> value;
                insertP(head, tail, pos, value, nodecnt);
                break;

            case 4:
                cout << "Enter position to delete: ";
                cin >> pos;
                deleteP(head, tail, pos, nodecnt);
                break;

            case 5:
                print(head);
                break;

            case 6:
                if(head) cout << "Head: " << head->data << endl;
                else cout << "Head: NULL\n";
                if(tail) cout << "Tail: " << tail->data << endl;
                else cout << "Tail: NULL\n";
                break;

            case 7:
                cout << "Current size: " << nodecnt << endl;
                break;

            case 8:
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
