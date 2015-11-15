#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main(void){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
 int fmt = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
 int fmt1 = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
 int fmt2 = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
int i = 0, j = 0, k = 0, c = 0, m = 0 ,l = 0;
for (k = 0; k < 105; k++){
    if (k % 3 == 0){
         SetConsoleTextAttribute(hConsole, fmt);

    }
    if ( k % 3 == 1){
        SetConsoleTextAttribute(hConsole, fmt1);
    }
    if (k % 3 == 2 ){
        SetConsoleTextAttribute(hConsole, fmt2);
    }
        if ( k < 25){
        if (k % 2 == 0){

for(i = 0; i < k+1; i++ ){
    c = k-i;
    pos.X = c;
    pos.Y = i;
    SetConsoleCursorPosition(hConsole, pos);
        printf("*");
        usleep(10000);


}
}
if (k % 2 == 1){
            for (j = 0; j <k+1; j++){
                c = i-j;
         pos.X = j;
         pos.Y = c;
        SetConsoleCursorPosition(hConsole, pos);


                  printf("*");
                usleep(10000);
            }
}
        }
if (k >= 25 && k  < 80){
if  (k % 2 == 1){
for (i = 24; i >= 0; i--){
        c = k-i;
         pos.X = c;
         pos.Y = i;
        SetConsoleCursorPosition(hConsole, pos);
        printf("*");
        usleep(10000);
    }
}


else{
    for (i = 0; i <= 24; i++){
        c = k-i;
         pos.X = c;
         pos.Y = i;
        SetConsoleCursorPosition(hConsole, pos);
        printf("*");
        usleep(10000);
    }
}
}
if (k >= 80 && k < 105){
        if (k % 2 == 0){
        for (i = 1+l; i < 25; i++){
        c = k - i;
         pos.X = c;
         pos.Y = i;
        SetConsoleCursorPosition(hConsole, pos);
        printf("*");
        usleep(10000);
        }
        l= l + 2;
        }
        else{
                m = 79;
            for (i = 24; i >=k - m; i--){
                c = k-i;
         pos.X = c;
         pos.Y = i;
        SetConsoleCursorPosition(hConsole, pos);

        printf("*");
        usleep(10000);

            }
            m++;
        }
}
}
return EXIT_SUCCESS;
}


