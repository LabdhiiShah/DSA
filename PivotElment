#include <iostream>
using namespace std;

// here both 11 and 0 is Pivot

//           11
//       8                       3
//  7                       2
//                    1          
//              0                      

// Code for 0 as pivot element

int pivot(int arr[], int n){
  int start = 0;
  int end = n-1;
  int mid = start + (end - start)/2;
  while(start < end){
    if(arr[mid] < arr[0]){
      end = mid;
    }
    else{
      start = mid + 1;
    }
    mid = start + (end - start)/2;
  }
  return start;
}

int main(){
  int arr[7] = {7,8,11,0,1,2,3};
  int pivotans = pivot(arr,7);
  cout << "Pivot element of the array is at Index " << pivotans << endl;
}

// Code for 11 as pivot element

int pivot(int arr[], int n){
    int start = 0;
    int end = n-1;
    int mid = start + (end - start)/2;
    while(start < end){
        if(arr[mid] < arr[end]){
            end = mid;
        }
        if(arr[mid] > arr[end]){
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
     return (start - 1 + n)%n;                // keyyyyy
}

int main(){
  int arr[7] = {7,8,11,0,1,2,3};
  int pivotans = pivot(arr,7);
  cout << "Pivot element of the array is at Index " << pivotans << endl;
}
