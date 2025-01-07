#include<iostream>
using namespace std;

// Here in the array all the element are occured twice accept except 0 hence it is unique element

 int main(){
   int arr[7] = {2,4,6,0,2,6,4};
   int ans = 0;

   for(int i=0; i<7; i++){
     ans = ans^arr[i];
   }

   cout << "Unique Element: " << ans;
 }
