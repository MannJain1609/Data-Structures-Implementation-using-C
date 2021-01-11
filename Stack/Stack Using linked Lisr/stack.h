#include "Linked_list.h"

struct Stack
{
	struct node *head;
	int count;
};

/*To push in stack*/
void push(struct Stack *,int );

/*To pop/delete from stack*/
int pop(struct Stack *);

/*To check whether the stack is empty or not*/
int isEmpty(struct Stack *);

/*To initialise the stack*/
void initialise(struct Stack *);

int count_of_elements(struct Stack *);