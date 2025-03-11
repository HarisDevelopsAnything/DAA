#include <stdio.h>
#include <stdlib.h>

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void heapify(int arr[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(&arr[index], &arr[largest]);
        heapify(arr, size, largest);
    }
}
void buildMinHeap(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}
void heapSort(int arr[], int size) {
    buildMinHeap(arr, size);
    for (int i = size - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int size;
    printf("Enter the no. of elements: ");
    scanf("%d", &size);
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }   
    printf("Original array: ");
    display(arr, size);
    heapSort(arr, size);
    printf("\n");
    printf("Sorted array: ");
    display(arr, size);
    return 0;
}
