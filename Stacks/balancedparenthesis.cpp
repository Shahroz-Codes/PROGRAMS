#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    int n = s.size();
    stack<char> st;
    bool valid = true;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                valid = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                valid = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                valid = false;
                break;
            }
        }
    }
    if (!st.empty())
    {
        valid = false;
    }
    return valid;
}
int main()
{
    string s = "[{()}]]";
    if (isValid(s))
    {
        cout << "VALID" << endl;
    }
    else
    {
        cout << "invalid";
    }
    return 0;
}