#include <iostream>
using namespace std;

const int SIZE = 10;
class MyArray
{
private:
public:
    void bubbleSort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    void selectionSort(int arr[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
    }
    void insertionSort(int arr[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            int current = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > current)
            {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = current;
        }
    }
    void MergeSort(int arr[], int low, int high)
    {

        if (low < high)
        {
            int mid = (low + high) / 2;
            MergeSort(arr, low, mid);
            MergeSort(arr, mid + 1, high);
            Merge(arr, low, mid, high);
        }
    };
    void Merge(int arr[], int low, int mid, int high)
    {
        int n1 = mid - low + 1;
        int n2 = high - mid;
        int left[n1], right[n2];

        for (int i = 0; i < n1; i++)
        {
            left[i] = arr[low + i];
        }
        for (int i = 0; i < n2; i++)
        {
            right[i] = arr[mid + 1 + i];
        }
        int i = 0, j = 0, k = low;
        while (i < n1 && j < n2)
        {
            if (left[i] <= right[j])
            {
                arr[k] = left[i];
                k++;
                i++;
            }
            else
            {
                arr[k] = right[j];
                k++;
                j++;
            }
        }
        while (i < n1)
        {
            arr[k++] = left[i++];
        }
        while (j < n2)
        {
            arr[k++] = right[j++];
        }
    }
    void QuickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pivot = Partition(arr, low, high);
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
    void ShowArray(int arr[], int SIZE)
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << "index : " << i << " value : " << arr[i] << endl;
        }
    }
};

int main()
{
    MyArray A;
    int arr[SIZE] = {30, 60, 80, 40, 20, 90, 10, 100, 50, 70};
    // A.MergeSort(arr, 0, SIZE-1);
    // A.bubbleSort(arr,SIZE);
    // A.ShowArray(arr, SIZE);
    A.QuickSort(arr,0,SIZE-1);
    A.ShowArray(arr, SIZE);

    return 0;
}