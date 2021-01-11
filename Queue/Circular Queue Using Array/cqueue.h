struct cqueue
{
	int arr[10];
	int front;
	int rear;
	int capacity;
};

//To initialize queue
void initialize(struct cqueue *);

//to display the queue
void display(struct cqueue *);

//returns 1 if queue is empty else 0
int isEmpty(struct cqueue *);

//to insert an element in queue
void insert(struct cqueue *, int );

//to delete the element in queue and returns the deleted element, in case queue is empty, returns -1
int delete(struct cqueue *);
