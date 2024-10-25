#include <stdio.h>
#include <stdlib.h>

void maxHeap(int *arr, int n) {
    for(int i=1;i<n;i++){
        if(arr[i]>arr[(i-1)/2]){
            int j=i;
            while(arr[j]>arr[(j-1)/2]){
                int temp=arr[j];
                arr[j]=arr[(j-1)/2];
                arr[(j-1)/2]=temp;
                j=(j-1)/2;
            }
        }
    }
}

void minHeap(int *arr, int n) {
   for(int i=1;i<n;i++){
        if(arr[i]<arr[(i-1)/2]){
            int j=i;
            while(arr[j]<arr[(j-1)/2]){
                int temp=arr[j];
                arr[j]=arr[(j-1)/2];
                arr[(j-1)/2]=temp;
                j=(j-1)/2;
            }
        }
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void ascendingHeapSorting(int *arr, int n) {
    maxHeap(arr,n);
    printf("Max heap tree is:\n");
    printArray(arr, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        int j=0,index;
        do{
            index=2*j+1;
            if(arr[index]<arr[index+1] && index<(i-1)) index++;
            if(arr[j]<arr[index] && index<i){
                int temp=arr[j];
                arr[j]=arr[index];
                arr[index]=temp;
            }
            j=index;
        }while(index<i);
        printf("Intermediate State %d:\n", n - i);
        printArray(arr, n);
    }
}

void descendingHeapSorting(int *arr, int n) {
    minHeap(arr,n);
    printf("Min heap tree is:\n");
    printArray(arr, n);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        int j=0,index;
        do{
            index=2*j+1;
            if(arr[index]>arr[index+1] && index<(i-1)) index++;
            if(arr[j]>arr[index] && index<i){
                int temp=arr[j];
                arr[j]=arr[index];
                arr[index]=temp;
            }
            j=index;
        }while(index<i);
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

    printf("1) Max heap tree\n2) Min heap tree\n3) Exit \n");
    int choice;
    do{
        printf("Enter the number based on your sorting: ");
        scanf("%d", &choice);
        if (choice == 1) {
        ascendingHeapSorting(arr, n);
        printf("The final heap sort array in ascending order is : \n");
        printArray(arr,n);
        } 
        else if (choice == 2) {
        descendingHeapSorting(arr, n);
        printf("The final heap sort array in descending order is : \n");
        }
        else if (choice==3){
            printf("Program exited . \n");
        }
    }while(choice!=3);

    free(arr);
    return 0;
}
