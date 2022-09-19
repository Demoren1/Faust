#include "../include/i_o_text_funcs.h"

FILE* file_open1(char* name_of_out_file, int errno)
{
    FILE* ptr_on_out = fopen(name_of_out_file, "w");
    assert (ptr_on_out != NULL);
    if (errno != 0)
    {
        strerror(errno);
    }

    return ptr_on_out;
}

static ssize_t count_lines(char *str, int quantity_of_sym)
{
    assert(str != nullptr);
    assert(quantity_of_sym != 0); //
    ssize_t quantity_of_str = 0; 
    
    for (int i = 0; i < quantity_of_sym; i++)
    {  
        if (str[i] == '\n')
        {   
            //if (str[i-1] == '\r')
            //{
             //   str[i-1] = ' ';
            //}

            quantity_of_str++; // 
            str[i] = '\0';
        }

    } 

   return quantity_of_str;
}

static void parse_strings(struct Information *info_of_file) 
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
                
                if (info_of_file->strings[counter].string[0] == NULL) 
                {  
                    info_of_file->strings[counter].string = "\0"; //^ not include empty lines
                }    

                if (counter > 0) 
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

static size_t find_lenght_of_buff(FILE *file_of_faust, const char *name_of_file) //
{
    assert(file_of_faust != nullptr);
    assert(name_of_file != nullptr);

    struct stat data = {};
    stat(name_of_file, &data); 

    if (data.st_mode == S_IFDIR)
        {
            printf("Trying to find size of dir");
            abort();
        }

    return data.st_size;
}

void text_write_to_file(FILE* result, struct line *Strings, int quantity_of_str)
{
    assert(result != nullptr);
    assert(Strings != nullptr);
    
    for (int i = 0; i < quantity_of_str; i++)
    {
	    if (Strings[i].string == NULL)
		    continue;
      
	    if ((Strings[i]).string[0] != 0)
            fprintf(result, "%s \n", (Strings[i]).string);
    }
    END_OF_OUTPUT;
    printf("%d\n", quantity_of_str);
}

void text_read(const char *name_of_file, struct Information *info_of_file, FILE *file_of_faust) 
{
    assert(file_of_faust != NULL);
    assert(info_of_file  != NULL); 

    info_of_file->quantity_of_sym = find_lenght_of_buff(file_of_faust, name_of_file);
    
    info_of_file->buffer = (char*) calloc(info_of_file->quantity_of_sym, sizeof(char));
    assert(info_of_file->buffer != NULL);
    
    int test_fread = fread(info_of_file->buffer, sizeof(char), info_of_file->quantity_of_sym, file_of_faust);
    assert(test_fread != 0);
        
    info_of_file->quantity_of_str = count_lines(info_of_file->buffer, info_of_file->quantity_of_sym);
    assert(info_of_file->quantity_of_str != -1);

    info_of_file->strings = (struct line*) calloc(info_of_file->quantity_of_str, sizeof(struct line));
    assert(info_of_file->strings != NULL);

    parse_strings(info_of_file);
}

void text_write_original(FILE *destination, char *buffer, int quantity_of_sym)
{
    assert(destination != nullptr);
    
    for (int i = 0; i < quantity_of_sym; i++)
    {  
        if (buffer[i] == '\0')
        {   
            buffer[i] = '\n';
        }
    }

    fwrite(buffer, sizeof(char), quantity_of_sym, destination);
}

void text_detor(struct Information *info_of_file)
{
    free (info_of_file->buffer);
    free(info_of_file->strings);
}