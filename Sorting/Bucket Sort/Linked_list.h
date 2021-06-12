struct node
{
	double data;
	struct node *next;
};

//position starts from 0 index

//to create a node with the value pointing to NULL
struct node * create_node(double );

//to insert any element at begin
struct node * insert(struct node *, double );

//to sort the linked list
struct node *sort(struct node *);
