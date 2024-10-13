#include <iostream>
using namespace std;

void show(int c)
{
    cout<<"C is "<<c<<endl;
    if(c<=5)
        show(++c);
}
int main()
{
    show(1);
    return 0;
}