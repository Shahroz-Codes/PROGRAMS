Here's an explanation of Quick Sort in detail, along with C++ code examples:

What is Quick Sort?

Quick Sort is a divide-and-conquer sorting algorithm that works by selecting a pivot element, partitioning the array around it, and recursively sorting the subarrays.

How Quick Sort Works:

1. Choose a pivot element from the array.
2. Partition the array into two parts: elements less than the pivot and elements greater than the pivot.
3. Recursively apply the same process to the subarrays.
4. Combine the sorted subarrays.

C++ Code:
```cpp
#include <iostream>

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) i++;
        while (j >= low && arr[j] > pivot) j--;
        if (i <= j) std::swap(arr[i], arr[j]);
    }

    std::swap(arr[low], arr[j]);
    return j;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {5, 2, 8, 3, 1, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
```

Explanation of Code:

- quickSort function takes three arguments: arr (array to sort), low (starting index), and high (ending index).
- partition function takes three arguments: arr (array to partition), low (starting index), and high (ending index).
- Choose a pivot element (pivot = arr[low]).
- Partition the array around the pivot.
- Recursively apply quickSort to the subarrays.

Time Complexity:

- Best-case: O(n log n)
- Average-case: O(n log n)
- Worst-case: O(n^2)

Space Complexity:

- O(log n) (recursive call stack)

Advantages:

- Fast sorting times.
- Efficient use of memory.

Disadvantages:

- Worst-case performance can be poor.
- Not stable sorting algorithm.

Quick Sort is a fast and efficient sorting algorithm, but its worst-case performance can be poor. However, its average-case performance makes it suitable for many applications.

Optimized Quick Sort:

To improve performance, consider using:

- Median of Three: Choose a better pivot.
- Introsort: Switch to Heap Sort for worst-case scenarios.
- Dual-Pivot Quick Sort: Use two pivots.

These optimizations can improve performance and reduce the likelihood of worst-case scenarios.