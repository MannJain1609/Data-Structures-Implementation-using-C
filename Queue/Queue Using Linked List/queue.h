struct node
{
	int data;
	struct node *next;
};
struct queue
{
	struct node *front;
	struct node *rear;
	int count;
};

//To initialize queue
void initialize(struct queue *);

//to display the queue
void display(struct queue *);

//returns 1 if queue is empty else 0
int isEmpty(struct queue *);

//to insert an element in queue
void insert(struct queue *, int );

//to delete the element in queue and returns the deleted element, in case queue is empty, returns -1
int delete(struct queue *);
