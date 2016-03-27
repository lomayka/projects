#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "mutex.h"

typedef HANDLE module_t;
DWORD threadWrite(LPVOID args);
void free_producer(module_t * producer);
module_t * new_producer(mutex_t * mutex, int arr[]);
