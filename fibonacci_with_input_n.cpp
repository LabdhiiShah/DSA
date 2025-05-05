#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    int t1 = 0;
    int t2 = 1;
    cout<<t1<<" "<<t2;
    for(int i = 1; i<=n-2; i++)
    {
        int a;
        a = t1+t2;
        cout<<" "<<a;
        t1 = t2;
        t2 = a;
    } 
}