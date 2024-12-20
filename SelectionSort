#include<iostream>
using namespace std;

void sortedarr(int arr[],int n){
    for(int i=0;i<n;i++){
        int minIndex = i;
        for(int j=i+1;j<n;j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
int arr[5]={7,3,2,1,9};
sortedarr(arr,5);
}
