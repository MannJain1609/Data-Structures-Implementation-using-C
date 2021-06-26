struct node
{
	int data;
	struct node* right_child;
	struct node* left_child;
	struct node* parent;	
};

//to create a new node
struct node * create_node(int );

//to insert a value in tree
struct node* insert(struct node *, int );

//internal function for insert, no need to call by user
struct node * insert_value(struct node *, struct node *, int );

//to print the tree in a sorted order
//LDR
void inorder(struct node *);

//printing values of tree
//DLR
void preorder(struct node *);

//printing values of tree
//LRD
void postorder(struct node *);

//returns the node where key is present else NULL
struct node* search(struct node*, int );

//returns the minimum value in tree
int minimum(struct node *);

//returns the maximum value in tree
int maximum(struct node *);

//returns the number just greater than the node value in the tree
int successor(struct node *);

//returns the number just less than the node value in the tree
int predecessor(struct node *);

//transplates two nodes i.e replaces one node by another
void transplant(struct node* , struct node* );

//delete a key.
struct node * delete(struct node *, int);