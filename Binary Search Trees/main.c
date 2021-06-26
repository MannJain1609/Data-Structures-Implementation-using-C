#include<stdio.h>
#include "binary_tree.h"

int main()
{
	struct node *root=NULL;
	root=insert(root,12);
	//inorder(root);
	//printf("\n");
	root=insert(root,10);
	//inorder(root);
	//printf("\n");
	root=insert(root,2);
	//inorder(root);
	//printf("\n");
	root=insert(root,24);
	//inorder(root);
	//printf("\n");
	root=insert(root,5);
	//inorder(root);
	//printf("\n");
	root=insert(root,11);
	inorder(root);
	printf("\n");
	/*preorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	printf("min. value: %d\n", minimum(root));
	printf("max. value: %d\n", maximum(root));*/
	root=delete(root,5);
	inorder(root);
	printf("\n");
	root=delete(root,5);
	inorder(root);
	printf("\n");
	root=delete(root,24);
	inorder(root);
	printf("\n");
	root=delete(root,10);
	inorder(root);
	printf("\n");
	root=delete(root,12);
	inorder(root);
	printf("\n");
	root=delete(root,11);
	inorder(root);
	printf("\n");
	root=delete(root,2);
	inorder(root);
	printf("\n");
	root=delete(root,12);
	inorder(root);
	printf("\n");
	return 0;
}