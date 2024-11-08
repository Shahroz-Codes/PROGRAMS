#include <iostream>
#include <stdlib.h>
using namespace std;
const int SIZE = 5;
class CircularQueue
{
private:
    int arr[SIZE];
    int front;
    int rear;

public:
    CircularQueue() : front(SIZE - 1), rear(SIZE - 1) {}
    void Insert(int val)
    {
        if (rear == SIZE - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        if (rear == front)
        {
            cout << "Queue Overflow ";
            exit(1);
        }
        else
        {
            arr[rear] = val;
        }
    }
     bool IsEmpty()
    {
        if (front == rear)
            return true;
        else
            return false;
    }
    int Remove()
    {
        if (IsEmpty() == true)
        {
            cout << "Queue under flow" << endl;
            exit(1);
        }
        if (front == SIZE - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    return arr[front];

    }
   
};
int main()
{
    CircularQueue q;
    q.Insert(11);
    q.Insert(32);
    q.Insert(1);
    q.Insert(51);
    while (!q.IsEmpty())
    {
        cout << "Deleted Value is " << q.Remove() << endl;
    }
    // cout << "Value is " << q.Remove() << endl;
    // cout << "Value is " << q.Remove() << endl;
    // cout << "Value is " << q.Remove() << endl;
    // cout << "Value is " << q.Remove() << endl;
    // cout << "Value is " << q.Remove() << endl;
    return 0;
}