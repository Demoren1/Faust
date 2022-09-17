#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <sys/stat.h>
#define DBG printf("%s:%d -- %s\n", __FILE__, __LINE__, __FUNCTION__);
int Strcmp(const void *v_str1, const void *v_str2);

int  new_line_changer (char *str, int quantity_of_sym);

void made_massive_of_ptr(int quantity_of_str, char *buffer,size_t quantity_of_sym, struct line Strings[]);

void find_lenght_of_buff(FILE *file_of_faust, size_t *quantity_of_sym, const char* name_of_files);

void writing_to_file (FILE* result, struct line Strings[], int quantity_of_str);

int MyCmp(const void* str1, const void* str2);

void MySort(void *base, size_t Strings, size_t Size_of_obj, int (*MyCmp)(const void*, const void*));

void do_Bubble_sort(struct line Strings[], int quantity_of_str);

void made_buff(const char* name_of_file);

void made_buff_and_pointers(const char *name_of_file, struct information *inf_of_file);

struct line
{
    char *string;
    int len;
};

struct information 
{
  size_t quantity_of_sym;
  int quantity_of_str;
  char *buff_of_Faust;
  struct line *strings;
};

