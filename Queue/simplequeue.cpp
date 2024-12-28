#include <iostream>
using namespace std;
const int SIZE = 5;

class Queue
{
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() : front(0), rear(-1) {}

    bool IsEmpty()
    {
        if (front > rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Insert(int val)
    {
        if (rear >= SIZE - 1)
        {
            cout << "Overflow" << endl;
        }

        arr[++rear] = val;
        cout << arr[rear] << endl;
    }
    int Remove()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty..." << endl;
            exit(1);
        }
        return arr[front++];
    }
};
int main()
{
    Queue q1;
    q1.Insert(2);
    q1.Insert(3);
    q1.Insert(3);
    q1.Insert(4);
    q1.Insert(4);
    q1.Insert(4);
    cout<<q1.Remove()<<endl;
    cout<<q1.Remove()<<endl;
    cout<<q1.Remove()<<endl;
    cout<<q1.Remove()<<endl;
    return 0;
}