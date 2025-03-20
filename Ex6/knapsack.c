#include <stdio.h>
#include <stdlib.h>
int MFKnapsack(int** F, int* w, int* v,int i,int j){
    if(F[i][j]<0){
        if(j<w[i])
            F[i][j]= MFKnapsack(F,w,v,i-1,j);
        else{
            int v1=  MFKnapsack(F,w,v,i-1,j);
            int v2=  v[i]+MFKnapsack(F,w,v,i-1,j-w[i]);
            F[i][j]= v1>v2?v1:v2;
        }      
    }
}
int main(){
    int n,cap;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d",&cap);
    int** F= (int**)malloc((n+1)*sizeof(int*));
    int i;
    for(i=0;i<=n;i++){
        F[i] = (int*)malloc((cap+1)*sizeof(int));
    }
    int w[n];
    int v[n];
    int j;
    for(i=0;i<=n;i++){
        for(j=0;j<=cap;j++){
            if(i==0 || j==0)
            F[i][j]=0;
        }
    }
    for(i=1;i<=n;i++){
        printf("Item %d:\n", i);
        printf("Weight: ");
        scanf("%d",&w[i-1]);
        printf("Value: ");
        scanf("%d",&v[i-1]);
        for(j=1;j<=cap;j++){
            if(w[i]>j)
            F[i][j]=F[i-1][j];
            else
            F[i][j]=-1;
        }
    }
    int optwe= MFKnapsack(F,w,v,n,cap);
    printf("Optimal Knapsack weight: %d\n", optwe);
    i=n-1;
    int c= cap;
    for(i=0;i<=n;i++){
        for(j=0;j<=cap;j++){
            printf("%d ",F[i][j]);
        }
        printf("\n");
    }
}