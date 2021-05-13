#include<bits/stdc++.h>
using namespace std;

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
// determine if the input string is valid.
bool check(char a, char b)
{
    if (a == '(' && b == ')')
        return true;
    else if (a == '{' && b == '}')
        return true;
    else if (a == '[' && b == ']')
        return true;
    return false;
}

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else if (st.empty())
            return false;
        else
        {
            if (!check(st.top(), s[i]))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string s = "([)]";
    cout << isValid("s");
    return 0;
}