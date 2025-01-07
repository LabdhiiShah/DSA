//Reverse the Array

#include<iostream>
using namespace std;

void reverse_arr(int arr[],int n){
int start=0;
    int end=n-1;
    while(start<=end){
        swap(arr[start],arr[end]);
            start++;
            end--;
  }
    cout<<"Reversed Array: ";
   for(int i=0;i<n;i++){
    cout<<arr[i]<<"   ";
}
}

int main(){
    int a[5];
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    cout<<"Printing the Entered Array: ";
    for(int i=0;i<5;i++){
        cout<<a[i]<<"   ";
    }
    reverse_arr(a,5);
}

Reverse an Array after  m position


#include<iostream>
using namespace std;

void reverse_arr(int arr[],int n,int key){
int start=key;
    int end=n-1;
    while(start<=end){
        swap(arr[start],arr[end]);
            start++;
            end--;
  }
    cout<<"Reversed Array: ";
   for(int i=0;i<n;i++){
    cout<<arr[i]<<"   ";
}

}

int main(){
    int a[5];
    for(int i=0;i<5;i++){
        cin>>a[i];
    }
    cout<<"Printing the Entered Array: ";
    for(int i=0;i<5;i++){
        cout<<a[i]<<"   ";
    }
    reverse_arr(a,5,1);
}
