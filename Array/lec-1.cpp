#include <iostream>
using namespace std;

const int SIZE =100;
class MyArray
{
    private:
        int arr[SIZE];
        int index;
    public:
        MyArray() : index(0) {}
        void Insert(int val)
        {
            if(index >SIZE-1)
            {
                cout<<"Array full"<<endl;
                return;
            }
            arr[index++] = val;
        }
        void Showarray()
        {
            for(int i = 0; i < index; i++)
            {
                cout<<"value at "<<i<<" index is "<<arr[i]<<endl;
            }
        }
        /**void SelectionSort()
        {

        }*/
        void BubbleSort()
        {
            for(int i = 0; i < index-1; i++)
            {
                for(int j = 0; j < index-1-i; j++)
                {
                    if(arr[j] > arr[j+1])
                        swap(arr[j], arr[j+1]);
                }
            }
        }
        int BinarySearch(int val)
        {
            int start = 0, last = index-1, mid;
            while(start <= last)
            {
                mid = (start + last)/2;
                if(arr[mid] == val)
                    return mid;
                else if(arr[mid] > val)
                    last = mid - 1;
                else
                    start = mid + 1;
            }
            return -1;
        }

};
int main()
{
    MyArray obj;
    obj.Insert(12);
    obj.Insert(24);
    obj.Insert(-98);
    obj.Insert(76);
    obj.Insert(-2);
    obj.Showarray();

    cout<<endl;
    obj.BubbleSort();
    obj.Showarray();

    /**cout<<endl;
    obj.SelectionSort();
    obj.Showarray();
    **/

    /**int ind = obj.LinearSearch(-98);
    if(ind == -1)
        cout<<"value not found"<<endl;
    else
        cout<<"Value found at "<<ind<<" index"<<endl;
    **/

    int ind = obj.BinarySearch(24);
    if(ind == -1)
        cout<<"\nValue not found"<<endl;
    else
        cout<<"\nValue founded at "<<ind<<" index"<<endl;

    return 0;
}