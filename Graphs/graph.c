#include<stdio.h>
#include<stdlib.h>
#include "graph.h"

struct node* create_node(int val)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node)); 
	//To save temp in memory even after function end
	temp->value=val;
	temp->next=NULL;
	return temp;
}


struct graph* create_graph(int v)
{
	struct graph* g = (struct graph *)malloc(sizeof(struct graph));
	g->size = v;
	g->adj_list = (struct adjList *)malloc(v*sizeof(struct adjList));

	int i;
	for(i=0; i<v; i++)
	{
		g->adj_list[i].head = NULL;
	}
	return g;
}

//undirected graph...adding edge from src to dest and from dest to src
void addEdge(struct graph* g, int src, int dest)
{
	struct node* new = create_node(dest);

	if (g->adj_list[src].head==NULL)
	{
		//new->next = g->adj_list[src].head;
		g->adj_list[src].head = new;
	}
	else
	{
		struct node* temp = g->adj_list[src].head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next = new;
	}

	new = create_node(src);

	if (g->adj_list[dest].head==NULL)
	{
		//new->next = g->adj_list[dest].head;
		g->adj_list[dest].head = new;
	}
	else
	{
		struct node* temp = g->adj_list[dest].head;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next = new;
	}
}

void PrintGraph(struct graph* g)
{
	int v;
    for (v = 0; v < g->size; v++) 
    {
        struct node* temp = g->adj_list[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (temp) 
        {
            printf("-> %d", temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}