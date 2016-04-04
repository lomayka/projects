#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fprocess(const char * pread, const char * pwrite);

int main(void){
char * pread = "in.txt";
char * pwrite = "out.txt";
fprocess(pread,pwrite);
}

void fprocess(const char * pread, const char * pwrite){
    FILE * fp = fopen(pread, "r");
    char str[100];
    char * endstr;
    double arr [100];
    int len = 0 , cnt = 0, d = 0;
    fgets(str,100,fp);
    len = strlen(str);
    cnt = 0;
    double r = 0;
     for (int i = len; i > 0;  i-- ){
//double r = strtod(str,&endstr);

    /* if (0.0 != r){

            printf("%f ", r);
        cnt++;
        if (5 == cnt){
            break;
        }


    }*/
      r = atov(&str[cnt])
    if (0.0 != r){
      arr[cnt] = r;
      cnt++;
    }

    }
    fclose(fp);

    FILE * pf = fopen(pread, "r");
    for (int m = 0; m < cnt; cnt++){
      fprintf(pf,"%d",arr[m]);

    }

    fclose(pf);


}
