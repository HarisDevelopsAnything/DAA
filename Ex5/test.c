#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char* p= (char*)malloc(sizeof(char)*100);
    printf("Enter the pattern: ");
    fgets(p,100,stdin);
    int m= strlen(p);
    printf("%d\n",m);
}