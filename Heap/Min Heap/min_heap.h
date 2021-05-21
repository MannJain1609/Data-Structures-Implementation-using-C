struct min_heap
{
	int arr[100];
	int size;
};

//initialize the heap
void initialize(struct min_heap *);

//prints the heap
void print_heap(struct min_heap *);

//returns the parent position of that position
int parent(int );

//returns the left child position of that position
int left_child(int );

//returns the right child position of that position
int right_child(int );

//return 1 if it is a leaf node else zero
int isLeaf_node(struct min_heap *, int );

//to get the index of min value among parent, left and right child
int get_min_index(struct min_heap *, int );

//make a max heap at a particular index
void min_heapify(struct min_heap *, int );

//builds a heap
void build_heap(struct min_heap *);

//puts the new value in heap instead of a value less than the value.
void heapDecreaseKey(struct min_heap *, int , int );

//insert a value in heap at suitable position
void insert(struct min_heap *, int );

//deletes the value at a particular index
int delete(struct min_heap *, int );

//extracts the minimum value from heap
int extract_min(struct min_heap *);

/returns the height of heap
int height_of_heap(struct max_heap *);