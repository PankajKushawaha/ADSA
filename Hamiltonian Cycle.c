 #include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
 
// A structure to represent the graph 
typedef struct 
{ 
    int V;          // Number of vertices 
    int** graph;    // Adjacency matrix 
    int* path;      // To store the Hamiltonian cycle 
} Graph; 
 
// Function prototypes 
bool is_safe(Graph* g, int v, int pos); 
bool hamiltonian_cycle_util(Graph* g, int pos); 
void print_solution(Graph* g); 
bool find_hamiltonian_cycle(Graph* g); 
 
// Driver Code 
int main() 
{ 
    int V; 
    printf("Enter the number of vertices: "); 
    scanf("%d", &V); 
 
    // Allocate memory for the graph structure 
    Graph* g = (Graph*)malloc(sizeof(Graph)); 
    g->V = V; 
 
    // Allocate memory for the path array 
    g->path = (int*)malloc(V * sizeof(int)); 
 
    // Allocate memory for the adjacency matrix (graph) 
    g->graph = (int*)malloc(V * sizeof(int)); 
    for (int i = 0; i < V; i++) 
    { 
        g->graph[i] = (int*)malloc(V * sizeof(int)); 
    } 
 
    printf("Enter the adjacency matrix (0 or 1):\n"); 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            scanf("%d", &g->graph[i][j]); 
        } 
    } 
 
    find_hamiltonian_cycle(g); 
 
    // Free all dynamically allocated memory 
    for (int i = 0; i < V; i++) 
    { 
        free(g->graph[i]); 
    } 
    free(g->graph); 
    free(g->path); 
    free(g); 
 
    return 0; 
} 
 
bool is_safe(Graph* g, int v, int pos) 
{ 
    // Check if this vertex is an adjacent vertex of the previously added vertex. 
    if (g->graph[g->path[pos - 1]][v] == 0) 
    { 
        return false; 
    } 
 
    // Check if the vertex has already been included in the path. 
    for (int i = 0; i < pos; i++) 
    { 
        if (g->path[i] == v) 
        { 
            return false; 
        } 
    } 
    return true; 
} 
 
bool hamiltonian_cycle_util(Graph* g, int pos) 
{ 
    // Base case: If all vertices are included in the path 
    if (pos == g->V) 
    { 
        // And if there is an edge from the last included vertex to the first vertex 
        if (g->graph[g->path[pos - 1]][g->path[0]] == 1) 
        { 
            return true; 
        } 
        else 
        { 
            return false; 
        } 
    } 
 
    // Try different vertices as a next candidate in Hamiltonian Cycle. 
    for (int v = 1; v < g->V; v++) 
    { 
        if (is_safe(g, v, pos)) 
        { 
            g->path[pos] = v; 
 
            // Recur to construct the rest of the path 
            if (hamiltonian_cycle_util(g, pos + 1)) 
            { 
                return true; 
            } 
 
            // If adding vertex v doesn't lead to a solution, then remove it (backtrack) 
            g->path[pos] = -1; 
        } 
    } 
    return false; 
} 
 
void print_solution(Graph* g) 
{ 
    printf("Hamiltonian Cycle found:\n"); 
    for (int i = 0; i < g->V; i++) 
    { 
        printf("%d ", g->path[i]); 
    } 
    // Print the first vertex again to show the complete cycle 
    printf("%d\n", g->path[0]); 
} 
 
bool find_hamiltonian_cycle(Graph* g) 
{ 
    // Initialize the path array with -1 
    for (int i = 0; i < g->V; i++) 
    { 
        g->path[i] = -1; 
    } 
    g->path[0] = 0; 
 
    if (!hamiltonian_cycle_util(g, 1)) 
{ 
printf("Solution does not exist\n"); 
return false; 
} 
print_solution(g); 
return true; 
} 