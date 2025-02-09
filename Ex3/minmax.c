#include<stdio.h>

void findMinMax(int* arr, int low, int high, int* min, int* max){
    if(high==low){
        *min= arr[high];
        *max= arr[low];
    }
    else if(high==low+1){
        if(arr[low] < arr[high]){
            *min= arr[low];
            *max= arr[high];
        }
        else{
            *min= arr[high];
            *max= arr[low];
        }
    }
    else{
        int mid= (low+high)/2;
        int lmin;
        int lmax;
        int rmin;
        int rmax;
        findMinMax(arr,low,mid,&lmin,&lmax);
        findMinMax(arr,mid+1,high,&rmin,&rmax);
        if(lmax>rmax)
        *max= lmax;
        else
        *max= rmax;
        if(rmin<lmin)
        *min= rmin;
        else
        *min= lmin;

    }
}

int main(){
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    int* arr= (int*)malloc(n*sizeof(int));
    int i;
    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d", &arr[i]);
    }
    int min, max;
    findMinMax(arr,0,n-1,&min,&max);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
}
