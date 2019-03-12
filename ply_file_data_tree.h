/** @file generic_tree.h
 *  @brief Function prorotypes for the generic tree implementation.
 *
 *  This contains all the necessary functions to create, interact with
 *  and delete a binary search tree (BST). Each node of the tree has an id.
 *  The data must be allocated by the user but will be freed by the respective
 *  functions provided.
 */

#ifndef PLY_FILE_DATA_TREE_H
#define PLY_FILE_DATA_TREE_H

/* Structs and macros */
typedef struct GenericTreeNode
{
  int id; /**< The id of each node */
  char *sub_id;
  void *data; /**< The data that carrys the node. This must be allocated by the user. */
  struct GenericTreeNode *left; /**< The left branch of the node */
  struct GenericTreeNode *right; /**< The right branch of the node */
} GenericTreeNode;

typedef struct GenericTree
{
  GenericTreeNode *root; /**< The root of the tree */
  int items; /**< The number of elements stored in the tree */
} GenericTree;

/* Generic Tree Functions */

/** @brief Creates new Binary Tree
 *
 *  This function allocates and initializes a pointer to an empty binary search tree.
 *
 *  @return The newly created tree.
 */
GenericTree *NewGenericTree(void);

/** @brief Inserts new data in a BST.
 *
 *  The tree must be created before inserting data. The data must
 *  be allocated by the user. Note that in case of an existing node with the same id,
 *  the node will be replaced. Old data will be freed.
 *
 *  @param tree The address of the tree where the data will be inserted.
 *  @param id The id of new data.
 *  @param data The address of the data to be added.
 *
 *  @return void
 */
GenericTreeNode *InsertGenericTreeData(GenericTree *tree, int id, char *sub_id, void *data);

/** @brief Delete a node from a tree, based on its id.
 *
 *  This function deletes a node from the tree based on the given id.
 *
 *  @param tree The address of the tree from which the node must be deleted.
 *  @param id the id of the node to be deleted.
 *
 *  @return void
 */
void DeleteGenericTreeNode(GenericTree *tree, int id, char *sub_id);

/** @brief Empty a tree without deleting it
 *
 *  This function Removes all the nodes from a tree, but the tree can be used for
 *  new data.
 *
 *  @param tree The address of the tree to be emptied.
 *
 *  @return void
 */
void EmptyGenericTree(GenericTree *tree);

/** @brief Empty a tree and then delete it.
 *
 *  This function deletes a tree and all its contents. The tree can not be
 *  used.
 *
 *  @param tree The address of the tree to be deleted.
 *
 *  @return void
 */
void FreeGenericTree(GenericTree *tree);

/** @brief Prints the sub-nodes of a root node, in ascending order.
 *
 *  This function starts from a tree node and prints all the sub-nodes in an
 *  ascending order.
 *
 *  @param root The address of the tree root node from which to start the iteration.
 *
 *  @return void
 */
void printGenericTree(GenericTreeNode *root, int line_change, int properties);

#endif // PLY_FILE_DATA_TREE_H
