#include "funcs.h"

int new_line_changer (char *str, int QUANTITY_OF_SYM)
{
    int QUANTITY_OF_STR = 0;
    for (int i = 0; i < QUANTITY_OF_SYM; i++)
    {  
        if (str[i] == '\n')
        {
	    QUANTITY_OF_STR++;
            //str[i-1] = ' ';
	    str[i] = '\0';
        }

    }
   return QUANTITY_OF_STR;
}

void made_massive_of_ptr(int QUANTITY_OF_STR, char *str_with_text, char *massive_of_ptr[], int QUANTITY_OF_SYM)
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

void find_lenght_of_buff(FILE *file_of_faust, size_t *QUANTITY_OF_SYM)
{
    fseek(file_of_faust, 0L, SEEK_END);
    *QUANTITY_OF_SYM = ftell(file_of_faust) + 2;
    fseek(file_of_faust, 0L, SEEK_SET);
}

void writing_to_file (FILE* result, char** pFaust, int QUANTITY_OF_STR)
{
    for (int i = 0; i < QUANTITY_OF_STR; i++)
    {
	    if (&(pFaust[i][0]) == NULL)
		    continue;
      int x = (pFaust[i][0] !=0);
	    if (x)
        fprintf(result, "%s \n", (char*) pFaust[i]);
    }
}
