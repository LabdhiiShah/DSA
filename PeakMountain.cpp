#include <iostream>
using namespace std;

int peak(int arr[] , int n){
  int start = 0;
  int end = n-1;
  while(start <end){
     int mid=start + (end - start)/2;
        if(arr[mid] < arr[mid+1]){
            start = mid + 1;
        }
    else{
      end = mid;
    }
     mid=start + (end - start)/2;
    }
  return start;
}

int main(){
   int arr[11] = {2,4,5,6,7,8,6,4,2,1,0};

   int p = peak(arr,11);
   cout<< "Peak Value is at Index "<< p;
}

// ANOTHER SOLUTION 

#include <iostream>
using namespace std;

int peak(int arr[] , int n){
  int start = 0;
  int end = n-1;
  while(start <end){
     int mid=start + (end - start)/2;
    if(arr[mid+1] < arr[mid] && arr[mid] > arr[mid-1]){
      return mid;
    }
        if(arr[mid] < arr[mid+1]){
            start = mid + 1;
        }
    else{
      end = mid-1;
     // end = mid
    }
     mid=start + (end - start)/2;
    }
  return start;
}

int main(){
   int arr[11] = {2,4,5,6,7,8,6,4,2,1,0};

   int p = peak(arr,11);
   cout<< "Peak Value is at Index "<< p;
}
