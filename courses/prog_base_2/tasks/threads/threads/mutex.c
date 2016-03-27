#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "mutex.h"

mutex_t * new_mutex(){
mutex_t hMutex = CreateMutex(
        NULL,               // default security attributes
        FALSE,              // initially not owned
        NULL);              // unnamed mutex
return hMutex;
}

void free_mutex(mutex_t * mutex){
CloseHandle(mutex);

}
