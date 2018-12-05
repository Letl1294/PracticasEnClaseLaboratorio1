#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "LinkedList.h"
#include "Compra.h"
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int parser_parseCompras(char* fileName, LinkedList* lista);


#endif // PARSER_H_INCLUDED
