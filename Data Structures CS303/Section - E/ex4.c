#include <stdio.h>
#include <string.h>


int linearSearch(char *arr[], int size, const char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], target) == 0) { 
            return i; 
        }
    }
    return -1; 
}

int main() {
    
    char *arr[] = {"apple", "banana", "cherry", "date", "fig", "grape"};
    int size = sizeof(arr) / sizeof(arr[0]);

    char target[50];
    printf("Enter the string to search: ");
    scanf("%s", target);

    
    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("String found at index %d.\n", result);
    } else {
        printf("String not found.\n");
    }

    return 0;
}
