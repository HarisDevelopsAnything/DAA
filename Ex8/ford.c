#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* Returns true if there is a path from source 's' to sink 't' in
   residual graph. Also fills parent[] to store the path */
bool bfs(int **rGraph, int V, int s, int t, int parent[]) {
    // Create a visited array and mark all vertices as not visited
    bool *visited = (bool*)malloc(V * sizeof(bool));
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }

    // Create a queue, enqueue source vertex and mark source vertex as visited
    int *queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0;
    
    // Enqueue source vertex
    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;

    // Standard BFS loop
    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < V; v++) {
            if (visited[v] == false && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    // Free dynamically allocated memory
    free(visited);
    free(queue);

    // We can reach sink from source if visited[t] becomes true
    return (parent[t] != -1);
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(int **graph, int V, int s, int t) {
    int u, v;

    // Create a residual graph and fill it with given capacities as
    // residual capacities of original graph
    int **rGraph = (int**)malloc(V * sizeof(int*));
    for (u = 0; u < V; u++) {
        rGraph[u] = (int*)malloc(V * sizeof(int));
        for (v = 0; v < V; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    int *parent = (int*)malloc(V * sizeof(int)); // Array filled by BFS to store path
    
    // Initialize all parent values as -1 (no parent assigned yet)
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }
    
    int max_flow = 0; // Initialize the maximum flow

    // Augment the flow while there is a path from source to sink
    while (bfs(rGraph, V, s, t, parent)) {
        // Find minimum residual capacity of the edges along the
        // path found by BFS
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = (rGraph[u][v] < path_flow) ? rGraph[u][v] : path_flow;
        }

        // Update residual capacities of the edges and reverse edges
        // along the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
        
        // Reset parent array for next BFS
        for (int i = 0; i < V; i++) {
            parent[i] = -1;
        }
    }

    // Free dynamically allocated memory
    free(parent);
    for (u = 0; u < V; u++) {
        free(rGraph[u]);
    }
    free(rGraph);

    // Return the overall flow (max_flow)
    return max_flow;
}

// Driver program to test above functions
int main() {
    int V, s, t;
    
    // Get the number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    
    // Dynamically allocate memory for the graph
    int **graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph[i] = (int*)malloc(V * sizeof(int));
    }
    
    // Get the source and sink vertices
    printf("Enter the source vertex (0 to %d): ", V-1);
    scanf("%d", &s);
    printf("Enter the sink vertex (0 to %d): ", V-1);
    scanf("%d", &t);
    
    // Input the capacity of each edge
    printf("Enter the capacity of each edge (enter 0 if there's no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Capacity from vertex %d to vertex %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    
    // Calculate and print the maximum flow
    printf("\nThe maximum possible flow is %d\n", fordFulkerson(graph, V, s, t));
    
    // Free dynamically allocated memory
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);
    
    return 0;
}