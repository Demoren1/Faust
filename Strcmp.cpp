#include "funcs.h"
int Strcmp(const void* v_str1, const void* v_str2)
{
    const char** str1 = (const char**) v_str1;
    const char** str2 = (const char**) v_str2;
    
    int diff = 0, counter = 0;
    
    while (*str1[counter] != 0 && &str2[counter] != 0)
    {
	    diff = *str1[counter] - *str2[counter];

	    if 	(diff != 0)
	    {
		    diff = (diff > 0) ? 1 : -1;
		    return diff;
	    }
	    
	    counter++;
    }
    return diff;
}
//
