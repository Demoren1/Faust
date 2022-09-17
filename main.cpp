#include "funcs.h"
const int NUM_OF_FILE = 2;
int main()
{
  
  FILE *result = fopen("result.txt", "w");  

  const char* names_of_files[] = {"test_text.txt",
                                  "work_text1.txt", 
                                  "work_text2.txt", 
                                  "work_text3.txt"};

  struct information info_of_file;
  made_buff_and_pointers(names_of_files[NUM_OF_FILE], &info_of_file);
  //DBG;
  //printf("%d, %d\n", info_of_file.quantity_of_sym, info_of_file.quantity_of_str);
  //DBG;
  
  made_massive_of_ptr(info_of_file.quantity_of_str, info_of_file.buff_of_Faust, info_of_file.quantity_of_sym, info_of_file.strings);
  //DBG;
  /*
  for (int i = 0; i < quantity_of_str; i++)
  { 
    puts((strings[i]).string);
    printf("%d \n", (strings[i]).len );
  }
  */
  qsort(info_of_file.strings, info_of_file.quantity_of_str, sizeof(info_of_file.strings[0]), Strcmp);
  writing_to_file(result, info_of_file.strings, info_of_file.quantity_of_str);
  
  fputs("******************************************************\n", result);
  
  do_Bubble_sort(info_of_file.strings, info_of_file.quantity_of_str);
  writing_to_file(result, info_of_file.strings, info_of_file.quantity_of_str);
  
  //MySort(pFaust, quantity_of_str, sizeof(pFaust[0]), MyCmp);
  
  fclose(result);
  // getchar();
  
  free(info_of_file.buff_of_Faust);
  free(info_of_file.strings);
 
  //DBG;
  return 0;
}


