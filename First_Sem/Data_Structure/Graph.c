//Undirected Graph using matrix

#include <stdio.h>
#define MAX 10

int main()
{
    int i,j,source,destination;
    int vertices,edges;

    int graph[MAX][MAX];

    printf("\n");
    printf("Enter number of vertices: ");
    scanf("%d",&vertices);

    printf("Enter number of edges: ");
    scanf("%d",&edges);

    for(i=0;i<vertices;i++)
    {
        for(j=0;j<vertices;j++)
        {
            graph[i][j]=0;
        }
    }

    printf("Enter the edges(Source to Destination):\n");
    for(i=0;i<edges;i++)
    {
        scanf("%d  %d",&source , &destination);
        graph[source][destination]=1;
        graph[destination][source]=1;

    }

    printf("Adjacency Matrix is:\n");
    for(i=0;i<vertices;i++)
    {
        for(j=0;j<vertices;j++)
        {
            printf(" %d ",graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}