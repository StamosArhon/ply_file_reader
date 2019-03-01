/* HEADER GUARD: preventing double include */
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "vertex.h"
/* ----------Tree Definition---------- */
typedef struct VertexTree
{
  Vertex *vertex_data;
  struct VertexTree* left_node;
  struct VertexTree* right_node;
} VertexTree;
/* ----------Tree Definitions---------- */

/* ----------Function Prototypes---------- */
VertexTree* createNewNode(Vertex *vertex_data);
VertexTree* insertData(VertexTree* root, Vertex *vertex_data);
VertexTree* clearMemory();
void treePrint (VertexTree* root);
/* ----------Function Prototypes---------- */

#endif /* BINARYTREE_H */
