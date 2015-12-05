/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fprocess(const char * pread, const char * pwrite);
int main()
{
    char * pread = "in.txt";
    char * pwrite = "out.txt";
   fprocess(pread,pwrite);
   return 0;
}*/
void fprocess(const char * pread, const char * pwrite){
FILE * fp = fopen(pread, "r");
int n = 0, N = 0, p = 0, min = 0, min_index = 0;
char * str;
char * a;
str = malloc(100*sizeof(char));
n = 0;
 while (n < 10){
    fgets(str,100,fp);
    n++;
    }
    str = strtok(str," ");
    N = atoi(str);
        str = strtok(NULL,",");
        p = atoi(str);
        min = p;
    for (int i = 1; i < N; i++){
        str = strtok(NULL,",");
        p = atoi(str);
        if (p < min){
            min = p;
            min_index = i;
        }
    }



fclose(fp);
fflush(fp);
FILE * pf = fopen(pwrite, "w");
fprintf(pf,"%d",min_index);

fclose(pf);
free(str);
}
