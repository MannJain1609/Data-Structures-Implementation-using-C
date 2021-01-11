struct node
{
	int data;
	struct node *next;
};
struct cqueue
{
	struct node *front;
	struct node *rear;
	int count;
};

//To initialize cqueue
void initialize(struct cqueue *);

//to display the cqueue
void display(struct cqueue *);

//returns 1 if cqueue is empty else 0
int isEmpty(struct cqueue *);

//to insert an element in cqueue
void insert(struct cqueue *, int );

//to delete the element in cqueue and returns the deleted element, in case cqueue is empty, returns -1
int delete(struct cqueue *);
