#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producer.h"
#include <windows.h>
#include <conio.h>
#include "mutex.h"
#include <time.h>
#include "array.h"


module_t * new_producer(mutex_t * mutex)
{   LPVOID args = (LPVOID)mutex;
    HANDLE hReadThread = CreateThread(
                             NULL,               // default security attributes
                             0,                  // default stack size
                             (LPTHREAD_START_ROUTINE) threadWrite,
                             (LPVOID) args ,               // no thread function arguments
                             0,                  // default creation flags
                             NULL);// receive thread identifier


return hReadThread;
}

void free_producer(module_t * producer){
CloseHandle(producer);
}


DWORD threadWrite(LPVOID args) {
mutex_t * hMutex = (mutex_t*)args;
srand(time(NULL));
while(1){

WaitForSingleObject(hMutex, INFINITE);
for (int i = 0; i < 3; i++){
    setArray(i,rand()%10);
    Sleep(10);

}
ReleaseMutex(hMutex);
}
}

