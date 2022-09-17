#include "funcs.h"
int straight_cmp(const void* v_str1, const void* v_str2)
{
    const struct line*  structure_str1 = (const struct line*) v_str1;
    const struct line*  structure_str2 = (const struct line*) v_str2;
    assert(structure_str1->string != NULL);
    assert(structure_str2->string != NULL);
    
    char *str1 = structure_str1->string;
    char *str2 = structure_str2->string;
    int diff = 0;

    while (!(isalpha(*str1)) && *str1++ != 0)
    {} 
    
    while (!(isalpha(*str2)) && *str2++ != 0)
    {} 

    while (diff == 0 && *str1 != 0 && *str2 != 0)
    {
	    diff = *str1 - *str2;
	    str1++;
	    str2++;
    }
    
    if (*str1 == 0 || *str2 ==0)
    {
	    diff = *str1 - *str2;
		return diff;
    }
    
    return diff;
}