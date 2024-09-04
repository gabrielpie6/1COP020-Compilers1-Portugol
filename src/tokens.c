#include "tokens.h"

#include <stdlib.h>

Token createToken(int id, void * data, int line, int column)
{
    Token t   = malloc(sizeof(struct StToken));
    t->id     = id;
    t->data   = data;
    t->line   = line;
    t->column = column;

    return t;
}