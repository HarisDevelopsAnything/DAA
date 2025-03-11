#include <stdio.h>

void main(){
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    int* arr= (int*)malloc(n*sizeof(int));
    int i;
    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d", &arr[i]);
    }
    for(i=1;i<n;i++){
        int v = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>v){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;
    }
    printf("After sort:\n");
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}