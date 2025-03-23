#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node {
    char character;
    float freq;
};
struct Combine {
    float val;
    struct Node* left;
    struct Node* right;
};
int main(){

    char* str = (char*)malloc(sizeof(char)*100);
    printf("Enter the string: ");
    scanf("%s",str);
    int n= strlen(str);
    printf("%d\n",n);
    for(int i=1;i<n;i++){
        char ref= str[i];
        int j= i-1;
        while(j>=0 && str[j]>ref){
            str[j+1]= str[j];
            j--;
        }
        str[j+1]= ref;
    }
    int un=1;
    char pc=str[0];
    for(int i=0;i<n;i++){
        if(pc==str[i])
        continue;
        else{
            pc= str[i];
            un++;
        }
    }
    struct Node A[un];
    printf("%s - unique: %d\n",str,un);
    int* freq= (int*)malloc(sizeof(int)*un);
    char* unc= (char*)malloc(sizeof(char)*un);
    int ind =0;
    int f= 0;
    pc= str[0];
    for(int i=1;i<un;i++){
        freq[i]=1;
    }
    unc[0]= str[0];
    for(int i=0;i<n;i++){
        if(pc==str[i]){
            freq[ind]++;
        }
        else{
            unc[ind+1]= str[i];
            ind++;
            pc= str[i];
        }
    }
    for(int i=0;i<un;i++){
        printf("%c - %.2f\n",unc[i],(float)freq[i]/n);
        struct Node node;
        node.character = unc[i];
        node.freq = (float)freq[i]/n;
        A[i] = node;
    }
    for(int i=1;i<n;i++){
        struct Node ref= A[i];
        int j=i-1;
        while(j>=0 && A[i].freq > ref.freq){
            A[j+1] = A[j];
            j--;
        }
        A[j+1]= ref;
    }
    
}