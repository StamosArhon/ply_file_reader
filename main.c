#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------Included Project Files-----------*/
#include "header.h"
#include "vertex.h"
#include "faces.h"
#include "ply_file_data_tree.h"
/*-----------Included Project Files-----------*/

int main(void)
{
  int line_change = 0;
  int *last_vertex_position = malloc(sizeof(int));
  Header *p_header = malloc(sizeof(Header));
  GenericTree *VertexTree = NewGenericTree();
  GenericTree *FacesTree = NewGenericTree();

  read_header ("cube.ply", p_header);
  read_vertices ("cube.ply", VertexTree, p_header->elements[EL_VERTEX], p_header->el_props[EL_VERTEX], last_vertex_position);
  read_faces ("cube.ply", FacesTree, p_header->elements[EL_FACE], last_vertex_position);

  /*------Print Vertex Tree------*/
  printf ("\n=========");
  printf ("\nVertices:");
  printf ("\n=========\n\n");
  printGenericTree (VertexTree->root, line_change, p_header->el_props[EL_VERTEX]);
  /*------Print Vertex Tree------*/

  printf ("\n\n");

  /*------Print Faces Tree------*/
  printf ("\n======");
  printf ("\nFaces:");
  printf ("\n======\n\n");
  printGenericTree (FacesTree->root, line_change, 5);
  /*------Print Faces Tree------*/


  /*------Memory clean-up------*/
  free(p_header);
  EmptyGenericTree(VertexTree);
  FreeGenericTree(VertexTree);
  /*------Memory clean-up------*/

  return 0;
}
