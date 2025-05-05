#include<iostream>
using namespace std;

void reverse(int arr[], int n)
{
    int start=0;
    int end = n-1;
    while(start < end)
    {
            swap(arr[start], arr[end]);
            start++;
            end--;
        
    }
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

}

int main()
{
    int arr[5]={5,4,3,2,1};
    cout<<"reversed array: "<<endl;
    reverse(arr,5);
}