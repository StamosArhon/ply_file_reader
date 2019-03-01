#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*-----------Included Project Files-----------*/
#include "header.c"
#include "header.h"
#include "vertex.c"
#include "vertex.h"
#include "binarytree.h"
#include "binarytree.c"
/*-----------Included Project Files-----------*/

int main(void)
{
  int i, j;

  Header *p_header = malloc(sizeof(Header));

  read_header("test_file.ply", p_header);

  read_vertices("test_file.ply", p_header->elements[EL_VERTEX], p_header->el_props[EL_VERTEX]);


  treePrint(root, p_header->elements[EL_VERTEX], p_header->el_props[EL_VERTEX]);

  /* Memory clean-up */
  free(p_header);
  void treeMemoryErase (VertexTree* root);

  return 0;
}
