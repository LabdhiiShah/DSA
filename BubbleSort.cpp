#include<iostream>
using namespace std;

void bubblesort(int arr[],int n){
for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
        }
      }
    }
cout<<"Sorted array: ";
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
 }
}

int main(){
int arr[6]={6,19,30,26,12,7};
bubblesort(arr,6);
}
