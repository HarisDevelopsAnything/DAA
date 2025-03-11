#include <stdio.h>
int binSearch(int arr[], int l, int r, int s){
    if(r>=l){
        int m = (l + r)/2;
        if(arr[m] == s)
            return m;
        if(arr[m] > s)
            return binSearch(arr,l,m-1,s);
        return binSearch(arr,m+1,r,s);
    }
    return -1;
}
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
    printf("Enter element to search: ");
    int s;
    scanf("%d",&s);
    int l=0, r=n-1, m;
    int f= binSearch(arr,l,r,s);
    if(f==-1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n",f);
    printf("\n");
}