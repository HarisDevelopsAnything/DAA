#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
int N = 0;
int* final_path;
bool* visited;
int final_res = 99999;
void copyToFinal(int* curr_path)
{
	for (int i=0; i<N; i++)
		final_path[i] = curr_path[i];
	final_path[N] = curr_path[0];
}
int firstMin(int** adj, int i)
{
	int min = 99999;
	for (int k=0; k<N; k++)
		if (adj[i][k]<min && i != k)
			min = adj[i][k];
	return min;
}
int secondMin(int** adj, int i)
{
	int first = 99999, second = 99999;
	for (int j=0; j<N; j++)
	{
		if (i == j)
			continue;

		if (adj[i][j] <= first)
		{
			second = first;
			first = adj[i][j];
		}
		else if (adj[i][j] <= second &&
				adj[i][j] != first)
			second = adj[i][j];
	}
	return second;
}
void TSPRec(int** adj, int curr_bound, int curr_weight,
			int level, int* curr_path)
{
	if (level==N)
	{
		if (adj[curr_path[level-1]][curr_path[0]] != 0)
		{
			int curr_res = curr_weight + adj[curr_path[level-1]][curr_path[0]];
			if (curr_res < final_res)
			{
				copyToFinal(curr_path);
				final_res = curr_res;
			}
		}
		return;
	}
	for (int i=0; i<N; i++)
	{
		if (adj[curr_path[level-1]][i] != 0 &&
			visited[i] == false)
		{
			int temp = curr_bound;
			curr_weight += adj[curr_path[level-1]][i];
			if (level==1)
			curr_bound -= ((firstMin(adj, curr_path[level-1]) + firstMin(adj, i))/2);
			else
			curr_bound -= ((secondMin(adj, curr_path[level-1]) +firstMin(adj, i))/2);
			if (curr_bound + curr_weight < final_res)
			{
				curr_path[level] = i;
				visited[i] = true;
				TSPRec(adj, curr_bound, curr_weight, level+1,
					curr_path);
			}
			curr_weight -= adj[curr_path[level-1]][i];
			curr_bound = temp;
			for(int i=0;i<N;i++){
                visited[i]= false;
            }
			for (int j=0; j<=level-1; j++)
				visited[curr_path[j]] = true;
		}
	}
} 
void TSP(int** adj)
{
	int* curr_path = (int*)malloc(sizeof(int)*(N+1));
	int curr_bound = 0;
	for(int i=0;i<N;i++){
        curr_path[i] = -1;
        visited[i]= 0;
    }
	for (int i=0; i<N; i++)
		curr_bound += (firstMin(adj, i) +secondMin(adj, i));
	curr_bound = (curr_bound%2!=0)? curr_bound/2 + 1 :curr_bound/2;
	visited[0] = true;
	curr_path[0] = 0;
	TSPRec(adj, curr_bound, 0, 1, curr_path);
}
int main()
{
    printf("Enter the no. of towns: ");
    scanf("%d",&N);
    int **adj = (int**)malloc(sizeof(int*)*N);
    final_path = (int*)malloc(sizeof(int)*N);
    visited = (bool*)calloc(sizeof(bool),N);
    for(int i=0;i<N;i++){
        adj[i]= (int*)malloc(sizeof(int)*N);
    }
	for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                adj[i][j] = 99999;
                continue;
            }
        printf("[%d][%d]: ",i,j);
        scanf("%d", &adj[i][j]);
        }
    }

	TSP(adj);

	printf("Minimum cost : %d\n", final_res);
	printf("Path Taken : ");
	for (int i=0; i<=N; i++)
		printf("%d ", final_path[i]);

	return 0;
}
