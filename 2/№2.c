#include <stdio.h>
#include <stdlib.h>
struct yzel
{
    int verh;
    struct yzel* next;
};
struct yzel* newyzel(int v);
struct Graph
{
    int numVertices;
    int* zahod;
    struct yzel** list; 
};
struct Graph* newGraph(int);
void addend(struct Graph*, int, int);
void printGraph(struct Graph*);
void DFS(struct Graph*, int);
int main()
{
    struct Graph* graph = newGraph(4);
    addend(graph, 0, 1);
    addend(graph, 0, 2);
    addend(graph, 1, 2);
    addend(graph, 2, 3);
    printGraph(graph);
    DFS(graph, 2);
    return 0;
}
void DFS(struct Graph* graph, int verh) {
        struct yzel* list = graph->list[verh];
        struct yzel* temp = list;
        graph->zahod[verh] = 1;
        printf("Вход %d \n", verh);
        while(temp!=NULL) {
            int pVerh = temp->verh;
            if(graph->zahod[pVerh] == 0) {
                DFS(graph, pVerh);
            }
            temp = temp->next;
        }       
}
struct yzel* newyzel(int v)
{
    struct yzel* newyz = malloc(sizeof(struct yzel));
    newyz->verh = v;
    newyz->next = NULL;
    return newyz;
}
struct Graph* createGraph(int verhs)
{
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = verhs;
    graph->list = malloc(verhs * sizeof(struct yzel*));
    graph->zahod = malloc(verhs * sizeof(int));
    int i;
    for (i = 0; i < verhs; i++) {
        graph->list[i] = NULL;
        graph->zahod[i] = 0;
    }
    return graph;
}
void addend(struct Graph* graph, int src, int dest)
{
    struct yzel* newyz = newyzel(dest);
    newyz->next = graph->list[src];
    graph->list[src] = newyz;
    newyz = newyzel(src);
    newyz->next = graph->list[dest];
    graph->list[dest] = newyz;
}
void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct yzel* temp = graph->list[v];
        printf("\n Список вершин %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->verh);
            temp = temp->next;
        }
        printf("\n");
    }
}
