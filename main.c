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
  int line_change = 0;
  Header *p_header = malloc(sizeof(Header));
  GenericTree *VertexTree = NewGenericTree();

  read_header("cube.ply", p_header);

  //read_vertices("cube.ply", VertexTree, p_header->elements[EL_VERTEX], p_header->el_props[EL_VERTEX]);

  /*------Print Tree------*/
  printf ("\n=========");
  printf ("\nVertices:");
  printf ("\n=========\n\n");
  //printGenericTree (VertexTree->root, line_change);
  /*------Print Tree------*/


  /*------Memory clean-up------*/
  free(p_header);
  //EmptyGenericTree(VertexTree);
  //FreeGenericTree(VertexTree);
  /*------Memory clean-up------*/

  return 0;
}
