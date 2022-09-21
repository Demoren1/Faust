#include "../include/funcs.h"

int main(int argc, char** argv)
{ 
  const char *start_file = (argc > 1) ? argv[1] : "work_text2.txt";
  const char *name_of_file = start_file;

  FILE *result = file_open("result.txt");
  FILE *file_of_faust = fopen(name_of_file, "r");

  assert(file_of_faust != NULL);
  assert(result != NULL);
  
  struct Information info_of_file = {};   
  text_read(name_of_file, &info_of_file, file_of_faust);                                    
  
  text_my_sort(info_of_file.strings, info_of_file.quantity_of_str, sizeof(info_of_file.strings[0]), straight_cmp);
  text_write_to_file(result, info_of_file.strings, info_of_file.quantity_of_str);

  text_my_sort(info_of_file.strings, info_of_file.quantity_of_str, sizeof(info_of_file.strings[0]), reverse_cmp);
  text_write_to_file(result, info_of_file.strings, info_of_file.quantity_of_str);

  text_write_original(result, info_of_file.buffer, info_of_file.quantity_of_sym);

  fclose(result);
  fclose(file_of_faust);

  text_detor(&info_of_file);

  return 0;
}


