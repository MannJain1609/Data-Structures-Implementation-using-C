struct max_heap
{
	int size;
	int arr[100];
};

//initialize the heap
void initialize(struct max_heap *);

//returns the parent position of that position
int parent(int );

//returns the left child position of that position
int left_child(int );

//returns the right child position of that position
int right_child(int );

//return 1 if it is a leaf node else zero
int isLeaf_node(struct max_heap *, int );

//to get the index of max value among parent, left and right child
int get_max_index(struct max_heap *, int );

//make a max heap at a particular index
void max_heapify(struct max_heap *, int );

//builds a heap
struct max_heap build_heap(int [],int );

//extracts the maximum value from heap
int extract_max(struct max_heap *);
