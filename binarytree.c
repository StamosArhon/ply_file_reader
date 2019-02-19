/*========================================================================================================*/

#include <stdio.h>
#include <stdlib.h>

/*========================================================================================================*/

/*--------Binary Search Tree Struct Definition--------*/
struct binarySearchTreeNode
{
	float data;
	struct binarySearchTreeNode* left;
	struct binarySearchTreeNode* right;
};
/*--------Binary Search Tree Struct Definition--------*/

/*========================================================================================================*/

/*----------Global Variables----------*/
struct binaryTree* root = NULL; //Initialize the tree as blank
struct binarySearchTreeNode coordinates; //The varibale that will hold the coordinates from the plyfile
int input_data; //
/*----------Global Variables----------*/

/*========================================================================================================*/

/*-------   CreateNode: A Function that creates a new node in the binary tree    ------*/
/*-------   with three slots, one for the left child, one for the righ and one   ------*/
/*-------   for the data we want each node to hold, in this case the coordinates ------*/
struct binaryTree* CreateNode(int data)
{
	struct binaryTree* newNode = (struct binaryTree*)malloc(sizeof(struct binaryTree));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
/*-------   CreateNode: A Function that creates a new node in the binary tree    ------*/
/*-------   with three slots, one for the left child, one for the righ and one   ------*/
/*-------   for the data we want each node to hold, in this case the coordinates ------*/

/*========================================================================================================*/

/*------- InsertData: A function that checks the binary tree in regards to the inserted value -------*/
/*------- and places the value in the appropriate node. If the necessary node does not exist  -------*/
/*------- it creates a new one with a call to the "CreateNode" function                       -------*/
struct binaryTree* InsertData(struct binaryTree* root, int data)
{
	if (root == NULL) //If the root is blank create a new node
	{
		root = CreateNode(data);
	}

	else if (data <= root->data) //If the inserted value is smaller than the root, place it on the left child of that tree
	{
		root->left = InsertData(root->left, data);
	}

	else //If the inserted value is higher than the root, place it on the right child of that tree
	{
		root->right = InsertData(root->right, data);
	}

	return root;
}
/*------- InsertData: A function that checks the binary tree in regards to the inserted value -------*/
/*------- and places the value in the appropriate node. If the necessary node does not exist  -------*/
/*------- it creates a new one with a call to the "CreateNode" function                       -------*/

/*========================================================================================================*/

/*----- TreeSearch: A function to help us locate whether or not a specific value is present -----*/
/*----- in our binary tree or nor, generating the appropriate message and exit in response  -----*/
void TreeSearch(struct binaryTree* root, int data)
{
	if (root == NULL) //If the root is blank print that the value was not found and exit with -1
	{
		printf ("\n+=================================+");
		printf ("\n| Value not found! Terminating... |");
		printf ("\n+=================================+");
		exit(-1);
	}

	else if (root->data == data) //If the data element is equal to the value we are searching for print that the value was found and exit with 0
	{
		printf ("\n+====================================+");
		printf ("\n| Value found! Exiting succefully... |");
		printf ("\n+====================================+");
		exit(0);
	}

	else if (data <= root->data) //If the requested value is smaller than the root, search for it on the left child of that tree
	{
		return Search(root->left, data);
	}

	else
	{
		return Search(root->right, data); //If the requested value is higher than the root, search for it on the right child of that tree
	}
}
/*----- TreeSearch: A function to help us locate whether or not a specific value is present -----*/
/*----- in our binary tree or nor, generating the appropriate message and exit in response  -----*/

/*========================================================================================================*/

/*----The main function of the program that makes the initial calls to the other functions----*/
int main()
{

}
/*----The main function of the program that makes the initial calls to the other functions----*/

/*========================================================================================================*/
																						/*END OF FILE*/
