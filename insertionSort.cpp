#include<iostream>
using namespace std;

void insertion(int arr[],int n)
{
    for(int i=1; i<n; i++)
    { 
        int temp = arr[i];
        int j = i-1; 
        while(j >= 0 && arr[j] > temp)
        {
               arr[j+1] = arr[j];      // for shifting
               j--;
        }
        arr[j+1] = temp;        // after shifting placing the i th element
    }
}

int main()
{
    int arr[5] = {3,4,2,1,90};
    insertion(arr,5);
    for(int i=0; i<5; i++)
    {
        cout << arr[i] << "     ";
    }
}
