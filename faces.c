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
  float faces_index_number;
  char *faces_sub_id [24] = {
                             "a", "b", "c", "d", "e", "f", "g"
                             "h", "i", "j", "k", "l", "m", "n"
                             "o", "p", "q", "r", "s", "t", "u"
                             "v", "w", "x", "y", "z"
                            };

  while ((read = getline(&line, &line_sz, input)) >= 0)
  {
    if (ftell(input) == *last_vertex_position)
    {
      for (i = 0; i < faces_elements; i++)
      {
        if (getline(&line, &line_sz, input) < 0)
          break;

        token = strtok(line, " ");
        faces_data[id-1] = atof(token);
        faces_index_number = faces_data[id-1];
        InsertGenericTreeData(FacesTree, i+1, faces_sub_id[0], &faces_data[id-1]);
        id++;

        for (j = 1; j <= faces_index_number; j++)
        {
          token = strtok(NULL, " ");
          faces_data[id-1] = atof(token);
          InsertGenericTreeData(FacesTree, i+1, faces_sub_id[j], &faces_data[id-1]);
          id++;
        }
      }
    }
  }
}

/*NOTE: Mistake-bug made by me when designing the function.
  It does not read the faces data correctly. Perfect the desing*/

void print_faces (GenericTree *VertexTree, GenericTree *FacesTree, int faces_elements, int vertex_properties)
{
  GenericTreeNode *Iterator = malloc(sizeof(GenericTreeNode));
  GenericTreeNode *Iterator2 = malloc(sizeof(GenericTreeNode));
  GenericTreeNode *TempNode = malloc(sizeof(GenericTreeNode));

  char *vertex_sub_id[3] = {"x", "y", "z"};
  char *faces_sub_id[5] = {"a", "b", "c", "d", "e"};
  int count, faces_number;
  int i,j,k;
  float vertex_d;

  printf ("\n====================");
  printf ("\nExpanded Faces List:");
  printf ("\n====================\n\n");

  for (i=0; i<faces_elements; i++)
  {
    Iterator = FindGenericTreeNode(i+1, faces_sub_id[0], FacesTree);
    count = (int)(*((float*)Iterator->data));

    printf ("|Face number %d|:\t", i+1);

    for (j=1; j <= count; j++)
    {
      Iterator2 = FindGenericTreeNode(i+1, faces_sub_id[j], FacesTree);
      faces_number = (int)(*((float*)Iterator2->data));

      printf ("\n\n+=========================================+");
      printf ("\nFaces Number [%d] - Index [%d] Composition:", i+1, faces_number);
      printf ("\n+=========================================+");

      printf ("\n\n+---------------------------------------+\n");

      for (k=0; k < vertex_properties; k++)
      {
        TempNode = FindGenericTreeNode(faces_number+1, vertex_sub_id[k], VertexTree);
        vertex_d = (*((float*)TempNode->data));
        printf("\n|%d%s %.1f|", faces_number+1, vertex_sub_id[k], vertex_d);
      }

      printf ("\n\n+---------------------------------------+\n");
    }
    printf("\n\n");
  }
  free(Iterator);
  free(Iterator2);
  free(TempNode);
}
