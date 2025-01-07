#include<iostream>
using namespace std;

// Basic method (only finds integer and not decimal)

int sqrroot(int n){
    int count = 0;
    int ans = 0;

    for(int count = 0; count <= n; count++){
    ans = count * count;
    if(ans > n){
        return --count;
    }
    else if(ans == n){
        return count;
    }
  }
}

int main(){
    int n;
    cout << "Enter any no of which square root is required ";
    cin >> n;
    int ans = sqrroot(n);
    cout << "Square Root of " << n << " is " << ans;
}

// Using Binary Search (only finds integer and not decimal)

int sqrroot(int n){
    int start = 0;
    int end = n;
    int ans = 0;
    while(start<= end){
    int mid = start + (end - start)/2;

    if((long long)mid*mid == n){
        return mid;
    }

    if((long long)mid*mid < n){
        start = mid + 1;
         ans = mid;
    }

    else{
        end = mid - 1;
    }
  }
  return ans;
}

int main(){
    int n;
    cout << "Enter any no of which square root is required ";
    cin >> n;
    int ans = sqrroot(n);
    cout << "Square Root of " << n << " is " << ans;
    return 0;
}

// Perfect Method (with decimal no.)

int sqrroot(int n){
    int start = 0;
    int end = n;
    int ans = 0;
    while(start<= end){
    int mid = start + (end - start)/2;

    if((long long)mid*mid == n){
        return mid;
    }

    if((long long)mid*mid < n){
        start = mid + 1;
         ans = mid;
    }

    else{
        end = mid - 1;
    }
  }
  return ans;
}

double preciseSol(int n , int precision , int tempSol){

    double factor = 1;
    double ans = tempSol;

    for(int i = 0; i < precision ; i++){
        factor = factor / 10;
        for(double j = ans ; j*j < n ; j = j+factor){
            ans = j;
        }
     }
    return ans;
}

int main(){
    int n;
    cout << "Enter any no of which square root is required ";
    cin >> n;
    int tempSol= sqrroot(n);
    cout << "Square Root of " << n << " is " << preciseSol(n ,3 , tempSol);
    return 0;
}
