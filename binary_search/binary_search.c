#include "binary_search.h"

// recursive method
int
search(int* arr, int q, int low, int high) {
    int mid = low + (high - low) / 2;
    if (q == arr[mid]) {
        return mid;
    } else if (q < arr[mid]) {
        return search(arr, q, low, mid - 1);
    } else if (q > arr[mid]) {
        return search(arr, q, mid + 1, high);
    } else {
        return -1;
    }
}

// iterative method
int
search2(int* arr, int q, int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (q == arr[mid]) {
            return mid;
        }
        if (q > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}
