#include<iostream>
#include<cctype>
#include<string>
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;
    while(left < right)
    {
        while((left < right) && !isalnum(s[left])) left++;
        while((right > left) && !isalnum(s[right])) right--;

        if(tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    bool result = isPalindrome(s);
    if(result == true)
    {
        cout<<"palindrome";
    }
    else
    {
        cout<<"not a palindrome";
    }
}