#include "funcs.h"

void sorter(char *(pFaust[QUANTITY_OF_STR]))
{
    char *tmp;

    for (int i = 0; i < QUANTITY_OF_STR; i++)
    {
        for (int j = i + 1; j < QUANTITY_OF_STR; j++)
        {
            tmp = pFaust[i];
            if (strcmp(pFaust[i], pFaust[j]) == 1)
            {
                pFaust[i] = pFaust[j];
                pFaust[j] = tmp;
            }
        }
    }
}
