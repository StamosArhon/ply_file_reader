#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

#define MAX_LINE_SIZE 81

void read_header(char *filename, struct Header *header)
{
  FILE *input = fopen(filename, "r");
  char *line = malloc(MAX_LINE_SIZE*sizeof(char));
  size_t line_sz;
  char *token;
  int last_element = -1;
  int i;

  if (!header) return;

  for (i = EL_VERTEX; i <= EL_FACE; i++) {
    header->el_props[i] = 0;
    header->elements[i] = 0;
  }

  while (getline(&line, &line_sz, input) >= 0 &&
          !strstr(line, "end_header")) {
    if (!strstr(line, " ")) continue;
    token = strtok(line, " ");
    if (!token) continue;
    if (!strcmp(token, "element")) {
      token = strtok(NULL, " ");

      if (!strcmp(token, "vertex")) {
        token = strtok(NULL, " ");
        header->elements[EL_VERTEX] = atoi(token);
        last_element = EL_VERTEX;
      }

      if (!strcmp(token, "edge")) {
        token = strtok(NULL, " ");
        header->elements[EL_EDGE] = atoi(token);
        last_element = EL_EDGE;
      }

      if (!strcmp(token, "face")) {
        token = strtok(NULL, " ");
        header->elements[EL_FACE] = atoi(token);
        last_element = EL_FACE;
      }
    }

    if (!strcmp(token, "property")) {
      header->el_props[last_element]++;
    }
  }

  free(line);
  fclose(input);
}
