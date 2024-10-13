Here's an explanation of Merge Sort in detail, along with C++ code examples:

What is Merge Sort?

Merge Sort is a divide-and-conquer sorting algorithm that works by dividing the array into smaller subarrays, sorting each subarray, and then merging the sorted subarrays.

How Merge Sort Works:

1. Divide the array into two halves.
2. Recursively apply Merge Sort to each half.
3. Merge the two sorted halves.

C++ Code:
```cpp
#include <iostream>

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++) left[i] = arr[low + i];
    for (int i = 0; i < n2; i++) right[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) arr[k] = left[i++];
        else arr[k] = right[j++];
        k++;
    }

    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
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

    mergeSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
```

Explanation of Code:

- mergeSort function takes three arguments: arr (array to sort), low (starting index), and high (ending index).
- merge function takes four arguments: arr (array to merge), low (starting index), mid (middle index), and high (ending index).
- Divide the array into two halves (mid = (low + high) / 2).
- Recursively apply mergeSort to each half.
- Merge the two sorted halves using merge.

Time Complexity:

- Best-case: O(n log n)
- Average-case: O(n log n)
- Worst-case: O(n log n)

Space Complexity:

- O(n) (auxiliary arrays)

Advantages:

- Fast sorting times.
- Stable sorting algorithm.

Disadvantages:

- Requires extra memory.

Merge Sort is a fast and stable sorting algorithm, making it suitable for many applications.

Optimized Merge Sort:

To improve performance, consider using:

- Iterative Merge Sort: Avoid recursive calls.
- Natural Merge Sort: Take advantage of existing order.
- Hybrid Sorting: Combine Merge Sort with other algorithms.

These optimizations can improve performance and reduce memory usage.