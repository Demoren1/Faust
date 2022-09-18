#include "funcs.h"
const int NUM_OF_FILE = 3;
int main()
{
  
  FILE *result = fopen("result.txt", "w");  

  const char* names_of_files[] = {"test_text.txt",
                                  "work_text1.txt", 
                                  "work_text2.txt", 
                                  "work_text3.txt"};

  struct information info_of_file;
  made_buff_and_pointers(names_of_files[NUM_OF_FILE], &info_of_file);
  
  made_massive_of_ptr(&info_of_file);
  
  //qsort(info_of_file.strings, info_of_file.quantity_of_str, sizeof(info_of_file.strings[0]), straight_cmp);
  //do_Bubble_sort(info_of_file.strings, info_of_file.quantity_of_str, straight_cmp);
  //writing_to_file(result, info_of_file.strings, info_of_file.quantity_of_str);
  
  MySort(info_of_file.strings, info_of_file.quantity_of_str, sizeof(info_of_file.strings[0]), straight_cmp);
  writing_to_file(result, info_of_file.strings, info_of_file.quantity_of_str);


  fputs("******************************************************\n", result);
  
  //do_Bubble_sort(info_of_file.strings, info_of_file.quantity_of_str, reverse_cmp);
  //writing_to_file(result, info_of_file.strings, info_of_file.quantity_of_str);
  
  MySort(info_of_file.strings, info_of_file.quantity_of_str, sizeof(info_of_file.strings[0]), reverse_cmp);
  writing_to_file(result, info_of_file.strings, info_of_file.quantity_of_str);


  fputs("******************************************************\n", result);

  write_original(result, info_of_file.buffer, info_of_file.quantity_of_sym);

  //MySort(info_of_file.strings, info_of_file.quantity_of_str, sizeof(info_of_file.strings[0]), reverse_cmp);
  //writing_to_file(result, info_of_file.strings, info_of_file.quantity_of_str);

  fclose(result);
  
  free(info_of_file.buffer);
  free(info_of_file.strings);
 
  return 0;
}


