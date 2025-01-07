#include<iostream>
using namespace std;

void swapAlternate(int arr[],int n){
  for(int i=0; i<n; i+=2){
   if(i+1 < n){
     swap(arr[i] ,arr[i+1]);
   }
  }
  cout << "Array after Swapping" << endl;
  for(int i=0; i<n; i++){
    cout << arr[i] << " ";
  }
} 

int main(){
  int arr[6]={5,4,3,2,1,0};

  swapAlternate(arr,6);
}
