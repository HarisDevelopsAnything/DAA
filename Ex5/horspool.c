#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void makeShiftTable(int* arr, char* p,int m){
    int i;
    for(i=0;i<27;i++){
        arr[i]= m;
    }
    for(i=m-2;i>=0;i--){
        if(arr[(int)p[i]-65] > m-i-1)
        arr[(int)p[i]-65] = m-i-1;
    }
}
int main(){
    int* arr= (int*)malloc(sizeof(int)*27);
    char* t= (char*)malloc(sizeof(char)*100);
    printf("Enter the text: ");
    fgets(t,100,stdin);
    int n= strlen(t)-1;
    t= realloc(t, (n+1)*sizeof(char));
    char* p= (char*)malloc(sizeof(char)*100);
    printf("Enter the pattern: ");
    fgets(p,100,stdin);
    int m= strlen(p)-1;
    p= realloc(p, (m+1)*sizeof(char));
    int shift=1;
    int found=0;
    int pos;
    int c=0;
    int match=0;
    makeShiftTable(arr,p,m);
    int i=0,j=0;
    printf("%s",t);
    while(!found && i<n-m+1){
        pos=i;
        j=i+m-1;
        c = m-1;
        int k;
        for(k=0;k<pos;k++){
            printf(" ");
        }
        printf("%s",p);
        while(j>=i){
            //printf("Cmp %c and %c\n",t[j]==' '?'_':t[j],p[c]);
            if(t[j]!=p[c]){
                if((int)t[j]!=32)
                shift = arr[(int)t[j]-65];
                else
                shift = m;
                break;
            }
            j--;
            c--;
            match++;
        }
        if(match==m){ 
            found= 1;
            printf("Substring found at index %d\n",pos);
        }
        else{
            i=i+shift;
        }
    }
    if(!found) printf("Substring not found!\n");
}