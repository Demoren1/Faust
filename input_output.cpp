#include "funcs.h"

void new_line_changer (char *str, int QUANTITY_OF_SYM)
{
    for (int i = 0; i < QUANTITY_OF_SYM; i++)
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
        }

    }
}

void made_massive_of_ptr(char *str_with_text, char *massive_of_ptr[QUANTITY_OF_STR], int QUANTITY_OF_SYM)
{
    int counter = 0;

    for(int num_of_sym = 0; counter < QUANTITY_OF_STR && num_of_sym < QUANTITY_OF_SYM; num_of_sym++)
    {
        if ( num_of_sym == 0 || (num_of_sym > 0 && str_with_text[num_of_sym-1] == '\0'))
        {	
		if ((&str_with_text[num_of_sym]) != 0)
		{
               	 massive_of_ptr[counter] = &str_with_text[num_of_sym];
               	 counter++;
		}
        }
    }
}
//
