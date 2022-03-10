struct node
{
	int value;
	struct node* next;
};

//implementation using adjacency list
struct adjList
{
	struct node* head;
};

struct graph
{
	int size;
	//size = number of vertices
	struct adjList* adj_list;
};

struct node* create_node(int );
//v= number of vertices in the graph

struct graph* create_graph(int );

void PrintGraph(struct graph* );