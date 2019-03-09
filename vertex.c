#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vertex.h"

#define MAX_LINE_SIZE 81

void read_vertices(char *filename, GenericTree *VertexTree, int elems, int props)
{
  FILE *input = fopen(filename, "r");
  char *line = malloc(MAX_LINE_SIZE*sizeof(char));
  size_t line_sz;
  char *token;
  ssize_t read;
  int i, j;
  int id = 1;
  float *vertex_data = malloc((elems*props)*sizeof(float)); //Question: Do I need to clear the memory for that or does the "FreeGenericTree" cover it? Because I can't clear the memory for it inside this file since that will effect the printGenericTree function and I cant clear the memory in main because it doesnt "see" this variable (is making it a global variable viable option?)

  //char *vertex_id [3] = {"x", "y", "z"};
  //int vertex_data_node_id;
  //Vertex *p_vertex;

  while ((read = getline(&line, &line_sz, input)) >= 0)
  {
    if (strstr(line, "end_header"))
    {
      for (i = 0; i < elems; i++)
      {
        if (getline(&line, &line_sz, input) < 0)
          break;

        token = strtok(line, " ");
        vertex_data[id-1] = atof(token);

        InsertGenericTreeData(VertexTree, id, &vertex_data[id-1]);
        id++;

        for (j = 1; j < props; j++)
        {
          token = strtok(NULL, " ");
          vertex_data[id-1] = atof(token);
          InsertGenericTreeData(VertexTree, id, &vertex_data[id-1]);
          id++;
        }
      }
    }
  }
  free(line);
  fclose(input);
}
