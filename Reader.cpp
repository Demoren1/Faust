#include "funcs.h"


int main()
{
    FILE *file_of_faust;
    FILE *result;
    result = fopen("result.txt", "w");
    file_of_faust = fopen("work_text.txt", "a+");
    char Faust[QUANTITY_OF_SYM];
    char *(pFaust[QUANTITY_OF_STR]);


    fread(Faust, sizeof(char), QUANTITY_OF_SYM, file_of_faust);

    new_line_changer(Faust);

    made_massive_of_ptr(Faust, pFaust, QUANTITY_OF_STR);

    sorter(pFaust);

    for (int i = 0; i < QUANTITY_OF_STR && *pFaust != NULL; i++)
    {
        if (pFaust[i][0] != '\n' || pFaust[i][0] != '\0')
            fprintf(result, "%s %3d \n", pFaust[i], i);
    }

    fclose(file_of_faust);
    fclose(result);
    return 0;
}

