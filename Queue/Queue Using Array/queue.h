struct queue
{
	int arr[10];
	int front;
	int rear;
	int capacity;
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

//returns 1 if the queue is upto its capacity else 0
int isFull(struct queue *);