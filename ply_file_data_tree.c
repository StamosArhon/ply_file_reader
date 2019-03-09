/** @file generic_tree.c
 *  @brief A Generic Binary Search Tree (BST) implementation.
 *
 *  The term Generic means that each node of the tree can hold a pointer
 *  to any kind of data. For example float *data.
 *
 *  @note The tree implemented here is unballanced.
 *  @note The documentation for each available function is in the
 *        header file. Here you may find functions for internal use,
 *        the documentation is not needed, since the user of the tree
 *        will not use them.
 */

/*=====================================================================================================*/

/*-------System headers-------*/
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
/*-------System headers-------*/

/*-------Custom headers-------*/
#include "ply_file_data_tree.h"
/*-------Custom headers-------*/

/*=====================================================================================================*/

/*----------------Function: NewGenericTree----------------*/

GenericTree *NewGenericTree(void)
{
  GenericTree *new_tree = malloc(sizeof(GenericTree));

  new_tree->items = 0;
  new_tree->root = NULL;

  return new_tree;
}

/*----------------Function: NewGenericTree----------------*/

/*=====================================================================================================*/

/*----------------Function: FreeTreeBranch----------------*/

void FreeTreeBranch(GenericTreeNode *node)
{
  if (node->left != NULL)
  {
    FreeTreeBranch(node->left);
    node->left = NULL;
  }

  if (node->right != NULL)
  {
    FreeTreeBranch(node->right);
    node->right = NULL;
  }

  free(node);
}

/*----------------Function: FreeTreeBranch----------------*/

/*=====================================================================================================*/

/*----------------Function: EmptyGenericTree----------------*/

void EmptyGenericTree(GenericTree *tree)
{
  if (tree->root == NULL)
    return;

  FreeTreeBranch(tree->root);
  tree->root = NULL;
  tree->items = 0;
}

/*----------------Function: EmptyGenericTree----------------*/

/*=====================================================================================================*/

/*----------------Function: FreeTreeBranch----------------*/

void FreeGenericTree(GenericTree *tree)
{
  EmptyGenericTree(tree);
  free(tree);
}

/*----------------Function: FreeTreeBranch----------------*/

/*=====================================================================================================*/

/*----------------Function: NewGenericTree----------------*/

GenericTreeNode *NewGenericTreeNode(int id, void *data)
{
  GenericTreeNode *new_node = malloc(sizeof(GenericTreeNode));

  new_node->id = id;
  new_node->data = data;
  new_node->left = NULL;
  new_node->right = NULL;

  return new_node;
}

/*----------------Function: NewGenericTree----------------*/

/*=====================================================================================================*/

/*----------------Function: SearchNodeById----------------*/

GenericTreeNode *SearchNodeById(int id, GenericTreeNode *node)
{
  if (node == NULL || node->id == id)
    return node;

  if (id < node->id)
    return SearchNodeById(id, node->left);

  else
    return SearchNodeById(id, node->right);
}

/*----------------Function: SearchNodeById----------------*/

/*=====================================================================================================*/

/*----------------Function: FindGenericTreeNode----------------*/

GenericTreeNode *FindGenericTreeNode(int id, GenericTree *tree)
{
  return SearchNodeById(id, tree->root);
}

/*----------------Function: FindGenericTreeNode----------------*/

/*=====================================================================================================*/

/*----------------Function: InsertToBranch----------------*/

GenericTreeNode *InsertToBranch(GenericTreeNode *root, GenericTreeNode *node)
{
  if (root == NULL || node->id == root->id)
    return node;

  if (node->id < root->id)
  {
    root->left = InsertToBranch(root->left, node);
  }

  else
  {
    root->right = InsertToBranch(root->right, node);
  }
}

/*----------------Function: InsertToBranch----------------*/

/*=====================================================================================================*/

/*----------------Function: InsertGenericTreeNode----------------*/

GenericTreeNode *InsertGenericTreeNode(GenericTree *tree, GenericTreeNode *node)
{
  if (FindGenericTreeNode(node->id, tree) != NULL)
  {
    printf("Replacing id: %d\n", node->id);
  }

  else
  {
    tree->items++;
  }

  if (tree->root == NULL)
  {
    tree->root = node;
    return node;
  }

  return InsertToBranch(tree->root, node);
}

/*----------------Function: InsertGenericTreeNode----------------*/

/*=====================================================================================================*/

/*----------------Function: InsertGenericTreeData----------------*/

GenericTreeNode *InsertGenericTreeData(GenericTree *tree, int id, void *data)
{
  GenericTreeNode *new_node = NewGenericTreeNode(id, data);
  return InsertGenericTreeNode(tree, new_node);
}

/*----------------Function: InsertGenericTreeData----------------*/

/*=====================================================================================================*/

/*----------------Function: minIdNode----------------*/

GenericTreeNode *minIdNode(GenericTreeNode *root)
{
  struct GenericTreeNode *node = root;

  while (node->left != NULL)
  {
    node = node->left;
  }

  return node;
}

/*----------------Function: minIdNode----------------*/

/*=====================================================================================================*/

/*----------------Function: DeleteFromBranch----------------*/

struct GenericTreeNode *DeleteFromBranch(struct GenericTreeNode *root, int id)
{
  if (root == NULL)
    return root;

  if (id < root->id)
  {
    root->left = DeleteFromBranch(root->left, id);
  }

  else if (id > root->id)
  {
    root->right = DeleteFromBranch(root->right, id);
  }

  else
  {
    if (root->left == NULL)
    {
      struct GenericTreeNode *temp_node = root->right;
      free(root);
      return temp_node;
    }

    else if (root->right == NULL)
    {
      struct GenericTreeNode *temp_node = root->left;
      free(root);
      return temp_node;
    }

    else
    {
      struct GenericTreeNode *temp_node = minIdNode(root->right);

      root->id = temp_node->id;
      root->data = temp_node->data;

      root->right = DeleteFromBranch(root->right, temp_node->id);
    }
  }

  return root;
}

/*----------------Function: DeleteFromBranch----------------*/

/*=====================================================================================================*/

/*----------------Function: DeleteGenericTreeNode----------------*/

void DeleteGenericTreeNode(struct GenericTree *tree, int id)
{
  if (FindGenericTreeNode(id, tree) != NULL)
  {
    tree->items--;
  }

  else
  {
    printf("There is no data with id: %d\n", id);
    return;
  }

  DeleteFromBranch(tree->root, id);
}

/*----------------Function: DeleteGenericTreeNode----------------*/

/*=====================================================================================================*/

/*----------------Function: printGenericTree----------------*/

void printGenericTree(struct GenericTreeNode *root)
{
	int i,j;
	int elems = 5, props = 3;
  if (root != NULL)
  {
    printGenericTree(root->left);
		for (i=0;i<elems;i++)
		{
			for(j=1;j<props;j++)
			{
				printf("%d: %f\t", root->id, *((float *)root->data->p_vertex_array[i]->p_vertex->properties[j]));
			}
		}
    printGenericTree(root->right);
  }
}

/*----------------Function: printGenericTree----------------*/

/*=====================================================================================================*/
