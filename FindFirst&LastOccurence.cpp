#include <iostream>
using namespace std;

int firstocc(int arr[], int n, int key) {
  int start = 0;
  int end = n - 1;
  int ans = -1;

  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (arr[mid] == key) {
      ans = mid;
      end = mid - 1;
    }
    if (arr[mid] >= key) {
      end = mid - 1;

    } else {
      start = mid + 1;
    }
     mid = start + (end - start) / 2;
  }
  return ans;
}

int lastocc(int arr[], int n, int key) {
  int start = 0;
  int end = n - 1;
  int ans = -1;

  int mid = start + (end - start) / 2;

  while (start <= end) {
    if (arr[mid] == key) {
      ans = mid;
      start = mid + 1;
    }
    if (arr[mid] > key) {
      end = mid - 1;

    } else {
      start = mid + 1;
    }
     mid = start + (end - start) / 2;
  }
  return ans;
}

int main() {
  int even[6] = {1, 2, 4, 8, 8, 8};
  int odd[5] = {1,1,1,2,2};

  cout << "First Occurence of 8 at Index " << firstocc(even, 6, 8) << endl;
  cout << "Last Occurence of 8 at Index " << lastocc(even, 6, 8) << endl;

  cout << "First Occurence of 2 at Index " << firstocc(odd, 5, 2) << endl;
  cout << "Last Occurence of 2 at Index " << lastocc(odd, 5, 2) << endl;
  
  cout << "Occurence of 8 in 1st array " << ((lastocc(even, 6, 8)-firstocc(even, 6, 8))+1) <<endl; // TOTAL NO.OF OCCURENCES
}
