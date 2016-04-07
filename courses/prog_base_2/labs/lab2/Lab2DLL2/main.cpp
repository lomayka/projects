#include "main.h"

int compare(stack_t * a)
{
    int count = stack_getCount(a);
     stack_t * b = stack_new();
     stack_copy(a,b);
    int sum = 0;
    for (int i = 0; i < count; i++ ){
      sum+= stack_pop(b);
    }
    if (sum > 255) return 1;
    if (sum < 100) return 2;
    else return 0;
}

void reaction(stack_t * a)
{
    if(compare(a) == 1){
    while(compare(a) != 2 ){
   stack_pop(a);
    }
}
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // attach to process
        // return FALSE to fail DLL load
        break;

    case DLL_PROCESS_DETACH:
        // detach from process
        break;

    case DLL_THREAD_ATTACH:
        // attach to thread
        break;

    case DLL_THREAD_DETACH:
        // detach from thread
        break;
    }
    return TRUE; // succesful
}
