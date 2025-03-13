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
    int n;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    int F[n][n+1];
    int w[n];
    int v[n];
    int i,j;
    for(i=0;i<n;i++){
        printf("Item %d:\n", i+1);
        printf("Weight: ");
        scanf("%d",&w[i]);
        printf("Value: ");
        scanf("%d", &v[i]);
        for(j=0;j<=n;j++){
            if(i==0 || j==0)
            F[i][j]=0;
            else
            F[i][j]=-1;
        }
    }
    int optwe= MFKnapsack(&F,w,v,n-1,n);
    printf("%d\n", optwe);
}