#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.c"
#include "header.h"
#include "vertex.c"
#include "vertex.h"

void print_vertices(Vertex **p_array, int elements, int properties)
{
  int i, j; //itterators

  printf("Vertices:\n");
  for (i = 0; i < elements; i++)
  {
    printf("%i|\t", i+1);
    for (j = 0; j < properties; j++)
    {
      printf("%f\t", p_array[i]->properties[j]);
    }
    printf("\n");
  }
}

int main(void)
{
  int i, j; //Itterators
  Header *p_header = malloc(sizeof(Header)); //Assign heap memory space for the Header struct variable "p_header" equal to the size of the Header struct
  Vertex **p_vertex_array; //Declare a Vertex struct variable which is a pointer to a pointer to a Vertex struct

  read_header("test_file.ply", p_header); //Call to the read_header function from the vertex.c file

  p_vertex_array = malloc(p_header->elements[EL_VERTEX]*sizeof(Vertex)); //Assigning heap memory space for the Vertex variable "p_vertex_array" equal to the size of the Vertex struct times the value of the "elements[EL_VERTEX]" element of the Header struct variable "p_header"

  read_vertices("test_file.ply", p_vertex_array, p_header->elements[EL_VERTEX], p_header->el_props[EL_VERTEX]); //Call to the read_vertices function from the vertex.c file

  print_vertices(p_vertex_array, p_header->elements[EL_VERTEX], p_header->el_props[EL_VERTEX]); //Call to the print_vertices function from the main.c file

  /* Memory clean-up */

  free(p_header); //Clear the heap memory space we saved for the Header struct variable "p_header"

  for (i = 0; i < p_header->elements[EL_VERTEX]; i++) //Clear the space we saved in heap memory for every element in the "p_vertex_array"
  {
    free(p_vertex_array[i]);
  }
  free(p_vertex_array); //Free p_vertex_array heap memory

  return 0;
}
