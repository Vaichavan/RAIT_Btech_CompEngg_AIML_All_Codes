#include <stdio.h>
#include <limits.h>
#include <alloc.h>

#define true 1
#define false 0

struct Edge
{
    int src, dest, weight;
};

struct Graph
{
    int V, E;
    struct Edge *edge;
};

void printDistances(int dist[], int n)
{   int i;
    printf("Vertex   Distance from Source\n");
    for (i = 0; i < n; ++i)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int bellmanFord(struct Graph *graph, int V, int src)
{
    int E = graph->E;
    int *dist = (int *)malloc(V * sizeof(int));
    int i;
    int j;

    for (i = 0; i < V; i++)
    {
	dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (i = 1; i <= V - 1; i++)
    {
	for (j = 0; j < E; j++)
	{
	    int u = graph->edge[j].src;
	    int v = graph->edge[j].dest;
	    int weight = graph->edge[j].weight;
	    if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
	    {
		dist[v] = dist[u] + weight;
	    }
	}
    }

    for (i = 0; i < E; i++)
    {
	int u = graph->edge[i].src;
	int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            free(dist);
            return false;
        }
    }

    printDistances(dist, V);
    free(dist);
    return true;
}

int main()
{
    int src;
    int V;
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = 5;
    graph->E = 8;

    graph->edge = (struct Edge *)malloc(graph->E * sizeof(struct Edge));
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;


    src = 0;
    V = graph->V;

    if (bellmanFord(graph, V, src))
    {
	printf("No negative-weight cycle found.\n");
    }
    else
    {
	printf("Negative-weight cycle found.\n");
    }

    free(graph->edge);
    free(graph);
    getch();
    return 0;
}