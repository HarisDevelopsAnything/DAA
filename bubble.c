#include<stdio.h>

int* sort(int* arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
    return arr;
}
int main(){
    int a[]= {1,2,0};
    int* res= sort(a,3);
    for(int i=0;i<3;i++){
        printf("%d ", res[i]);
    }
    printf("\n");
}


