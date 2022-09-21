#ifndef MY_GUARD_HEADER_2
#define MY_GUARD_HEADER_2

#include <stdio.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define END_OF_OUTPUT fputs("******************************************************\n", result);

static size_t find_lenght_of_buff(FILE *file_of_faust, const char *name_of_file);

static ssize_t count_lines(char *str, int quantity_of_sym);

static void parse_strings(struct Information *info_of_file); 

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