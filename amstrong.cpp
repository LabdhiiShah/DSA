// a number that is equal to the sum of its own digits each raised to the power of the number of digits.


#include<iostream>
#include<cmath>
using namespace std;

int amstrong(int n,int p)
{
    int d=0,result=0,temp=n;
    while(temp!=0)
    {
        d = temp % 10;
        temp = temp / 10;
        result = result + pow(d,p);  // pow(x,y)    means x raised to power y
    }
    return result;
}


int main()
{
    int n,count=0,d=0;
    cout<<"enter a num: ";
    cin>>n;
    int temp = n;
    while(temp!=0)
    {
        d = temp % 10;
        temp = temp / 10;
        count++;
    }
    int result = amstrong(n,count);
    cout<<"amstrong: "<<result<<endl;
    if(n == result)
    {
        cout<<n<<" is an amstrong num!!"<<endl;
    }
    else
    {
        cout<<n<<" is not an amstrong num!!"<<endl;
    }
}