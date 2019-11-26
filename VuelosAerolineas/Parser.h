#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Aerolineas.h"

int parser_AerolineasFromText(FILE* pFile, LinkedList* pArrayList);
int parser_AerolineasFromBinary(FILE* pFile, LinkedList* pArrayList);
