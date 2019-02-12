/* HEADER GUARD: preventing double include */
#ifndef HEADER_H
#define HEADER_H
/* --------------------------- */
#define MAX_EL 3

enum
{
    EL_VERTEX = 0,
    EL_EDGE,
    EL_FACE
};
/* --------------------------- */

/* --------------------------- */
typedef struct Header
{
    int elements[MAX_EL];
    int el_props[MAX_EL];
    void *properties;
} Header;
/* --------------------------- */

/* --------------------------- */
void read_header(char *filename, Header *header); //read_header function prototype
/* --------------------------- */
#endif /* HEADER_H */
