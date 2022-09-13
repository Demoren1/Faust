#include "funcs.h"

void test_func(char** arr, int (*compar)(const void *, const void *));
int test_func2(const void *, const void *);

int main()
{
    FILE *file_of_faust;
    FILE *result; // uninit

    result = fopen("result.txt", "w"); // file name str || cmd arg

    file_of_faust = fopen("test_text.txt", "r");
    assert(file_of_faust != NULL);
    
    int QUANTITY_OF_SYM = 0; // size t
    
    // -> function
    fseek(file_of_faust, 0L, SEEK_END);
    QUANTITY_OF_SYM = ftell(file_of_faust) + 2;
    fseek(file_of_faust, 0L, SEEK_SET);
    //puts("in size");   

    // input
     char buff_of_Faust[QUANTITY_OF_SYM] = {0};
    printf("%d %d\n", sizeof (buff_of_Faust), QUANTITY_OF_SYM);
    //char* buff_of_Faust = (char*) malloc (QUANTITY_OF_SYM+200000); 
    char *(pFaust[QUANTITY_OF_STR]) = {}; // fseek
    int counter = 0;
    int nfread = 0;
    nfread = fread(buff_of_Faust, sizeof(char), QUANTITY_OF_SYM, file_of_faust);
    //for (int j = 0; j < QUANTITY_OF_SYM-2; j++)
//	    printf("%d\n", buff_of_Faust[j]);
  //  printf("%d\n %d\n", nfread, QUANTITY_OF_SYM);
    //puts("not in size");
    new_line_changer(buff_of_Faust, QUANTITY_OF_SYM);
    //puts("not in  changer");
    made_massive_of_ptr(buff_of_Faust, pFaust, QUANTITY_OF_SYM);
    //puts("not in made massive ptr");
   // qsort(pFaust, QUANTITY_OF_STR, sizeof(pFaust[0]), Strcmp);
    puts("not in qsort");
    for (int i = 0; i < QUANTITY_OF_STR && *pFaust != NULL; i++)
    {
	puts ("x alive");
	printf("%d %s\n", i, pFaust[i]);
	int x = (pFaust[i][0] !=0);
	puts("x still alive");
       	if (x)
            fprintf(result, "%s \n", (char*) pFaust[i]);
    } // pwngdb 

    fclose(file_of_faust);
    fclose(result);
   // getchar();
    return 0;
}//
