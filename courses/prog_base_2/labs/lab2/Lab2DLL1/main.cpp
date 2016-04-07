#include "main.h"
#include <stdio.h>
int compare(stack_t * a)
{
    int p = stack_peek(a);
    if ( p < 0) return p*(-1);
    else return 0;
}

void reaction(stack_t * a)
{
    int com = compare(a);
    int count = stack_getCount(a);
                  if (com != 0)
    {
        if (com < count)
        {
            for (int i = 0; i < com; i++)
            {
                stack_pop(a);
            }
        }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    stack_pop(a);
                }
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
