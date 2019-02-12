#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

#define MAX_LINE_SIZE 81 //Setting the maximum line size to 81 characters

void read_header(char *filename, struct Header *header) //read_header function that takes three parameters
{
  FILE *input = fopen(filename, "r"); //Open the ply file and placing a pointer to the begining of that file
  char *line = malloc(MAX_LINE_SIZE*sizeof(char)); //Allocate heap memory for each line we read from that file, equal to the size of a char variable times the max number of characters we allow for each line
  size_t line_sz; //Declaring a line_sz parameter - unisgned int
  char *token; //Declaring a char variable named token for every piece of a line we read
  int last_element = -1; //Initialize the last_elemennt variable to -1 in order to change it later - Its -1 because we have set EL_VERTEX as 0 in the header.h
  int i; //Itterator

  if (!header) //If there is no header parameter return to main()
    return;

  for (i = EL_VERTEX; i <= EL_FACE; i++) //Set all "header" array element values to 0 in order to fill the later on
  {
    header->el_props[i] = 0;
    header->elements[i] = 0;
  }

  while (getline(&line, &line_sz, input) >= 0 && !strstr(line, "end_header")) //While the line is more than or equal to 0 characters and we don't find the string "end_header" keep running the while loop
  {
    if (!strstr(line, " ")) //if there is not a space in the line we read, and thus no meaningfull data to read go to the next itteration of the while loop
      continue;

    token = strtok(line, " "); //break the line to tokens using " " as a deliminator

    if (!token) //If there is no token available go to the next itteration of the while loop
      continue;

    if (!strcmp(token, "element")) //If one of the tokens of this line is the string "element" go to the body of "if"
    {
      token = strtok(NULL, " "); //Continue from the last token position and keep breaking the line to tokens using again " " as a deliminator

      if (!strcmp(token, "vertex")) //If the line has the string "vertex" as a token go to the body of this "if"
      {
        token = strtok(NULL, " "); //Continue from the last token position and keep breaking the line to tokens using again " " as a deliminator
        header->elements[EL_VERTEX] = atoi(token); //Convert the last token of this line (which is a number in string form) to a single precision floating point number from a string and then place it in the Header struct variable "header" in the "elements[EL_VERTEX]" element
        last_element = EL_VERTEX; //appoint EL_VERTEX as the last element to be stored in our struct variable
      }

      if (!strcmp(token, "edge"))  //If one of the tokens of this line is the string "edge" go to the body of "if"
      {
        token = strtok(NULL, " "); //Continue from the last token position and keep breaking the line to tokens using again " " as a deliminator
        header->elements[EL_EDGE] = atoi(token); //Convert the last token of this line (which is a number in string form) to a single precision floating point number from a string and then place it in the Header struct variable "header" in the "elements[EL_EDGE]" element
        last_element = EL_EDGE; //appoint EL_EDGE as the last element to be stored in our struct variable
      }

      if (!strcmp(token, "face")) //If one of the tokens of this line is the string "face" go to the body of "if"
      {
        token = strtok(NULL, " "); //Continue from the last token position and keep breaking the line to tokens using again " " as a deliminator
        header->elements[EL_FACE] = atoi(token); //Convert the last token of this line (which is a number in string form) to a single precision floating point number from a string and then place it in the Header struct variable "header" in the "elements[EL_FACE]" element
        last_element = EL_FACE; //appoint EL_FACE as the last element to be stored in our struct variable
      }
    }

    if (!strcmp(token, "property")) //If the token is not "element" but property go to the body of this "if"
    {
      header->el_props[last_element]++; //Increment the "last element" element in the "el_props" array
    }
  }

  free(line); //free the memory we reserved in heap for saving each line we read in the while loop
  fclose(input); //Close the file
}
