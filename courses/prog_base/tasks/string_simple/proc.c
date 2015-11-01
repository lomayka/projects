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
    char tempResult[100];

    for (i = 0; i < linesNum; i++) {
        for (j = 0; j < linesNum; j++) {
            if (strcmp(textLines[i], textLines[j]) == 0) {
                counter++;
            }
        }
        length = strlen(textLines[i]);
        if (counter > maxCounter) {
            maxCounter = counter;
            maxIndex = i;
        }
        if (counter==maxCounter){
        if (length > maxLength){
            maxLength = length;
            maxIndex = i;
            }
        }

    }

    sprintf(tempResult, "%d, %s", maxCounter, textLines[maxIndex]);
    resultStr = tempResult;
    return resultStr;
}
