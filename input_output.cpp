#include "funcs.h"

int new_line_changer (char *str, int quantity_of_sym)
{
    int QUANTITY_OF_STR = 0;
    for (int i = 0; i < quantity_of_sym; i++)
    {  
        if (str[i] == '\n')
        {
	    QUANTITY_OF_STR++;
        
        //if (str[i-1] = '\r')
          //  str[i-1] = ' ';
	    str[i] = '\0';
        }

    }
   return QUANTITY_OF_STR;
}

void made_massive_of_ptr(int QUANTITY_OF_STR, char *buffer, char *massive_of_ptr[], size_t quantity_of_sym)
{
    int counter = 0;

    for(int num_of_sym = 0; counter < QUANTITY_OF_STR && num_of_sym < quantity_of_sym; num_of_sym++)
    {
        if ( num_of_sym == 0 || (num_of_sym > 0 && buffer[num_of_sym-1] == '\0'))
        {	
		if (&(buffer[num_of_sym]) != 0)
		{
               	 massive_of_ptr[counter] = &buffer[num_of_sym];
               	 counter++;
		}
        }
    }
}

void find_lenght_of_buff(FILE *file_of_faust, size_t *quantity_of_sym, const char *name_of_file)
{   
    struct stat data ={};
    stat (name_of_file, &data);

    *quantity_of_sym = data.st_size + 2;
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
