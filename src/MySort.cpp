#include "../include/funcs.h"

void text_my_sort(void *v_base, size_t quantity_of_str, size_t size_of_obj, int (*comparator)(const void*, const void*))
{   
    char *base = (char*) v_base;
    char tmp = 0;

    assert(base != NULL);

    for (int counter1 = 0; counter1 < quantity_of_str; counter1++)
    {
        for (int counter2 = counter1 + 1; counter2 < quantity_of_str; counter2++)
        {
            if (comparator(base + counter1 * size_of_obj, base + counter2 * size_of_obj) > 0)
            {   
               for (int i = 0; i < size_of_obj; i++)
               {
                    tmp = *(base + counter1 * size_of_obj + i);

                    *(base + counter1 * size_of_obj + i) = *(base + counter2 * size_of_obj + i);
                    *(base + counter2 * size_of_obj +i ) = tmp;
               }
            
            }
        }
    }
}

