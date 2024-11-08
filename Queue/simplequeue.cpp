#include<iostream>
#include<queue>
using namespace std;
const int Size=100;
class Queue
{
private:
    int qu[Size];
    int Front,Back;
public:
    Queue():Front(0),Back(-1){}
    Queue(int fr,int rr):Front(fr),Back(rr){}
    bool Isfull()
    {
        if(Back>=Size)
            return true;
        else
            return false;
    }
    bool Isempty()
    {
        if(Back==-1)
            return true;
        else
            return false;
    }
    int Enqueue(int no)
    {
        if(Isfull())
            cout<<"Queue is Full "<<endl;
        else
            qu[++Back]=no;
    }
    int Dequeue()
    {
        if(Isempty())
            cout<<"Queue is Empty "<<endl;
        else
            return qu[Front++];
    }
    void Print()
    {
        for(int i=Front; i<=Back; i++)
        {
            cout<<"The Value is : "<<qu[i]<<endl;
        }
    }
};
int main()
{
    Queue q1;
    q1.Enqueue(1);
    q1.Enqueue(2);
    q1.Enqueue(3);
    q1.Enqueue(4);
    q1.Enqueue(5);
    q1.Enqueue(6);
    q1.Dequeue();
    q1.Dequeue();
    q1.Print();
    queue<int>q2;
    q2.push(1);
    q2.push(2);
    q2.push(4);
    q2.push(5);
    q2.push(8);
    bool result=q2.empty();
    cout<<"Queue is not Empty because result is = "<<result<<endl;
    while(!q2.empty())
    {
        cout<<"The Value is = "<<q2.front()<<endl;
        q2.pop();
    }
    return 0;
}