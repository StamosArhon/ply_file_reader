/* HEADER GUARD: preventing double include */
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "vertex.h"
/* ----------Tree Definition---------- */
typedef struct VertexTree
{
  int vertex_node_id;
  Vertex *vertex_data;
  struct VertexTree* left_node;
  struct VertexTree* right_node;
} VertexTree;
/* ----------Tree Definitions---------- */

/* ----------Function Prototypes---------- */
VertexTree* createNewNode(Vertex *vertex_data, int vertex_node_id);
VertexTree* insertData(VertexTree* root, Vertex *vertex_data, int vertex_node_id);
//void treeMemoryErase (VertexTree* root)
void treePrint (VertexTree* root, int elements, int properties);
/* ----------Function Prototypes---------- */

#endif /* BINARYTREE_H */
