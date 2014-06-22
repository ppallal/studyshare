#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};

struct node* createNode( int val )
{
	struct node *new;
	new = malloc(sizeof(struct node));
	new->val = val;
	new->next = NULL;
	return new;
}

//-----------------------------------------------------------



struct node* frontInsert( struct node *root, int val )
{
	if( root == NULL )
	{	
		root = createNode( val );
	}	
	else
	{
		struct node *new;
		new = createNode( val );
		new->next = root;
		root = new;
	}
	return root;
}

struct node* endInsert( struct node *root, int val )
{
	struct node *retRoot;
	retRoot = root;
	if( root == NULL )
	{
		retRoot = createNode( val );
	}
	else{
		while( root->next != NULL ) root = root->next;
		root->next = createNode( val );
	}
	return retRoot;
}

//------------------------------------------------------------
void display( struct node *root )
{
	printf("\n-->");
	while( root!=NULL )
	{
		printf("%4d",root->val);
		root = root->next;
	}	
	printf("\n");	
}


//------------------------------------------------------------

void main()
{
	struct node *root;
	root = NULL;
	int c=1;
	while(c)
	{
		printf("\nWelcome to Pallal's Linked List Program\n");
		printf("Front Insert\t\t\t1\nEnd Insert\t\t\t2\nExit\t\t\t\t0\nChoice\t:\t");
		scanf("%d",&c);
		if( c==1 || c==2 ) 
		{
			int val;
			printf("Val \t:\t");
			scanf("%d",&val);
			if (c==1) root = frontInsert( root, val );
			else root = endInsert( root, val );
		}
		display( root );
	}
}

