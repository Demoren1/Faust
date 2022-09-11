#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#define QUANTITY_OF_STR   230
#define QUANTITY_OF_SYM   1390000        //ftell, fseek()

int Strcmp(const void *v_str1, const void *v_str2);

void new_line_changer (char *str);

void made_massive_of_ptr(char *str_with_text, char *massive_Of_ptr[QUANTITY_OF_STR]);

int Strlen(const char* str);
// include guard
