#include <stdio.h>
#include <string.h>

// Function to perform binary search on a sorted array of strings
int binarySearch(char *arr[], int size, const char *target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Compare the middle element with the target
        int cmp = strcmp(arr[mid], target);
        if (cmp == 0) {
            return mid; // Target found
        } else if (cmp < 0) {
            left = mid + 1; // Narrow down to the right half
        } else {
            right = mid - 1; // Narrow down to the left half
        }
    }

    return -1; // Target not found
}

int main() {
    // Example array of strings
    char *arr[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
    int size = sizeof(arr) / sizeof(arr[0]);

    char target[50];
    printf("Enter the string to search: ");
    scanf("%s", target);

    // Perform binary search
    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("String found at index %d.\n", result);
    } else {
        printf("String not found.\n");
    }

    return 0;
}
