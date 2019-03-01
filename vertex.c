#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vertex.h"
#include "binarytree.h"

#define MAX_LINE_SIZE 81

/*----------Global Variables----------*/
VertexTree* root = NULL; //Initialize the tree as blank
/*----------Global Variables----------*/

void read_vertices(char *filename, int elems, int props)
{
  FILE *input = fopen(filename, "r");
  char *line = malloc(MAX_LINE_SIZE*sizeof(char));
  size_t line_sz;
  char *token;
  ssize_t read;
  int i, j;
  //float vertex_data;
  Vertex *vertex_data;

  while ((read = getline(&line, &line_sz, input)) >= 0)
  {
    if (strstr(line, "end_header"))
    {
      for (i = 0; i < elems; i++)
      {
        if (getline(&line, &line_sz, input) < 0)
          break;

        token = strtok(line, " ");
        vertex_data = malloc(sizeof(Vertex));
        vertex_data->properties = malloc(props*sizeof(float));
        vertex_data->properties[0] = atof(token);

        for (j = 1; j < props; j++)
        {
          token = strtok(NULL, " ");
          vertex_data->properties[j] = atof(token);
        }

        insertData(root, vertex_data);
      }
    }
  }
  free(line);
  fclose(input);
}
