#include <stdio.h>  
#include <stdbool.h>  
#include <limits.h>  
#include <stdlib.h>  
 
int minDistance(int dist[], bool visited[], int n);  
void printSolution(int dist[], int n);  
void dijkstra(int** graph, int src, int n);  
 
int main()   
{  
    int n;  
    printf("Enter the number of vertices in the graph: ");  
    scanf("%d", &n);  
 
    if (n <= 0)   
    {  
        printf("Number of vertices must be positive.\n");  
        return 1;  
    }  
 
    // Dynamically allocate memory for the adjacency matrix  
    int** graph = (int*)malloc(n * sizeof(int));  
    if(graph == NULL)   
    {  
        printf("Memory allocation failed!\n");  
        return 1;  
    }  
    for (int i = 0; i < n; i++)   
    {  
        graph[i] = (int*)malloc(n * sizeof(int));  
        if(graph[i] == NULL)   
        {  
            printf("Memory allocation failed!\n");  
            // Free previously allocated rows  
            for(int j = 0; j < i; j++) free(graph[j]);  
            free(graph);  
            return 1;  
        }  
    }  
 
    printf("Enter the adjacency matrix for the graph (use 0 for no direct path):\n");  
    for (int i = 0; i < n; i++)   
    {  
        for (int j = 0; j < n; j++)   
        {  
            scanf("%d", &graph[i][j]);  
        }  
    }  
 
    int source_vertex;  
    printf("Enter the source vertex (0 to %d): ", n - 1);  
    scanf("%d", &source_vertex);  
      
    if (source_vertex < 0 || source_vertex >= n)   
    {  
        printf("Invalid source vertex.\n");  
        // Free allocated memory before exiting  
        for (int i = 0; i < n; i++) free(graph[i]);  
        free(graph);  
        return 1;  
    }  
 
    printf("\nRunning Dijkstra's Algorithm from source vertex %d...\n", source_vertex);  
    dijkstra(graph, source_vertex, n);  
 
    // Free the dynamically allocated memory for the graph  
    for (int i = 0; i < n; i++)   
    {  
        free(graph[i]);  
    }  
    free(graph);  
 
    return 0;  
}  
 
int minDistance(int dist[], bool visited[], int n)   
{  
    // Initialize min value  
    int min = INT_MAX, min_index = -1;  
 
    for (int v = 0; v < n; v++)   
    {  
        if (visited[v] == false && dist[v] <= min)   
        {  
            min = dist[v];  
            min_index = v;  
        }  
    }  
 
    return min_index;  
}  
 
void printSolution(int dist[], int n)   
{  
    printf("\nVertex \t\t Distance from Source\n");  
    for (int i = 0; i < n; i++)   
    {  
        if (dist[i] == INT_MAX)   
        {  
            printf("%d \t\t INF\n", i);  
        }   
        else   
        {  
            printf("%d \t\t %d\n", i, dist[i]);  
        }  
    }  
}  
 
void dijkstra(int** graph, int src, int n)   
{  
    int* dist = malloc(n * sizeof(int));  
    bool* visited = malloc(n * sizeof(bool));  
 
    if (dist == NULL || visited == NULL)   
    {  
        printf("Memory allocation failed!\n");  
        return;  
    }  
 
    // Initialize all distances as INFINITE and visited[] as false  
    for (int i = 0; i < n; i++)   
    {  
        dist[i] = INT_MAX;  
        visited[i] = false;  
    }  
 
    // Distance of source vertex from itself is always 0  
    dist[src] = 0;  
 
    // Find shortest path for all vertices  
    for (int count = 0; count < n - 1; count++)   
    {  
        // Pick the minimum distance vertex from the set of vertices not yet processed  
        int u = minDistance(dist, visited, n);  
          
        // If no vertex is picked, remaining vertices are unreachable  
        if (u == -1) break;  
 
        // Mark the picked vertex as visited  
        visited[u] = true;  
 
        // Update dist value of the adjacent vertices of the picked vertex  
        for (int v = 0; v < n; v++)   
        {  
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&  
                dist[u] + graph[u][v] < dist[v])   
            {  
                dist[v] = dist[u] + graph[u][v];  
            }  
        }  
    }  
 
    // Print the constructed distance array  
    printSolution(dist, n);  
      
    // Free allocated memory  
    free(dist);  
    free(visited);  
} 