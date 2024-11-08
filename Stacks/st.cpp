#include <iostream>
#include <stack>
using namespace std;

int largestElement(stack<int> &st)
{
    stack<int> temp;
    int largest, current;
    largest = st.top();
    while (!st.empty())
    {
        current = st.top();
        st.pop();
        temp.push(current);
        if (current > largest)
        {
            largest = current;
        }
    }
    while (!st.empty())
    {
        current = temp.top();
        st.push(current);
        temp.pop();
    }
    return largest;
}
int Smallest(stack<int> &st)
{
    stack<int> temp;
    int smallest, current;
    smallest = st.top();
    while (!st.empty())
    {
        current = st.top();
        st.pop();
        temp.push(current);
        if (current < smallest)
        {
            smallest = current;
        }
    }
    while (!st.empty())
    {
        current = temp.top();
        st.push(current);
        temp.pop();
    }
    return smallest;
}
int main()
{
    stack<int> st;
    st.push(67);
    st.push(43);
    st.push(101);
    st.push(99);
    st.push(12);
    int result = largestElement(st);
    cout << "largest : " << result << endl;
    int small= Smallest(st);
    cout<<"smallest:"<<small<<endl;

    return 0;
}