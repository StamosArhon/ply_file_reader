#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vertex.h"

#define MAX_LINE_SIZE 81 //Setting the maximum line size to 81 characters

void read_vertices(char *filename, Vertex **p_vertex_array, int elems, int props)
{
  FILE *input = fopen(filename, "r"); //Open the ply filename
  char *line = malloc(MAX_LINE_SIZE*sizeof(char)); //Allocate heap memory for each line we read from that file, equal to the size of a char variable times the max number of characters we allow for each line
  size_t line_sz; //Declaring a line_sz parameter - unisgned int
  char *token; //Declaring a char variable named token for every piece of a line we read
  ssize_t read; //variable to check for a condition in the while loop
  int i, j; //Itterators

  Vertex *p_vertex; //A Vertex struct variable

  while ((read = getline(&line, &line_sz, input)) >= 0) //While the line we read has 0 or more characters go to the loop body
  {
    if (strstr(line, "end_header")) //If we encounter the string "end_header" go to the body of this if statement
    {
      for (i = 0; i < elems; i++) //Run the loop as long as i is less than "elems"
      {
        if (getline(&line, &line_sz, input) < 0) //If the line is less than 0 characters, i.e. if we reach the end of the file or if there is an error break from the loop
          break;

        p_vertex = malloc(sizeof(Vertex)); //Assign heap memory space for the Vertex variable "p_vertex" equal to the size of the Vertex struct
        p_vertex->properties = malloc(props*sizeof(float)); //Assign heap memory space for the "properties" element of the Vertex variable "p_vertex" equal to the size a float times the number of properties

        token = strtok(line, " "); //Break the line to tokens using " " as a deliminator
        p_vertex->properties[0] = atof(token); //Transform and save the token which is a number in string form in float form in the properties element of the Vertex struct variable "p_vertex" under the "0" subscript (its an array)

        for (j = 1; j < props; j++) //setting j as 1 and as long as j is less than the "props" keep breaking the line in tokens and saving the numbers in that line in the p_array, each one in the appropriate subscript represented by "j"
        {
          token = strtok(NULL, " ");
          p_vertex->properties[j] = atof(token);
        }

        p_vertex_array[i] = p_vertex;
      }
    }
  }
  free(line);
  fclose(input);
}
