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


struct node* positionInsert( struct node *root, int pos, int val )
{
	struct node *temp;
	temp = root;
	if ( root == NULL )
	{
		if ( pos == 1 ) root = createNode( val );
		else printf("Invalid Operation -> Position Out of Bounds\n");
	}
	else if( pos == 1 )
	{
		struct node *new=createNode( val );
		new->next = root;
		root = new;
	}
	else if( pos > 1)
	{
		int i;
		for( i=1; i<pos-1; i++)
		{
			if( temp->next == NULL ) 
			{
				printf("Invalid Operation -> Position Out of Bounds\n");
				return root;
			}			
			temp = temp->next;
		}
		struct node *new =createNode( val );
		new->next = temp->next;
		temp->next = new; 
		
	}
	else printf("Invalid Operation -> Position Out of Bounds\n");

	return root;
}
//------------------------------------------------------------


struct node* frontDelete( struct node *root )
{
	if( root == NULL ) printf("No element To delete\n");
	else
	{
		root = root->next;
	}
	return root;
}

struct node* endDelete( struct node *root )
{
	if( root == NULL ) printf("No element To delete\n");
	else if ( root-> next == NULL ) root = NULL;
	else
	{
		struct node *temp;
		temp = root;
		while( temp->next->next != NULL ) temp = temp->next;
		temp->next = NULL;		
	}
	return root;
}

struct node* positionDelete( struct node *root, int pos )
{
	if( root == NULL ) printf("No element To delete\n");
	else if( pos == 1) root = root->next;
	else if( pos > 1 )
	{
		int i;
		struct node *temp;
		temp = root;
		for( i=1; i<pos-1; i++ )
		{
			if( temp->next->next == NULL ) 
			{
				printf("Invalid Operation -> Position Out of Bounds\n");
				return root;
			}
			temp = temp->next;
		}
		temp->next = temp->next->next;
	}
	else printf("Invalid Operation -> Position Out of Bounds\n");
	return root;
}

struct node* valueDelete( struct node *root, int val )
{
	if( root == NULL ) printf("No element To delete\n");
	else if( root->val == val ) root = root->next;
	else
	{	
		struct node *temp;
		temp = root;
		while( temp->next != NULL )
		{
			if( temp->next->val == val ) break;
			temp = temp->next;
		}
		if ( temp->next == NULL ) printf("No Such Element Found\n");
		else temp->next = temp->next->next;
	}
	return root;
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
		printf("Front Insert\t\t\t1\nEnd Insert\t\t\t2\nPosition Insert\t\t\t3\nFront Delete\t\t\t4\nEnd Delete\t\t\t5\nPosition Delete\t\t\t6\nValue Delete\t\t\t7\nExit\t\t\t\t0\nChoice\t:\t");
		scanf("%d",&c);
		if( c==1 || c==2 || c==3 ) 
		{
			int val;
			printf("Val \t:\t");
			scanf("%d",&val);
			if (c==1) root = frontInsert( root, val );
			else if(c==2) root = endInsert( root, val );
			else {
				int pos;
				printf("Pos \t:\t");
				scanf("%d",&pos);
				root = positionInsert( root, pos, val );
			}
		}
		else if( c==4 ) root = frontDelete( root );
		else if( c==5 ) root = endDelete( root );
		else if( c==6 ) 
		{
			int pos;
			printf("Pos \t:\t");
			scanf("%d",&pos);
			root = positionDelete( root, pos );
		}	
		else if( c==7 ) 
		{
			int val;
			printf("Val \t:\t");
			scanf("%d",&val);
			root = valueDelete( root, val );
		}	
		display( root );
	}
}

