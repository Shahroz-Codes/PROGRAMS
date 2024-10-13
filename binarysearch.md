Here's an explanation of Binary Search in detail, along with C++ code examples:

What is Binary Search?

Binary Search is an efficient algorithm for finding an element in a sorted array. It works by repeatedly dividing the search space in half until the target element is found.

How Binary Search Works:

1. Start with a sorted array.
2. Find the middle element of the array.
3. Compare the target element with the middle element.
4. If the target is less than the middle, repeat steps 2-3 with the left half.
5. If the target is greater than the middle, repeat steps 2-3 with the right half.
6. Continue until the target is found or the search space is empty.

C++ Code:
```cpp
#include <iostream>

int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Target found
        } else if (arr[mid] < target) {
            left = mid + 1; // Search right half
        } else {
            right = mid - 1; // Search left half
        }
    }

    return -1; // Target not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}

```
Explanation of Code:

- binarySearch function takes three arguments: arr (sorted array), n (array length), and target (element to find).
- Initialize left to 0 and right to n - 1, representing the search space.
- Loop until left is greater than right.
- Calculate mid as the middle index.
- Compare arr[mid] with target.
- If equal, return mid (target found).
- If less than target, update left to mid + 1 (search right half).
- If greater than target, update right to mid - 1 (search left half).
- If loop ends without finding target, return -1 (target not found).

Time Complexity:

- Best-case: O(1) (target is middle element)
- Average-case: O(log n)
- Worst-case: O(log n)

Space Complexity:

- O(1) (no extra space needed)

Advantages:

- Fast search times for large datasets
- Efficient use of memory

Disadvantages:

- Requires sorted array
- Not suitable for real-time search

Binary Search is an efficient algorithm for finding elements in sorted arrays. Its logarithmic time complexity makes it suitable for large datasets. However, it requires the array to be sorted, which can be a limitation in certain scenarios.