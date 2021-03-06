#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.c"
#include "header.h"
#include "vertex.c"
#include "vertex.h"

void print_vertices(Vertex **p_array, int elements, int properties)
{
  int i, j;

  printf("Vertices:\n");
  for (i = 0; i < elements; i++) {
    printf("%i|\t", i+1);
    for (j = 0; j < properties; j++) {
      printf("%f\t", p_array[i]->properties[j]);
    }
    printf("\n");
  }
}

int main(void)
{
  int i, j;
  Header *p_header = malloc(sizeof(Header));
  Vertex **p_vertex_array;

  read_header("test_file.ply", p_header);

  p_vertex_array = malloc(p_header->elements[EL_VERTEX]*sizeof(Vertex));

  read_vertices("test_file.ply", p_vertex_array,
      p_header->elements[EL_VERTEX],
      p_header->el_props[EL_VERTEX]);

  print_vertices(p_vertex_array, p_header->elements[EL_VERTEX], p_header->el_props[EL_VERTEX]);

  /* Memory clean-up */
  free(p_header);
  for (i = 0; i < p_header->elements[EL_VERTEX]; i++) {
    free(p_vertex_array[i]);
  }
  free(p_vertex_array);

  return 0;
}
