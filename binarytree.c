/*========================================================================================================*/
#include <stdio.h>
#include <stdlib.h>

#include "binarytree.h"
/*========================================================================================================*/

/*---MACROS---*/
#define MAX_LINE_SIZE 81
/*---MACROS---*/

/*========================================================================================================*/

/*----------Global Variables----------*/
int i,j; //Itterators
//VertexTree* root; //Initialize the tree as blank
/*----------Global Variables----------*/

/*========================================================================================================*/

/*-------   CreateNode: A Function that creates a new node in the binary tree    ------*/
/*-------   with three slots, one for the left child, one for the righ and one   ------*/
/*-------   for the data we want each node to hold, in this case the coordinates ------*/
VertexTree* createNode(Vertex* vertex_data, int vertex_node_id)
{
	VertexTree* newNode = (VertexTree*)malloc(sizeof(VertexTree));
	newNode->vertex_node_id = vertex_node_id;
	newNode->vertex_data = vertex_data;
	newNode->left_node = newNode->right_node = NULL;
	return newNode;
}
/*-------   CreateNode: A Function that creates a new node in the binary tree    ------*/
/*-------   with three slots, one for the left child, one for the righ and one   ------*/
/*-------   for the data we want each node to hold, in this case the coordinates ------*/

/*========================================================================================================*/

/*------- InsertData: A function that checks the binary tree in regards to the inserted value -------*/
/*------- and places the value in the appropriate node. If the necessary node does not exist  -------*/
/*------- it creates a new one with a call to the "CreateNode" function                       -------*/
VertexTree* insertData(VertexTree* root, Vertex *vertex_data, int vertex_node_id)
{
	if (root == NULL) //If the root is blank create a new node
	{
		root = createNode(vertex_data, vertex_node_id);
	}

	else if (vertex_data <= root->vertex_data) //If the inserted value is smaller than the root, place it on the left child of that tree
	{
		root->left_node = insertData(root->left_node, vertex_data, vertex_node_id);
	}

	else //If the inserted value is higher than the root, place it on the right child of that tree
	{
		root->right_node = insertData(root->right_node, vertex_data, vertex_node_id);
	}

	return root;
}
/*------- InsertData: A function that checks the binary tree in regards to the inserted value -------*/
/*------- and places the value in the appropriate node. If the necessary node does not exist  -------*/
/*------- it creates a new one with a call to the "CreateNode" function                       -------*/

/*========================================================================================================*/

/*----- TreeSearch: A function to help us locate whether or not a specific value is present -----*/
/*----- in our binary tree or nor, generating the appropriate message and exit in response  -----*/
void treePrint (VertexTree* root, int elements, int properties)
{
	if (root == NULL)
	{
		return;
	}

	else
	{
		for (i = 0; i < properties; i++)
		{
			printf ("%.1f\t", root->vertex_data->properties[i]);
		}
		printf ("\n");
		treePrint (root->left_node, elements, properties);
		treePrint (root->right_node, elements, properties);
	}
}
void treeMemoryErase (VertexTree* root)
{
	if (root == NULL)
		return;

	else
	{
		free (root);
		treeMemoryErase (root->left_node);
		treeMemoryErase (root->right_node);
	}
}
