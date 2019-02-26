/* HEADER GUARD: preventing double include */
#ifndef VERTEX_H
#define VERTEX_H
/* --------------------------- */
typedef struct Vertex
{
  float *properties;
} Vertex;
/* --------------------------- */

/* --------------------------- */
void read_vertices(char *filename, Vertex **p_vertex_array, int elems, int props);
/* --------------------------- */
#endif /* VERTEX_H */
