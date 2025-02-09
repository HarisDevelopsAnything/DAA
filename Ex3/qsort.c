#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    printf("Pivot: %d\n", arr[low]);
    printf("Low: %d\n", low);
    printf("High: %d\n", high);
    int p = arr[low];
    int i = low;
    int j = high;
    
    while (i < j) {
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    printf("Moved %d to final location!\n",arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        printf("Partition index: %d\n",pi);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
  int n;
  printf("Enter the no. of elements: ");
  scanf("%d",&n);
  int* arr= (int*)malloc(n*sizeof(int));
  int i;
  for(i=0;i<n;i++){
    printf("Enter element %d: ",i+1);
    scanf("%d", &arr[i]);
  }
  quickSort(arr,0,n-1);
  printf("After sort:\n");
  for(i=0;i<n;i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}