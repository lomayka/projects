#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char * str = NULL;
    int * len = NULL;
    int * i = NULL;
    int * count = NULL;
    i = (int *)malloc(sizeof(int));
    len = (int *)malloc(sizeof(int));
    count = (int *)malloc(sizeof(int));
    str = (char*)malloc(30*sizeof(char));
    if (NULL == len || NULL == i || NULL == count || NULL == str){
        printf("Error");
        return EXIT_FAILURE;
    }
     gets(str);
    *len = strlen(str);
    *count = 0;
    *i = 0;
    for (*i = 0; *i < *len; (*i)++){
        if (0 != isspace(str[*i])){
         (*count)++;
        }
    }
    printf("%d", *count);
    free(str);
    free(i);
    free(count);
    free(len);
    return 0;
}
