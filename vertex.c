#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vertex.h"

#define MAX_LINE_SIZE 81

void read_vertices(char *filename, GenericTree *VertexTree, int vertex_elements, int vertex_properties, int *last_vertex_position)
{
  FILE *input = fopen(filename, "r");
  char *line = malloc(MAX_LINE_SIZE*sizeof(char));
  size_t line_sz;
  char *token;
  ssize_t read;
  int i, j;
  int id = 1;
  float *vertex_data = malloc((vertex_elements*vertex_properties)*sizeof(float));
  char *vertex_sub_id [3] = {"x", "y", "z"};

  while ((read = getline(&line, &line_sz, input)) >= 0)
  {
    if (strstr(line, "end_header"))
    {
      for (i = 0; i < vertex_elements; i++)
      {
        if (getline(&line, &line_sz, input) < 0)
          break;

        token = strtok(line, " ");
        vertex_data[id-1] = atof(token);

        InsertGenericTreeData(VertexTree, i+1, vertex_sub_id[0], &vertex_data[id-1]);
        id++;

        for (j = 1; j < vertex_properties; j++)
        {
          token = strtok(NULL, " ");
          vertex_data[id-1] = atof(token);
          InsertGenericTreeData(VertexTree, i+1, vertex_sub_id[j], &vertex_data[id-1]);
          id++;
        }
      }
      *last_vertex_position = ftell(input);
    }
  }
  free(line);
  fclose(input);
}
