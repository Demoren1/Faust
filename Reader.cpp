#include "funcs.h"

int main()
{
  FILE *file_of_faust;
  FILE *result = fopen("result.txt", "w");  // file name str || cmd arg

  file_of_faust = fopen("work_text2.txt", "r");
  assert(file_of_faust != NULL);
    
  size_t QUANTITY_OF_SYM = 0; // size t
    
  find_lenght_of_buff(file_of_faust, &QUANTITY_OF_SYM);

  char buff_of_Faust[QUANTITY_OF_SYM] = {};
  
  int counter = 0;
  int nfread = 0;
 
  nfread = fread(buff_of_Faust, sizeof(char), QUANTITY_OF_SYM, file_of_faust);
    
  int QUANTITY_OF_STR = new_line_changer(buff_of_Faust, QUANTITY_OF_SYM);
  
  char *(pFaust[QUANTITY_OF_STR]) = {};

  made_massive_of_ptr(QUANTITY_OF_STR, buff_of_Faust, pFaust, QUANTITY_OF_SYM);

  qsort(pFaust, QUANTITY_OF_STR, sizeof(pFaust[0]), Strcmp);
    
  writing_to_file(result, pFaust, QUANTITY_OF_STR);
 // pwngdb 
  made_massive_of_ptr(QUANTITY_OF_STR, buff_of_Faust, pFaust, QUANTITY_OF_SYM);
  
  //MySort(pFaust, QUANTITY_OF_STR, sizeof(pFaust[0]), MyCmp);
  
  Bubble_sort(pFaust, QUANTITY_OF_STR);
  writing_to_file(result, pFaust, QUANTITY_OF_STR);
  
  fclose(file_of_faust);
  fclose(result);
  // getchar();
  return 0;
}


