#include "../include/funcs.h"
int straight_cmp(const void* v_str1, const void* v_str2)
{
    
    const struct line*  structure_str1 = (const struct line*) v_str1;
    const struct line*  structure_str2 = (const struct line*) v_str2;
    
    assert(structure_str1 != NULL);
    assert(structure_str2 != NULL);
    
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

int reverse_cmp(const void* v_str1, const void* v_str2)
{
    const struct line* str1 = ((const struct line*) v_str1);
    const struct line* str2 = ((const struct line*) v_str2);
    
    assert(str1 != NULL);
    assert(str2 != NULL);
    
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
	    diff = (int) string1[len1] - (int)string2[len2]; //^
	    len1--;
	    len2--;
    }
    
    if (len1+1 == 0 || len2+1 ==0) //^?
    {
	    diff = string1[len1] - string2[len2];
        return diff;
    }

    return diff;
}
