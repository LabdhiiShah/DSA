#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter an no. : ";
    cin>>n;
    cout<<"dividors of n: ";
    for(int i=1 ;i<n;i++)
    {
        if(n % i == 0)
        {
            cout<<i<<" ";
        }
    }
}
