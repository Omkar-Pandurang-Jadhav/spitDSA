#include <stdio.h>
#include <stdlib.h>

// Function to create a max heap from an array
void maxHeap(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        // If the current element is greater than its parent
        if (arr[i] > arr[(i - 1) / 2]) {
            int j = i;
            // Bubble up the element to maintain the max heap property
            while (arr[j] > arr[(j - 1) / 2]) {
                int temp = arr[j];
                arr[j] = arr[(j - 1) / 2];
                arr[(j - 1) / 2] = temp;
                j = (j - 1) / 2; // Move to parent index
            }
        }
    }
}

// Function to create a min heap from an array
void minHeap(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        // If the current element is less than its parent
        if (arr[i] < arr[(i - 1) / 2]) {
            int j = i;
            // Bubble up the element to maintain the min heap property
            while (arr[j] < arr[(j - 1) / 2]) {
                int temp = arr[j];
                arr[j] = arr[(j - 1) / 2];
                arr[(j - 1) / 2] = temp;
                j = (j - 1) / 2; // Move to parent index
            }
        }
    }
}

// Function to print the array
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform heap sort in ascending order using max heap
void ascendingHeapSorting(int *arr, int n) {
    // Build max heap
    maxHeap(arr, n);
    printf("Max heap tree is:\n");
    printArray(arr, n);

    // Sorting the array
    for (int i = n - 1; i > 0; i--) {
        // Swap the root of the heap with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Maintain the max heap property for the reduced heap
        int j = 0, index;
        do {
            index = 2 * j + 1; // Left child index
            // Check if right child exists and is greater than left child
            if (index + 1 < i && arr[index] < arr[index + 1]) {
                index++; // Use the right child if it's larger
            }
            // If the current node is smaller than the largest child
            if (j < index && index < i) {
                temp = arr[j];
                arr[j] = arr[index];
                arr[index] = temp; // Swap
            }
            j = index; // Move down to the child
        } while (index < i);
        printf("Intermediate State %d:\n", n - i);
        printArray(arr, n);
    }
}

// Function to perform heap sort in descending order using min heap
void descendingHeapSorting(int *arr, int n) {
    // Build min heap
    minHeap(arr, n);
    printf("Min heap tree is:\n");
    printArray(arr, n);

    // Sorting the array
    for (int i = n - 1; i > 0; i--) {
        // Swap the root of the heap with the last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Maintain the min heap property for the reduced heap
        int j = 0, index;
        do {
            index = 2 * j + 1; // Left child index
            // Check if right child exists and is smaller than left child
            if (index + 1 < i && arr[index] > arr[index + 1]) {
                index++; // Use the right child if it's smaller
            }
            // If the current node is greater than the smallest child
            if (j > index && index < i) {
                temp = arr[j];
                arr[j] = arr[index];
                arr[index] = temp; // Swap
            }
            j = index; // Move down to the child
        } while (index < i);
        printf("Intermediate State %d:\n", n - i);
        printArray(arr, n);
    }
}

// Main function to drive the program
int main() {
    int n;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int)); // Allocate memory for the array
    printf("Enter the elements of the heap tree:\n");

    // Read elements into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Menu for choosing sorting method
    printf("1) Max heap tree\n2) Min heap tree\n3) Exit\n");
    int choice;
    do {
        printf("Enter the number based on your sorting: ");
        scanf("%d", &choice);
        if (choice == 1) {
            ascendingHeapSorting(arr, n);
            printf("The final heap sort array in ascending order is:\n");
            printArray(arr, n);
        } 
        else if (choice == 2) {
            descendingHeapSorting(arr, n);
            printf("The final heap sort array in descending order is:\n");
            printArray(arr, n);
        }
        else if (choice == 3) {
            printf("Program exited.\n");
        }
    } while (choice != 3);

    free(arr); // Free the allocated memory
    return 0;
}
