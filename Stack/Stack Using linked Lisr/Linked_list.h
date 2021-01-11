struct node
{
	int data;
	struct node *next;
};

//position starts from 0 index

//to create a node with the value pointing to NULL
struct node * create_node(int );

//to insert any element at begin
struct node * insert_at_begin(struct node *, int );

//to delete the first element from linked list
struct node * delete_first(struct node * );
