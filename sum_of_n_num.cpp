#include<iostream>
using namespace std;

int main()
{
    int n,sum=0;
    cout<<"enter a num: ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        sum += i;       //sum = sum + i; 
    }
    cout<<"sum: "<<sum<<endl;
}