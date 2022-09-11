#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int int_cmp (const void* left_val, const void* right_val)
{
    if (*((int*) left_val) < *((int*) right_val))
        return -1;

    return 1;
}

int strcmp_void (const void* left_val, const void* right_val)
{
    return strcmp((const char*) left_val, (const char*) right_val);
}

int main()
{
    const char* test_text[3] = {"aaa", "ccc", "bbb"};

    int arr[] = {3, 5, 1};
    size_t arr_len = sizeof arr / sizeof arr[0];

    qsort(test_text, 3, sizeof(test_text[0]), strcmp_void);

    qsort(arr, arr_len, sizeof(arr[0]), int_cmp);

    for (size_t val_id = 0; val_id < arr_len; val_id++)
        printf("%s %d\n", test_text[val_id], arr[val_id]);
}

