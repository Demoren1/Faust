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
    const char* str1 = (const char*) v_str1;
    const char* str2 = (const char*) v_str2;
    
    assert(str1 != NULL);
    assert(str2 != NULL);
    
    char tmp1 = 0;
    char tmp2 = 0;
    int diff = 0;
    int counter1 = strlen(str1) - 1;
    int counter2 = strlen(str2) - 1;
    
    while (!(isalpha(str1[counter1])) && (counter1--) > 0)
    {} 
    
    while (!(isalpha(str2[counter2])) && (counter2--) > 0)
    {} 
     
    while (diff == 0 && str1[counter1] != 0 && str2[counter2] != 0)
    {   
	    diff = str1[counter1] - str2[counter2];
	    counter1--;
	    counter2--;
    }
    
    if (str1[counter1] == 0 || str2[counter2] ==0)
    {
	    diff = str1[counter1] - str2[counter2];
		return diff;
    }
    return diff;
}

void do_Bubble_sort(char* *pFaust, int QUANTITY_OF_STR)
{   

    for (int ptr1 = 0; ptr1 < QUANTITY_OF_STR; ptr1++)
    {
        for (int ptr2 = ptr1 + 1; ptr2 < QUANTITY_OF_STR; ptr2++)
        {
            if ( &(pFaust[ptr1]) == NULL || &(pFaust[ptr2]) == NULL)
                continue;
            if ((MyCmp(pFaust[ptr1], pFaust[ptr2])) > 0)
            {
                char* tmp = pFaust[ptr1];
                pFaust[ptr1] = pFaust[ptr2];
                pFaust[ptr2] = tmp;
            }
        }
    }
}