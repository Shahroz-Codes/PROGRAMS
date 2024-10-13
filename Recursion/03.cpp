#include<iostream>
using namespace std;
int fact(int n){
    if(n==0){
        return 1;
    } else {
        //recursive call
        int x,y;
        x = n-1;
        y = fact(x);
        return n*y;
    }
}
int main()
{
    int n;
    cin>>n;
    cout<<n;
    //sum of array by recursion .. no of...local array pehle banalem... agr size 0 hojai to return qwo index... or + jo call de raha hai... dry run banana hai.. find largest value from array using recursion... also smallest
   return 0;
}