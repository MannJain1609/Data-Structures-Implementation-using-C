#include<stdio.h>
#include<stdlib.h>
#include "binary_tree.h"
/*
void initialize(struct BST *tree)
{
	tree->root=NULL;
	printf("Me chala\n");
}
*/
struct node * create_node(int val)
{
	struct node *new;
	new=(struct node *)malloc(sizeof(struct node));
	new->data=val;
	new->left_child=NULL;
	new->right_child=NULL;
	new->parent=NULL;
	return new;
}

struct node * insert(struct node *root, int val)
{
	root=insert_value(NULL,root,val);
	return root;
}
struct node * insert_value(struct node *parent, struct node *root, int val)
{
	if (root==NULL)
	{
		struct node *temp=create_node(val);
		temp->parent=parent;
		return temp;
	}
	if (val>root->data)
		root->right_child=insert_value(root,root->right_child,val);
	else if (val<root->data)
		root->left_child=insert_value(root, root->left_child,val);
}

//LDR
void inorder(struct node *root)
{
	if (root==NULL)
		return;
	inorder(root->left_child);	
	printf("%d ", root->data);
	inorder(root->right_child);
}

//DLR
void preorder(struct node *root)
{
	if (root==NULL)
		return;
	printf("%d ", root->data);
	preorder(root->left_child);	
	preorder(root->right_child);
}

//LRD
void postorder(struct node *root)
{
	if (root==NULL)
		return;
	postorder(root->left_child);	
	postorder(root->right_child);
	printf("%d ", root->data);
}

struct node* search(struct node*root, int key)
{
	if (root==NULL)
		return NULL;
	if (root->data==key)
		return root;
	else if (root->data>key)
		return search(root->left_child, key);
	else if (root->data<key)
		return search(root->right_child, key);
}

int minimum(struct node *root)
{
	if (root->left_child==NULL)
		return root->data;
	return minimum(root->left_child);
}

int maximum(struct node *root)
{
	if (root->right_child==NULL)
		return root->data;
	return maximum(root->right_child);
}

int successor(struct node *root)
{
	if (root->right_child!=NULL)
		return minimum(root->right_child);
	struct node* temp=root;
	struct node* y=temp->parent;
	while(y!=NULL  && temp==y->right_child)
	{
		temp=y;
		y=y->parent;
	}
	return y->data;
}

int predecessor(struct node *root)
{
	if (root->left_child!=NULL)
		return maximum(root->left_child);
	struct node* temp=root;
	struct node* y=temp->parent;
	while(y!=NULL  && temp==y->left_child)
	{
		temp=y;
		y=y->parent;
	}
	return y->data;
}

void transplant(struct node* x, struct node* y)
{
	/*if (x->parent==NULL)
	{
		printf("i m here\n");
		x=y;
	}*/
	if (x==x->parent->left_child)
		x->parent->left_child=y;
	else if (x==x->parent->right_child)
		x->parent->right_child=y;
	if (y!=NULL)
		y->parent=x->parent;
	x->parent=NULL;
}

struct node * delete(struct node *root, int key)
{
	struct node* x=search(root,key);
	if (x==NULL)
	{
		printf("There is no such value present in the tree equal to the value %d\n", key);
		return root;
	}
	if (x->left_child==NULL)
	{
		if (x->parent==NULL)
		{
			root=x->right_child;
			x->right_child->parent=NULL;
			x->parent=NULL;
			return root;
		}
		transplant(x,x->right_child);
		return root;
	}
	if (x->right_child==NULL)
	{
		if (x->parent==NULL)
		{
			root=x->left_child;
			x->left_child->parent=NULL;
			x->parent=NULL;
			return root;
		}
		transplant(x,x->left_child);
		return root;
	}
	struct node* y=x->right_child;
	while(y->left_child!=NULL)
		y=y->left_child;
	if (y->parent!=x)
	{
		transplant(y,y->right_child);
		y->right_child=x->right_child;
		y->right_child->parent=y;
	}
	if (x->parent==NULL)
	{
		root=y;
		y->left_child=x->left_child;
		y->left_child->parent=y;
		y->parent=NULL;
		return root;
	}
	transplant(x,y);
	y->left_child=x->left_child;
	y->left_child->parent=y;
	return root;
}
