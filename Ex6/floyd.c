#include <stdio.h>
#include <stdlib.h>
void floyd(int **mat, int n) {
    int **dist = (int **)malloc(n * sizeof(int *));
    int i,j,k;
    for (i = 0; i < n; i++) {
        dist[i] = (int *)malloc(n * sizeof(int));
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dist[i][j] = mat[i][j];
        }
    }
    for (k = 0; k < n; k++) {
        printf("Keeping %d vertices as intermediate: \n",k+1);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        for (i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(dist[i][j] == 999)
                printf("-\t");
                else
                printf("%d\t",dist[i][j]);
            }
            printf("\n");
        }
    }
    printf("The all-pair short. path mat:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == 999) {
                printf("-\t");
            } else {
                printf("%d\t", dist[i][j]);
            }
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
    int **mat = (int **)malloc(n *sizeof(int*));
    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter the adj. mat (999: no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                mat[i][j] = 0;
            } else {
                printf("Ad. mat. (%d, %d): ", i, j);
                scanf("%d", &mat[i][j]);
            }
        }
    }
    floyd(mat, n);
    return 0;
}
