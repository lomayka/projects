#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

typedef HANDLE mutex_t;
mutex_t * new_mutex();
void free_mutex(mutex_t *);
