#include <iostream>

using namespace std;
const int SIZE = 5;

class CirculeQueue
{
    private:
        int arr[SIZE];
        int back, fronts;
    public:
        CirculeQueue(): back(SIZE-1), fronts(SIZE-1) {}

        void  Insert(int x)
    {
      if (back == SIZE-1)
         back = 0;
      else
         back++;
       if (back == fronts)
       {
             cout << "Queue Overflow";
             exit(1);
       }
       arr[back] = x;
    }

    int Remove()
    {
     if (back == fronts)
     {
           cout <<"Queue underflow";
           exit(1) ;
      }
      if (fronts == SIZE-1)
         fronts = 0;
      else
         fronts++;
      return (arr[fronts]);
    }

    void Display()
    {
    if(back == fronts)
    {
        cout<<"queue empty."<<endl;
        exit(1);
    }


    int index=(fronts +1)%SIZE; ///start from 1st element

    while(index != (back +1 )%SIZE)
    {
        cout<<arr[index]<<" ";

        index=(index + 1)%SIZE;
    }
    cout<<endl;
    }


};
int main()
{

    CirculeQueue c;


    c.Insert(6);
    c.Insert(2);
    c.Insert(8);
    cout<<"Elements after insertion:";
    c.Display();
    c.Remove();
    c.Remove();
    cout<<"Elements after deletion:";
    c.Display();

    return 0;
}