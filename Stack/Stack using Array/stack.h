struct Stack
{
	char arr[100];
	int capacity;
	int top_index;
};

/*To push in stack*/
void push(struct Stack *s,char val);

/*To pop/delete from stack*/
char pop(struct Stack *s);

/*Sometimes top can also be used as peek*/
char top(struct Stack *s);

/*To check whether the stack is empty or not*/
int isEmpty(struct Stack *s);

/*To check whether the stack is full to its capacity or not*/
int isFull(struct Stack *s);

/*To initialise the stack*/
void initialise(struct Stack *s);