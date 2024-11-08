#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    bool valid = true;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ']')
        {
            if (!st.empty() and st.top() == '[')
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
            if (!st.empty() and st.top() == '{')

            {
                st.pop();
            }
            else
            {
                valid = false;
                break;
            }
        }

        else if (s[i] == ')')
        {
            if (!st.empty() and st.top() == '(')
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
        return false;
    }
    else
    {
        return valid;
    }
}

int main()
{
    string str = "[{()}]]]";
    if (isValid(str))
    {
        cout << "Valid String";
    }
    else
    {
        cout << "Invalid String";
    }

    return 0;
}