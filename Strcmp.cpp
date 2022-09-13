#include "funcs.h"
int Strcmp(const void* v_str1, const void* v_str2)
{
    const char* str1 = *(const char**) v_str1;
    const char* str2 = *(const char**) v_str2;
    
    int diff = 0;
    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;
    
    //puts(str1);
    //puts(str2);
    //puts("***********");
    while (!(isalpha(str1[counter1])) && str1[counter1++] != 0)
    {} 
    //puts("counter1 def");	
    while (!(isalpha(str2[counter2])) && str2[counter2++] != 0)
    {} 
    //puts("counter2 def");
    while (diff == 0 && str1[counter1] != 0 && str2[counter2] != 0)
    {
	    diff = str1[counter1] - str2[counter2];
	    counter1++;
	    counter2++;
    }
    //puts("after while");
    if (str1[counter1] == 0 || str2[counter2] ==0)
    {
	    puts("in if");
	    diff = str1[counter1] - str2[counter2];
	    puts("not in diff");
	    return diff;
    }
    //puts("after if");
    return diff;
}
