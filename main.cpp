#include "funcs.h"
const int NUM_OF_FILE = 3;
int main()
{
  FILE *file_of_faust;
  FILE *result = fopen("result.txt", "w");  

  const char* names_of_files[] = {"test_text.txt",
                                  "work_text1.txt", 
                                  "work_text2.txt", 
                                  "work_text3.txt"};

  file_of_faust = fopen(names_of_files[NUM_OF_FILE], "r");
  assert(file_of_faust != NULL);
    
  size_t quantity_of_sym = 0; 
    
  find_lenght_of_buff(file_of_faust, &quantity_of_sym, names_of_files[NUM_OF_FILE]);

  char buff_of_Faust[quantity_of_sym] = {};
 
  fread(buff_of_Faust, sizeof(char), quantity_of_sym, file_of_faust);
    
  int QUANTITY_OF_STR = new_line_changer(buff_of_Faust, quantity_of_sym);
  
  char *(pFaust[QUANTITY_OF_STR]) = {};

  made_massive_of_ptr(QUANTITY_OF_STR, buff_of_Faust, pFaust, quantity_of_sym);

  do_Bubble_sort(pFaust, QUANTITY_OF_STR);
  writing_to_file(result, pFaust, QUANTITY_OF_STR);

  qsort(pFaust, QUANTITY_OF_STR, sizeof(pFaust[0]), Strcmp);
  writing_to_file(result, pFaust, QUANTITY_OF_STR);
 
  made_massive_of_ptr(QUANTITY_OF_STR, buff_of_Faust, pFaust, quantity_of_sym);
  
  //MySort(pFaust, QUANTITY_OF_STR, sizeof(pFaust[0]), MyCmp);
  
  fclose(file_of_faust);
  fclose(result);
  // getchar();
  return 0;
}


