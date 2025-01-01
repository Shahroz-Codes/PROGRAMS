#include <iostream>
using namespace std;

 void QuickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pivot =  Partition(arr, low, high);
            QuickSort(arr, low, pivot - 1);
            QuickSort(arr, pivot + 1, high);
        }
    }
    int Partition(int arr[], int low, int high)
    {
        int pivot = arr[low];
        int i = low + 1;
        int j = high;

        while (i <= j)
        {
            while (i <= high && arr[i] <= pivot)
                i++;
            while (j >= low && arr[j] > pivot)
                j--;
            if (i <= j)
                swap(arr[i], arr[j]);
        }

        swap(arr[low], arr[j]);
        return j;
    }

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 2, 8, 3, 1, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    QuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
