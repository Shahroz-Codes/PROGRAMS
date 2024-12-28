#include <iostream>

using namespace std;
const int SIZE = 5;

class CirculeQueue
{
private:
    int arr[SIZE];
    int front, rear;

public:
    CirculeQueue() : front(SIZE - 1), rear(SIZE - 1) {}
    bool IsEmpty()
    {
        if (front == rear)
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
            cout << "Queue is Full" << endl;
            exit(1);
        }
        arr[rear] = val;
        cout << "inserted : " << arr[rear] << " | Front: " << front << " | Rear: " << rear << endl;
    }

    void Remove()
    {
        if (IsEmpty())
        {
            cout << "Queue is Empty";
            exit(1);
        }
        if (front ==(SIZE - 1))
        {
            front = 0;
            cout << "Deleted : " << arr[front] << " | Front: " << front << " | Rear: " << rear << endl;
        }
        else
        {
            front++;
            cout << "Deleted: " << arr[front] << " | Front: " << front << " | Rear: " << rear << endl;
        }
    }

    void Display()
    {
        if (front == rear)
        {
            cout << "Queue is Empty";
            exit(1);
        }
        int index = (front + 1) % SIZE; // Start from the first valid element
        while (index != (rear + 1) % SIZE)
        {
            cout << arr[index] << " --> ";
            index = (index + 1) % SIZE; // Move circularly
        }
        cout << "END" << endl;
    }
};
int main()
{

    CirculeQueue c;

    c.Insert(22);
    c.Insert(2);
    c.Insert(8);
    c.Insert(99);
    // cout << "Elements after insertion:";
    c.Display();
    c.Remove();
    c.Remove();
    c.Remove();
    // cout << "Elements after deletion:";
    c.Display();

    return 0;
}