#include<stdio.h>

int power(int a, int n){
    int s=1;
    for(int i=0;i<n;i++){
        s= s*a;
    }
    return s;
}
int main(){
    int a, n;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter n: ");
    scanf("%d", &n);
    int res= power(a,n);
    printf("%d\n", res);
}


