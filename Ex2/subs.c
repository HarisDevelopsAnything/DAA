#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int findSub(char* T, char* P){
    printf("%s", T);
    int n = strlen(T)-1;
    int m= strlen(P)-1;
    int i,j,k;
    for(i=0;i<n-m+1;i++){
        j=0;
        for(k=0;k<i;k++){
            printf(" ");
        }
        printf("%s",P);
        while(j<m && P[j]==T[j+i]){
            j++;
        }
        if(j==m)
        return i;
    }
    return -1;
}

int main(){
    char* T= (char*)malloc(sizeof(char)*100);
    printf("Enter the string: ");
    fgets(T,100,stdin);
    T= realloc(T, strlen(T)*sizeof(char));
    printf("Enter the substring: ");
    char* P= (char*)malloc(sizeof(char)*100);
    fgets(P,100,stdin);
    P= realloc(P, strlen(P)*sizeof(char));
    int ind= findSub(T,P);
    if(ind!=-1)
    printf("Found at index %d\n", ind);
    else
    printf("Not found!\n");
}