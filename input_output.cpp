#include "funcs.h"

int new_line_changer (char *str, int quantity_of_sym)
{
    int quantity_of_str = 0;
    
    for (int i = 0; i < quantity_of_sym; i++)
    {  
        if (str[i] == '\n')
        {   
            if (str[i-1] == '\r')
            {
                str[i-1] = ' ';
            }
            quantity_of_str++;
            str[i] = '\0';
        }

    }
   return quantity_of_str;
}

void made_massive_of_ptr(int quantity_of_str, char *buffer, size_t quantity_of_sym, struct line Strings[])
{
    int counter = 0;
    
    for(int num_of_sym = 0; counter < quantity_of_str && num_of_sym < quantity_of_sym; num_of_sym++)
    {
        if ( num_of_sym == 0 || (num_of_sym > 0 && buffer[num_of_sym-1] == '\0'))
        {	
            if (&(buffer[num_of_sym]) != 0)
            {       Strings[counter].string = &buffer[num_of_sym];
                    //puts((Strings[counter]).string);
                    if(counter > 0)
                    {
                        (Strings[counter-1]).len = Strings[counter].string - Strings[counter-1].string -1;
                    }
                    counter++;            
            }
        }
    }
    (Strings[counter-1]).len = strlen((Strings[counter-1]).string) ;
    
}

void find_lenght_of_buff(FILE *file_of_faust, size_t *quantity_of_sym, const char *name_of_file)
{   
    struct stat data ={};
    stat (name_of_file, &data);
    //assert on directory

    *quantity_of_sym = data.st_size + 2;
}

void writing_to_file (FILE* result, struct line Strings[], int quantity_of_str)
{
    for (int i = 0; i < quantity_of_str; i++)
    {
	    if (&((Strings[i]).string[0]) == NULL)
		    continue;
      int x = ((Strings[i]).string[0] !=0);
	  if (x)
        fprintf(result, "%s \n", (Strings[i]).string);
    }
    printf("%d\n", quantity_of_str);
    for (int i = 0; i < quantity_of_str; i++)
    {
        //puts((Strings[i].string));
    }
}

void made_buff_and_pointers(const char *name_of_file, struct information *inf_of_file)
{
    
    //DBG;
    FILE *file_of_faust = fopen(name_of_file, "r");
    //DBG;
    assert(file_of_faust != NULL);
    //DBG;
    inf_of_file->quantity_of_sym = 0; 
    //DBG;    
    find_lenght_of_buff(file_of_faust, &(inf_of_file->quantity_of_sym), name_of_file);
    //DBG;
    inf_of_file->buff_of_Faust = (char*) calloc(inf_of_file->quantity_of_sym, sizeof(char));
    
    fread(inf_of_file->buff_of_Faust, sizeof(char), inf_of_file->quantity_of_sym, file_of_faust);
    DBG;
        
    inf_of_file->quantity_of_str = new_line_changer(inf_of_file->buff_of_Faust, inf_of_file->quantity_of_sym);
    
    inf_of_file->strings = (struct line*) calloc(inf_of_file->quantity_of_str, sizeof(struct line));
  
    
    fclose(file_of_faust);
}