#include<iostream>
using namespace std;

void ohkkk(int a[],int n){
int nonZero=0;
for(int i=0;i<n;i++){
    if(a[i]!=0){
        swap(a[i],a[nonZero]);
        nonZero++;
    }
}

cout<<"Array: ";
for(int i=0;i<n;i++){
    cout<<a[i]<<"   ";
}
}

int main(){
    int a[5]={0,12,0,29,0};
    ohkkk(a,5);
}
