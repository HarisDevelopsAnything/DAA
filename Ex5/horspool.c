#include <stdio.h>
#include <stdlib.h>

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
    char t[]= "FOR GEEKS";
    int n=9;
    char p[]= "GEEK";
    int m= 4;
    int shift=1;
    int found=0;
    int pos;
    int c=0;
    int match=0;
    makeShiftTable(arr,p,m);
    int i=0,j=0;
    while(!found && i<n-m+1){
        pos=i;
        j=i+m-1;
        c = m-1;
        while(j>=i){
            printf("Cmp %c and %c\n",t[j]==' '?'_':t[j],p[c]);
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