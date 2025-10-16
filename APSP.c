#include <stdio.h> 
#define INF 99999 
 
void printMatrix(int V, int dist[][V]); 
void floydWarshall(int V, int graph[][V]); 
 
int main() 
{ 
    int V; 
    printf("Enter the number of vertices: ");       // inputs the number of vertices of graph 
    scanf("%d", &V); 
 
    int graph[V][V]; 
    printf("Enter the adjacency matrix for the graph.\n"); 
    printf("Use 0 for infinity (no direct path).\n"); 
 
    for (int i = 0; i < V; i++) 
    {   // inputs the graph 
        for (int j = 0; j < V; j++) 
        { 
            scanf("%d", &graph[i][j]); 
 
            if (i != j && graph[i][j] == 0) 
            { 
                graph[i][j] = INF; 
            } 
        } 
    } 
 
    // Run the Floyd-Warshall algorithm 
    floydWarshall(V, graph); 
 
    return 0; 
} 
 
// A utility function to print the solution matrix 
void printMatrix(int V, int dist[][V]) 
{ 
    printf("\nShortest distances between every pair of vertices:\n"); 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            if (dist[i][j] == INF) 
                printf("%7s", "INF"); 
            else 
                printf("%7d", dist[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
// Implements the Floyd-Warshall algorithm for all-pairs shortest paths. 
void floydWarshall(int V, int graph[][V]) 
{ 
    int dist[V][V]; 
    int i, j, k; 
 
    // Initialize the solution matrix same as input graph matrix 
    for (i = 0; i < V; i++) 
        for (j = 0; j < V; j++) 
            dist[i][j] = graph[i][j]; 
 
    // Add all vertices one by one to the set of intermediate vertices. 
    for (k = 0; k < V; k++) 
    { 
        // Pick all vertices as source one by one 
        for (i = 0; i < V; i++) 
        { 
            // Pick all vertices as destination for the above picked source 
            for (j = 0; j < V; j++) 
            { 
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j] 
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) 
                { 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
                } 
            } 
        } 
    } 
 
    // Print the shortest distance matrix 
    printMatrix(V, dist); 
} 