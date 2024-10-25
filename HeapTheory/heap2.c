#include <stdio.h>
#include <stdlib.h>

void maxHeap(int *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        maxHeap(arr, n, largest);
    }
}

void minHeap(int *arr, int n, int i) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] < arr[smallest]) {
        smallest = l;
    }
    if (r < n && arr[r] < arr[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        minHeap(arr, n, smallest);
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void ascendingHeapSorting(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeap(arr, n, i);
    }
    printf("Max heap tree is:\n");
    printArray(arr, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        maxHeap(arr, i, 0); // Reduce heap size each time
        printf("Intermediate State %d:\n", n - i);
        printArray(arr, n);
    }
}

void descendingHeapSorting(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeap(arr, n, i);
    }
    printf("Min heap tree is:\n");
    printArray(arr, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        minHeap(arr, i, 0); // Reduce heap size each time
        printf("Intermediate State %d:\n", n - i);
        printArray(arr, n);
    }
}

int main() {
    int n;
    printf("Enter the size of an array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    printf("Enter the elements of the heap tree:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("1) Max heap tree\n2) Min heap tree\n 3)Exit");
    printf("Enter the number based on your sorting: ");
    int choice;
    scanf("%d", &choice);
    if (choice == 1) {
        ascendingHeapSorting(arr, n);
    } else if (choice == 2) {
        descendingHeapSorting(arr, n);
    }

    free(arr);
    return 0;
}
