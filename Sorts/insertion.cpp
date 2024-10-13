#include <iostream>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;

        while (j>=0 && arr[j]> current) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
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