/* HEADER GUARD: preventing double include */
#ifndef VERTEX_H
#define VERTEX_H

#include "ply_file_data_tree.h"

/* --------------------------- */
typedef struct Vertex
{
  void *properties;
} Vertex;
/* --------------------------- */

/* --------------------------- */
void read_vertices(char *filename, GenericTree *VertexTree, int elems, int props);
/* --------------------------- */
#endif /* VERTEX_H */
