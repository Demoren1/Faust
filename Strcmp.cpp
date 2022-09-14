#include "funcs.h"
int Strcmp(const void* v_str1, const void* v_str2)
{
    const char* str1 = *(const char**) v_str1;
    const char* str2 = *(const char**) v_str2;
    assert(str1 != NULL);
    assert(str2 != NULL);
    int diff = 0;
    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;

    while (!(isalpha(str1[counter1])) && str1[counter1++] != 0)
    {} 
    
    while (!(isalpha(str2[counter2])) && str2[counter2++] != 0)
    {} 

    while (diff == 0 && str1[counter1] != 0 && str2[counter2] != 0)
    {
	    diff = str1[counter1] - str2[counter2];
	    counter1++;
	    counter2++;
    }
    
    if (str1[counter1] == 0 || str2[counter2] ==0)
    {
	    diff = str1[counter1] - str2[counter2];
		return diff;
    }
    
    return diff;
}
