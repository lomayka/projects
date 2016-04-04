#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "array.h"

int arr[3];

int getArray(int index){

return arr[index];
}

void setArray(int index, int value){
arr[index] = value;
}

int * getArr(){
return arr;
}
