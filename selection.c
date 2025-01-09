#include<stdio.h>

int* sort(int* arr, int n){
    for(int i=0;i<n-1;i++){
        int min= i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min= j;
            }
        }
        int temp= arr[i];
        arr[i]= arr[min];
        arr[min]= temp;
    }
    return arr;
}
int main(){
    int a[]= {1,2,0,4};
    int* res= sort(a,4);
    for(int i=0;i<4;i++){
        printf("%d ", res[i]);
    }
    printf("\n");
}


