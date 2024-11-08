#include<iostream>
using namespace std;
const int Size=10;
class CircularQueue
{
private:
    int Front,Back;
    int Queue[Size];
public:
    CircularQueue():Front(0),Back(-1){}
    CircularQueue(int fr,int rr):Front(fr),Back(rr){}
    bool IsEmpty()
    {
        if(Front==-1)
            return true;
        else
            return false;
    }
    bool IsFull()
    {
        if((Back==Size-1 && Front==0))
            return true;
        else
            return false;
    }
    int Add(int val)
    {
        if(IsFull())
            cout<<"Queue is Full "<<endl;
        else
            Queue[++Back]=val;
    }
    int Delete()
    {
        if(IsEmpty())
            cout<<"Queue is Empty "<<endl;
        else
            return Queue[Front++];
    }
    void Print()
    {
        for(int i=Front; i<=Back; i++)
        {
            cout<<"The Value is = "<<Queue[i]<<endl;
        }
    }
};
int main()
{
    CircularQueue q1;
    q1.Add(1);
    q1.Add(2);
    q1.Add(3);
    q1.Add(4);
    q1.Add(5);
    q1.Print();
    return 0;
}