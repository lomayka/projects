#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int lastnspace(const char * pf, const char * pc) {
    if (pf > pc)         return -1;
    else if (0 == isspace(*pc))   return (int)*pc;
    else                        return lastnspace(pf, pc - 1);
}

int firstnspace(const char * pf, const char * pc) {
    if (pf > pc)         return -1;
    else if (0 == isspace(*pf))   return (int)*pf;
    else                        return firstnspace(pf+1, pc);
}

int main(){
char str [30];
printf("Please, enter your string: ");
gets(str);
printf("Result: %i", firstnspace(str, str + strlen(str) - 1)- lastnspace(str, str + strlen(str) - 1));
return 0;
}


