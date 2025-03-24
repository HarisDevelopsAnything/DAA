#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Node {
    char character;
    float freq;
    struct Node* left;
    struct Node* right;
};
void dispNode(struct Node n){
    printf("Character: %c\n",n.character);
    printf("Frequency: %.2f\n", n.freq);
}
struct Node huffmanTree(struct Node n1, struct Node n2){
    struct Node root;
    root.character = NULL;
    root.left = &n1;
    root.right = &n2;
    root.freq = n1.freq+ n2.freq;
    return root;
}
struct Node huffmanConstr(struct Node ele[], int n){
    int r= 0;
    int i=0;
    struct Node root = ele[0];
    while(i<n-1){
        printf("Joining: \n");
        dispNode(root);
        dispNode(ele[i+1]);
        root = huffmanTree(root, ele[i+1]);
        printf("New root freq. %.2f\n", root.freq);
        i++;
    }
    return root;
}
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
    //init freq.
    freq[0]= 0;
    for(int i=1;i<un;i++){
        freq[i]=1;
    }
    unc[0]= str[0];
    //unique characters and freq.
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
    //creating nodes
    for(int i=0;i<un;i++){
        printf("%c - %.2f\n",unc[i],(float)freq[i]/n);
        struct Node node;
        node.character = unc[i];
        node.freq = (float)freq[i]/n;
        node.left = NULL;
        node.right = NULL;
        A[i] = node;
    }
    //arrange in ascending frequency
    for(int i=1;i<un;i++){
        struct Node ref= A[i];
        int j=i-1;
        while(j>=0 && A[j].freq > ref.freq){
            A[j+1] = A[j];
            j--;
        }
        A[j+1]= ref;
    }
    for(int i=0;i<un;i++){
        dispNode(A[i]);
    }
    struct Node root = huffmanConstr(A,un);
    printf("%.2f\n",root.freq);
}