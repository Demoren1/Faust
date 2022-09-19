#include "../include/funcs.h"

// 
// text_sort(text, comparator);
// 

/*
int text_sort(const Text* text, ...)
{
    assert(text);

    #ifdef USE_MY_SORT 

        MySort()
        
    #else

        qsort(...)

    #endif 
}
*/

void text_my_sort(void *v_base, size_t quantity_of_str, size_t size_of_obj, int (*comparator)(const void*, const void*))
{   
    char *base = (char*) v_base;
    char *tmp = (char*) calloc(1, size_of_obj);

    assert(base != NULL);
    assert(tmp != NULL);

    for (int counter1 = 0; counter1 < quantity_of_str; counter1++)
    {
        for (int counter2 = counter1 + 1; counter2 < quantity_of_str; counter2++)
        {
            if (comparator(base + counter1 * size_of_obj, base + counter2 * size_of_obj) > 0)
            {
                memcpy(tmp, base + counter1 * size_of_obj, size_of_obj);
                memcpy(base + counter1 * size_of_obj, base + counter2 * size_of_obj, size_of_obj);
                memcpy(base + counter2 * size_of_obj, tmp, size_of_obj);
            //^
            }
        }
    }
    free(tmp);
}

