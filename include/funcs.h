#ifndef MY_GUARD_HEADER_1
#define MY_GUARD_HEADER_1

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define DBG printf("%s:%d -- %s\n", __FILE__, __LINE__, __FUNCTION__);

FILE* file_open(const char*);

void text_write_to_file (FILE* result, struct line *Strings, int quantity_of_str);

void text_my_sort(void *base, size_t Strings, size_t Size_of_obj, int (*comparator)(const void*, const void*));

void text_read(const char *name_of_file, struct Information *inf_of_file, FILE *file_with_text);

void text_write_original(FILE *destination, char *buffer, int quantity_of_sym);

void text_detor(struct Information* to_clean);

int straight_cmp(const void* v_str1, const void* v_str2);

int reverse_cmp(const void* v_str1, const void* v_str2);

struct line
{
    char *string;
    int len;
};

struct Information 
{
  size_t quantity_of_sym;
  int quantity_of_str;
  char *buffer;
  struct line *strings;
};
#endif

