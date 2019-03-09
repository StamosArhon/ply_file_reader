#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------Included Project Files-----------*/
#include "header.h"
#include "vertex.h"
#include "ply_file_data_tree.h"
/*-----------Included Project Files-----------*/

int main(void)
{
  int i, j;

  GenericTree *VertexTree = NewGenericTree();
  Header *p_header = malloc(sizeof(Header));
  Vertex **p_vertex_array;

  read_header("test_file.ply", p_header);

  p_vertex_array = malloc(p_header->elements[EL_VERTEX]*sizeof(Vertex));

  read_vertices("test_file.ply", VertexTree, p_header->elements[EL_VERTEX], p_header->el_props[EL_VERTEX]);

  /* Print Tree */
  printGenericTree (VertexTree->root);
  /* Print Tree */


  /* Memory clean-up */
  free(p_header);

  for (i = 0; i < p_header->elements[EL_VERTEX]; i++)
  {
    free(p_vertex_array[i]);
  }

  free(p_vertex_array);

  EmptyGenericTree(VertexTree);
  FreeGenericTree(VertexTree);

  /* Memory clean-up */

  return 0;
}
