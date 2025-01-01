#include <iostream>
using namespace std;

class ARRAY
{
private:
    int *arr;
    int SIZE;

public:
    // Constructor
    ARRAY(int SIZE)
    {
        this->SIZE = SIZE;
        arr = new int[SIZE];
    }

    // Destructor
    ~ARRAY()
    {
        delete[] arr;
    }

    // Function to input array elements
    void inputArray()
    {
        cout << "Enter array elements: ";
        for (int i = 0; i < SIZE; i++)
        {
            cin >> arr[i];
        }
    }

    // Function to display array elements
    void displayArray()
    {
        cout << "Array elements: ";
        for (int i = 0; i < SIZE; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to find the maximum element in the array
    int findMax()
    {
        int max = arr[0];
        for (int i = 1; i < SIZE; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }

    // Function to find the minimum element in the array
    int findMin()
    {
        int min = arr[0];
        for (int i = 1; i < SIZE; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }
        return min;
    }

    // Function to search for an element in the array
    int search(int key)
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (arr[i] == key)
            {
                return i; // Return the index of the found element
            }
        }
        return -1; // Return -1 if the element is not found
    }

    // Function to sort the array in ascending order using Bubble Sort
    void bubbleSort()
    {
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int j = 0; j < SIZE - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    // Swap arr[j] and arr[j + 1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    // Function to sort the array in ascending order using Selection Sort
    void selectionSort()
    {
        for (int i = 0; i < SIZE - 1; i++)
        {

            int minIndex = i;

            for (int j = i + 1; j < SIZE; j++)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            // Swap arr[i] and arr[minIndex]
            if (i != minIndex)
            {
                int temp = arr[i];
                arr[i] = arr[minIndex];
                arr[minIndex] = temp;
            }
        }
    }

    // Function to find the maximum sum of a subarray
    int maxSubarraySum()
    {
        int maxSum = arr[0];
        int currentSum = arr[0];
        for (int i = 1; i < SIZE; i++)
        {
            currentSum = max(arr[i], currentSum + arr[i]);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};

int main()
{
    int SIZE;
    cout << "Enter the SIZE of the array: ";
    cin >> SIZE;

    ARRAY arr(SIZE);
    arr.inputArray();
    arr.displayArray();

    // cout << "Maximum element: " << arr.findMax() << endl;
    // cout << "Minimum element: " << arr.findMin() << endl;

    // int key;
    // cout << "Enter the element to search: ";
    // cin >> key;
    // int result = arr.search(key);
    // if (result != -1)
    // {
    //     cout << "Element found at index " << result << endl;
    // }
    // else
    // {
    //     cout << "Element not found" << endl;
    // }

    // arr.bubbleSort();
    // cout << "Array after Bubble Sort: ";
    // arr.displayArray();

    arr.selectionSort();
    cout << "Array after Selection Sort: ";
    arr.displayArray();

    cout << "Maximum sum of a subarray: " << arr.maxSubarraySum() << endl;

    return 0;
}

/*
This implementation includes the following member functions:

- inputArray(): Inputs array elements from the user.
- displayArray(): Displays the array elements.
- findMax(): Finds the maximum element in the array.
- findMin(): Finds the minimum element in the array.

- search(int key): Searches for an element in the array and returns its index if found, -1 otherwise.
- bubbleSort(): Sorts the array in ascending order using Bubble Sort.
- selectionSort(): Sorts the array in ascending order using Selection Sort.
- maxSubarraySum(): Finds the maximum sum of a subarray.

The main() function demonstrates how to use these member functions.

You can compile and run this code to test the implementation.

Note that this is a basic implementation, and you may want to add more features, error checking, or optimization depending on your specific requirements.
*/
