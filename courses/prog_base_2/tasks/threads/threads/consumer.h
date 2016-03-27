#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "mutex.h"

typedef HANDLE module_t;
DWORD threadRead(LPVOID);
void free_consumer(module_t * consumer);
module_t * new_comsumer(mutex_t * mutex, int arr[]);
