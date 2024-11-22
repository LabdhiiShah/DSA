#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
  int start = 0;
  int end = n - 1;
  int mid = (start + end) / 2;

  while (start <= end) {
    if (arr[mid] == key) {
      return mid;
    }
    if (arr[mid] >= key) {
      end = mid - 1;

    } else {
      start = mid + 1;
    }
     mid = start + (end - start) / 2;
  }
  return -1;
}

int main() {
  int even[6] = {1, 2, 4, 8, 8, 8};
  int odd[5] = {1,1,1,2,2};

  int evenindex = binarySearch(even, 6, 10);
  cout << "Index of 10 is " << evenindex << endl;

  int oddindex = binarySearch(odd, 5, 17);
  cout << "Index of 17 is " << oddindex << endl;
}
