#include "funcs.h"

void new_line_changer (char *str)
{
    for (int i = 0; i < QUANTITY_OF_SYM ; i++)
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
        }

    }
}

void made_massive_of_ptr(char *str_with_text, char *massive_of_ptr[QUANTITY_OF_STR], int len_of_massive)
{
    int counter = 0;

    for(int j = 0; counter < QUANTITY_OF_STR && j < QUANTITY_OF_SYM; j++)
    {
        if ( j == 0 || (j>0 && str_with_text[j-1] == '\0'))
        {
            massive_of_ptr[counter] = &str_with_text[j];
            counter++;
        }
    }
}

