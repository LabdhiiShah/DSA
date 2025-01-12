#include<iostream>
using namespace std;

int merge(int a[],int n,int b[],int m,int c[]){
int i=0;
int j=0;
int k=0;
while(i<n && j<m){
    if(a[i]< b[j]){
        c[k]=a[i];
        k++;
        i++;
    }
    else{
        c[k]=b[j];
        k++;
        j++;
    }
}

while(i<n){
    c[k]=a[i];
    k++;
    i++;
}
while(j<m){
    c[k]=b[j];
    k++;
    j++;
}

cout<<"Merged Array: ";
for(int i=0;i<(n+m);i++){
    cout<<c[i]<<"   ";
}

}

int main(){
int a[5]={2,4,5,6,8};
int b[3]={3,4,9};
int c[8]={0};

merge(a,5,b,3,c);

}
