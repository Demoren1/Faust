#include "funcs.h"

void test_func(char** arr, int (*compar)(const void *, const void *));
int test_func2(const void *, const void *);

int main()
{
    FILE *file_of_faust;
    FILE *result;

    result = fopen("result.txt", "w");

    file_of_faust = fopen("work_text2.txt", "r");
    assert(file_of_faust != NULL);

    char buff_of_Faust[QUANTITY_OF_SYM] = {0};
    char *(pFaust[QUANTITY_OF_STR]) = {}; // fseek
    int counter = 0;

    fread(buff_of_Faust, sizeof(char), QUANTITY_OF_SYM, file_of_faust);

    new_line_changer(buff_of_Faust);

    made_massive_of_ptr(buff_of_Faust, pFaust);


    qsort(pFaust, QUANTITY_OF_STR, sizeof(pFaust[0]), Strcmp);

    for (int i = 0; i < QUANTITY_OF_STR && *pFaust != NULL; i++)
    {
       	if (pFaust[i][0] != 0)
            fprintf(result, "%s  %d %3d \n", pFaust[i], pFaust[i][0], counter++);
    }

    fclose(file_of_faust);
    fclose(result);
    getchar();
    return 0;
}//
