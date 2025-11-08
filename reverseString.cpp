#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack <char> s;
    string st;
    cout << "Enter a string: ";
    cin >> st;
    
    string reverse = "";
    char ch;
    cout << "Original string: " << st << endl;
    for(int i=0; i<st.length(); i++)
    {
        ch = st[i];
        s.push(ch);
    }
    while(!s.empty())
    {
        reverse += s.top();
        s.pop();
    }
    cout << "Reversed string: " << reverse << endl;
}
