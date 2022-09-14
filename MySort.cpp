#include "funcs.h"
void MySort(void *base, size_t Strings, size_t Size_of_obj, int (*MyCmp)(const void*, const void*))
{
    puts("SORT ok");
    for (int i = 0; i < Strings; i++)
    {
        MyCmp(base, base);
    }
}

int MyCmp(const void* v_str1, const void* v_str2)
{
    puts("CMP ok");
    
    return 0;
}

void Bubble_sort(char* *pFaust, int QUANTITY_OF_STR)
{
    for (int ptr1 = 0; ptr1 < QUANTITY_OF_STR; ptr1++)
    {
        for (int ptr2 = 0; ptr2 < QUANTITY_OF_STR; ptr2++)
        {
            if ( &(pFaust[ptr1]) == NULL || &(pFaust[ptr2]) == NULL)
                continue;
            if (strcmp(pFaust[ptr1], pFaust[ptr2]) < 0)
            {
                char* tmp = pFaust[ptr1];
                pFaust[ptr1] = pFaust[ptr2];
                pFaust[ptr2] = tmp;
            }
        }
    }
}