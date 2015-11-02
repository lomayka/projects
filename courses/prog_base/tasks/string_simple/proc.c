#include <stdio.h>
#include <string.h>
char *process (char *resultStr, const char *textLines [], int linesNum, const char *extraStr) {
    int maxCounter = 0;
    int maxIndex = 0;
    int maxLength = 0;
    int counter = 0;
    int length=0;
    int i=0;
    int j=0;
    char * p;

    for (i = 0; i < linesNum; i++) {
            counter=0;
        for (j = 0; j < linesNum; j++) {
            if (strcmp(textLines[i], textLines[j]) == 0) {
                counter++;
            }
        }
        length = strlen(textLines[i]);
        if (counter > maxCounter) {
            maxCounter = counter;
            maxIndex = i;
            maxLength = length;
        }
        if (counter==maxCounter){
        if (length > maxLength){
            maxLength = length;
            maxIndex = i;
            }
        }


    }
    if (maxCounter==1){
        p="0 NULL";
    sprintf(resultStr, "%s %s", p, extraStr);
    return resultStr;

    }


    sprintf(resultStr, "%d %s", maxCounter, textLines[maxIndex]);
    return resultStr;
}
