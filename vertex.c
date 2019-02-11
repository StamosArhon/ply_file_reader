#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vertex.h"

#define MAX_LINE_SIZE 81

void read_vertices(char *filename, Vertex **p_vertex_array, int elems, int props)
{
  FILE *input = fopen(filename, "r");
  char *line = malloc(MAX_LINE_SIZE*sizeof(char));
  size_t line_sz;
  char *token;
  int i, j;

  Vertex *p_vertex;

  while (getline(&line, &line_sz, input) >= 0 && !strstr(line, "end_header")) {}

  for (i = 0; i < elems; i++) {
    if (getline(&line, &line_sz, input) < 0) break;

    p_vertex = malloc(sizeof(Vertex));
    p_vertex->properties = malloc(props*sizeof(float));

    token = strtok(line, " ");
    p_vertex->properties[0] = atof(token);

    for (j = 1; j < props; j++) {
      token = strtok(NULL, " ");
      p_vertex->properties[j] = atof(token);
    }

    p_vertex_array[i] = p_vertex;
  }

  free(line);
  fclose(input);
}
