#ifndef FACES_H
#define FACES_H

#include "ply_file_data_tree.h"

void read_faces (char *filename, GenericTree *FacesTree, int faces_elements, int *last_vertex_position);
void print_faces (GenericTree *VertexTree, GenericTree *FacesTree, int faces_elements);

#endif
