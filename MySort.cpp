#include "funcs.h"
void MySort(void *base, size_t Strings, size_t Size_of_obj, int (*reverse_cmp)(const void*, const void*))
{
    puts("SORT ok");
    for (int i = 0; i < Strings; i++)
    {
        reverse_cmp(base, base);
    }
}

int reverse_cmp(const void* v_str1, const void* v_str2)
{
    const struct line* str1 = ((const struct line*) v_str1);
    const struct line* str2 = ((const struct line*) v_str2);
    
    assert(str1->string[0] != NULL);
    assert(str2->string[0] != NULL);
    
    char* string1 = str1->string;
    char* string2 = str2->string;
    int len1 = str1->len;
    int len2= str2->len;
    int diff = 0;
    
    while (!(isalpha(string1[len1])) && len1 > 0)
    {
        len1--;
    } 
    
    while (!(isalpha(string2[len2])) && len2 > 0)
    {
        len2--;
    } 
    
    while (diff == 0 && len1 > 0 && len2 > 0)
    {
	    diff = (int) string1[len1] - (int)string2[len2];
	    len1--;
	    len2--;
    }
    
    if (len1+1 == 0 || len2+1 ==0)
    {
	    diff = string1[len1] - string2[len2];
        return diff;
    }
    return diff;
}

void do_Bubble_sort(struct line Strings[], int quantity_of_str, int (*comparator) (const void*, const void*))
{  
    struct line tmp = {};
    for (int counter1 = 0; counter1 < quantity_of_str; counter1++)
    {
        for (int counter2 = counter1 + 1; counter2 < quantity_of_str; counter2++)
        {
            if (Strings[counter1].string == NULL || (Strings[counter2]).string == NULL)
                continue;
                
            if (comparator(&(Strings[counter1]), &(Strings[counter2])) > 0)
            {
                tmp = Strings[counter1];
                Strings[counter1] = Strings[counter2];
                Strings[counter2] = tmp;
            }
        }
    }
}