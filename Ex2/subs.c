#include<stdio.h>

int findSub(char* T, int n, char* P, int m){
    int i,j;
    for(i=0;i<n-m+1;i++){
        j=0;
        while(j<m && P[j]==T[j+i])
            j++;
        if(j==m)
        return i;
    }
    return -1;
}

int main(){
    printf("Enter the length of string: ");
    int n;
    scanf("%d", &n);
    getchar();
    printf("Enter the string: ");
    char T[n];
    fgets(T, n, stdin);
    getchar();
    printf("Enter the length of substring: ");
    int m;
    scanf("%d", &m);
    getchar();
    printf("Enter the substring: ");
    char P[m];
    fgets(P, m, stdin);
    if(findSub(T,n,P,m))
    printf("Found at index %d\n", findSub(T,n,P,m));
    else
    printf("Not found!\n");
}