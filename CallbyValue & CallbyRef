#include <iostream>
using namespace std;

// FOR A VARIABLE

// Using void so that it doesn't return anything i.e upgraded value
void callbyvalue1(int a) {
  a += 2;
  cout << "Value of a in funtion  callbyvalue1 " << a << endl;
}

// As int datatype is used it'll return the upgraded value
int callbyvalue2(int a) {
  a += 2;
  return a;
}

// In this, address is given so it'll directly change the value in it's stored location
int callbyref(int &a) {
  a += 4;
  return a;
}

int main() {
  int a = 0;

  cout << "Value of a before calling any function " << a << endl;

  callbyvalue1(a);
  cout << "Value of a in main after calling value function callbyvalue1 " <<
  a
       << endl;

  int val = callbyvalue2(a);
  cout << "Value of a in main after calling funtion callbyvalue2 " << val
       << endl;

  int ref = callbyref(a);
  cout << "Value of a in main after calling  callbyref function " << ref
       << endl;

  cout << "Final Value of a in main after calling each function " << a <<
  endl;
}

-----------------------------------------------------------------------

#include <iostream>
using namespace std;

//  FOR AN ARRAY

void callbyvalue(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = arr[i] + 10;
  }

  cout << "Value of Array after calling function callbyvalue " << endl;
  for (int i = 0; i < n; i++) {
    cout << arr[i] << endl;
  }
}

void callbyref(int (&arr) [6]){
  for (int i = 0; i < 6; i++) {
    arr[i] = arr[i] * 2;
  }

  cout << "Value of Array after calling function callbyref " << endl;
  
  for (int i = 0; i < 6; i++) {
    cout << arr[i] << endl;
  }
}

// here everytime u call funtion it'll upgrade the original value of array if any such code written as it is directly connected with the array's location

int main(){
  int a[6]={1,2,3,4,5,6};
   cout << "Original Value of Array" << endl;
  for (int i = 0; i < 6; i++){
  cout << a[i] << endl;
  }

  callbyvalue(a,6);
  cout << "Value of Array after calling function callbyvalue in main " << endl;
  for (int i = 0; i < 6; i++) {
    cout << a[i] << endl;
  }

  callbyref(a);
  cout << "Value of Array after calling function callbyref in main " << endl;
  for (int i = 0; i < 6; i++) {
    cout << a[i] << endl;
  } 
}
