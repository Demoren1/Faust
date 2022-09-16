#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <sys/stat.h>

int Strcmp(const void *v_str1, const void *v_str2);

int  new_line_changer (char *str, int quantity_of_sym);

void made_massive_of_ptr(int QUANTITY_OF_STR, char *buffer, char *massive_of_ptr[], size_t quantity_of_sym);

void find_lenght_of_buff(FILE *file_of_faust, size_t *quantity_of_sym, const char* name_of_files);

void writing_to_file (FILE* result, char** pFaust, int QUANTITY_OF_STR);

int MyCmp(const void* str1, const void* str2);

void MySort(void *base, size_t Strings, size_t Size_of_obj, int (*MyCmp)(const void*, const void*));

void do_Bubble_sort(char* *pFaust, int QUANTITY_OF_STR);

