Here's an explanation of Insertion Sort in detail, along with C++ code examples:

What is Insertion Sort?

Insertion Sort is a simple sorting algorithm that works by iterating through an array one element at a time, inserting each element into its proper position within the previously sorted portion of the array.

How Insertion Sort Works:

1. Start with the first element of the array (considered sorted).
2. Iterate through the remaining elements.
3. For each element, compare it with the previous elements in the sorted portion.
4. Shift elements greater than the current element one position to the right.
5. Insert the current element into the correct position.

C++ Code:
```cpp
#include <iostream>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
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

    insertionSort(arr, n);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
```

Explanation of Code:

- insertionSort function takes two arguments: arr (array to sort) and n (array length).
- Iterate from the second element (i = 1) to the end of the array.
- Store the current element (key) and its index (j = i - 1).
- Shift elements greater than key one position to the right.
- Insert key into the correct position.

Time Complexity:

- Best-case: O(n) (already sorted)
- Average-case: O(n^2)
- Worst-case: O(n^2)

Space Complexity:

- O(1) (in-place sorting)

Advantages:

- Simple to implement.
- Efficient for small datasets.
- Stable sorting algorithm.

Disadvantages:

- Inefficient for large datasets.
- Not suitable for real-time applications.

Insertion Sort is a simple sorting algorithm suitable for small datasets. Its quadratic time complexity makes it less efficient for large datasets. However, its simplicity and stability make it useful in certain scenarios.

Optimized Insertion Sort:

To improve performance, consider using:

- Binary Insertion Sort: Use binary search to find the insertion point.
- Shell Sort: Use a gap to compare elements.

These optimizations can improve performance for larger datasets.