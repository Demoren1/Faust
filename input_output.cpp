#include "funcs.h"

int new_line_changer(char *str, int quantity_of_sym)
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

void made_massive_of_ptr(struct information *info_of_file)
{
    assert(info_of_file != NULL);

    int counter = 0;
    int start_line = 1;
    int end_line = 0;
    char *buff = info_of_file->buffer;
    
    for(int num_of_sym = 0; counter < info_of_file->quantity_of_str && num_of_sym < info_of_file->quantity_of_sym; num_of_sym++)
    {
        end_line++;
        if ( num_of_sym == 0 || (num_of_sym > 0 && buff[num_of_sym-1] == '\0'))
        {	
            if ((buff + num_of_sym) != 0)
            {       
                info_of_file->strings[counter].string = buff + num_of_sym;
                    
                if(counter > 0)
                {
                    (info_of_file->strings[counter-1]).len = end_line - start_line - 1;
                    start_line = end_line;
                }
                counter++;            
            }
        }
    }
    (info_of_file->strings[counter-1]).len = strlen((info_of_file->strings[counter-1]).string) ;
    
}

size_t find_lenght_of_buff(FILE *file_of_faust, const char *name_of_file)
{
    struct stat data = {};
    stat(name_of_file, &data);

    return data.st_size + 2;
}

void writing_to_file(FILE* result, struct line *Strings, int quantity_of_str)
{
    
    for (int i = 0; i < quantity_of_str; i++)
    {
	    if (Strings[i].string == NULL)
		    continue;
      
	    if ((Strings[i]).string[0] != 0)
            fprintf(result, "%s \n", (Strings[i]).string);
    }
    printf("%d\n", quantity_of_str);
}

void made_buff_and_pointers(const char *name_of_file, struct information *info_of_file)
{
    FILE *file_of_faust = fopen(name_of_file, "r");
    
    assert(file_of_faust != NULL);
    assert(info_of_file !=NULL);

    info_of_file->quantity_of_sym = find_lenght_of_buff(file_of_faust, name_of_file);
    
    info_of_file->buffer = (char*) calloc(info_of_file->quantity_of_sym, sizeof(char));
    
    fread(info_of_file->buffer, sizeof(char), info_of_file->quantity_of_sym, file_of_faust);
        
    info_of_file->quantity_of_str = new_line_changer(info_of_file->buffer, info_of_file->quantity_of_sym);
    
    info_of_file->strings = (struct line*) calloc(info_of_file->quantity_of_str, sizeof(struct line));
  
    
    fclose(file_of_faust);
}

void write_original(FILE *destination, char *buffer, int quantity_of_sym)
{
 for (int i = 0; i < quantity_of_sym; i++)
    {  
        if (buffer[i] == '\0')
        {   
            buffer[i] = '\n';
        }
    }

    fwrite(buffer, sizeof(char), quantity_of_sym, destination);
}
