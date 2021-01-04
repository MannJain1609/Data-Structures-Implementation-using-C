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

//to display the linked list in console
void display_list(struct node *);

//to insert any value at last
struct node * insert_at_last(struct node *, int );

//to insert at a valid position of node
struct node * insert_at_pos(struct node *, int , int );

//to get the number of nodes from a particular node of the linked list
int count_nodes(struct node *);

//to insert element at a sorted position in a sorted linked list
struct node * insert_at_sorted_pos(struct node * , int );

//to delete the first element from linked list
struct node * delete_first(struct node * );

//to delete the last element of linked list
struct node * delete_last(struct node * );

//to delete an element at a particular position.
struct node * delete_at_pos(struct node * , int );

//to delete the first occurence of a particular value from the linked list
struct node * delete_key(struct node * , int );

//to sort the linked list
struct node *sort(struct node *);