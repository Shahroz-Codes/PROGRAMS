#include<iostream>
using namespace std;
const int SIZE = 10;

void InsertionSortReverse(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;

        while (j>=0) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = current;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

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
            right = mid - 1;
        }
    }

    return -1; 
}
int main()
{
    int arr[5]={12,19,17,15,16};
    InsertionSortReverse( arr, 5);
    printArray(arr,5);
   return 0;
}