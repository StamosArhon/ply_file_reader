#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "faces.h"
#include "ply_file_data_tree.h"

#define MAX_LINE_SIZE 81

void read_faces (char *filename, GenericTree *FacesTree, int faces_elements, int *last_vertex_position)
{
  FILE *input = fopen(filename, "r");
  char *line = malloc(MAX_LINE_SIZE*sizeof(char));
  size_t line_sz;
  char *token;
  ssize_t read;
  int i, j;
  int id = 1;
  float *faces_data = malloc((faces_elements*MAX_LINE_SIZE)*sizeof(float));
  float faces_properties;
  char *faces_sub_id [4] = {"1", "2", "3", "4"};

  while ((read = getline(&line, &line_sz, input)) >= 0)
  {
    if (ftell(input) == 273)
    {
      for (i = 0; i < faces_elements; i++)
      {
        if (getline(&line, &line_sz, input) < 0)
          break;

        token = strtok(line, " ");
        faces_data[id-1] = atof(token);
        faces_properties = faces_data[id-1];
        InsertGenericTreeData(FacesTree, i+1, faces_sub_id[0], &faces_data[id-1]);
        id++;

        for (j = 1; j <= faces_properties; j++)
        {
          token = strtok(NULL, " ");
          faces_data[id-1] = atof(token);
          InsertGenericTreeData(FacesTree, i+1, faces_sub_id[j], &faces_data[id-1]);
          id++;
        }
      }
    }
  }

  //while ((read = getline(&line, &line_sz, input)) >= 0)
  //{
    /*if (strstr(line, "end_header"))
    {
      for (i = 0; )
      {
        printf ("check!");

        for (i = 0; i < 6; i++)
        {
          if (getline(&line, &line_sz, input) < 0)
            break;

          token = strtok(line, " ");
          number = atof(token);

          printf ("%.1f\t", number);

          for (j = 1; j < 5; j++)
          {
            token = strtok(NULL, " ");
            number = atof(token);
            printf ("%.1f\t", number);
          }
        }
      }
    }*/
  //}
}
