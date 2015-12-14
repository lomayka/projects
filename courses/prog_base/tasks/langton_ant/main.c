/*

Зробив золотистий колір для кращої візуалізації, просто вважайте, що золотистий і білий одне й теж, але якщо потрібно то перероблю.
Сподіваюся, що не отримаю котика.

*/



#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#define WHITE 98
#define BLACK 0
void print(int x, int y, int color);

int main()
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
int red_w = FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN |BACKGROUND_RED | BACKGROUND_INTENSITY;
int white =  BACKGROUND_BLUE | BACKGROUND_GREEN |BACKGROUND_RED | BACKGROUND_INTENSITY;
    int mat[100][150];
    int direction;
    int i = 50, j = 80, speed = 1;

    for(int i = 0; i < 100; i++){
        for (int j = 0; j < 150; j++){
            mat[i][j] = WHITE;
        }
    }
    direction = 2;
print(1,1,red_w);
printf("Please, set the size of your console 120 * 120 with white fone.\n Press any key to continue");
getch();
system("cls");
for (int y = 0; y < 120; y++){    // just to be sure
    for (int x = 0; x < 150; x++){
        print(x,y,white);
        printf(" ");
    }
}
print(1,1,red_w);
printf("Please, use 1-7 to chage speed. Press Enter to stop and any key to continue. Press Esc to exit.");

 while(1){
       if (kbhit()){
    switch(getch()){
    case '1':
    speed = 1;
    break;

    case '2':
    speed = 2;
    break;

    case '3':
    speed = 4;
    break;

    case '4':
    speed = 10;
    break;

    case '5':
    speed = 20;
    break;

    case '6':
    speed = 40;
    break;

    case '7':
    speed = 100;
    break;

    case 13:
    getch();
    break;

    case 27:
    exit(0);
    break;
               }
       }
    if (100 == i || 150 == j || 0 == i || 0 == j){
        break;
    }
    if (WHITE == mat[i][j]){
        mat[i][j] = BLACK;
    print(j,i,red);
    printf("*");
    usleep(100000/speed);
    print(j,i,mat[i][j]);
    printf(" ");


        if (direction == 1){
            i--;
            direction = 2;


        }
        else if(direction == 2){
            j++;
            direction = 3;

        }
        else if(direction == 3){
              i++;
            direction = 4;
        }
        else if (direction == 4){
            j--;
            direction = 1;
        }
}


     if (BLACK == mat[i][j]) {
            mat[i][j] = WHITE;
    print(j,i,red);
    printf("*");
    usleep(100000/speed);
    print(j,i,mat[i][j]);
    printf(" ");

       if (direction == 1){
            i++;
            direction = 4;


       }
       else if(direction == 4){
            j++;
            direction = 3;

        }
        else if(direction == 3){
              i--;
            direction = 2;
        }
        else if (direction == 2){
            j--;
            direction = 1;
        }




     }
 }
    return 0;
}

void print(int x, int y, int color){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
                pos.X = x;
                pos.Y = y;
                SetConsoleCursorPosition(hConsole, pos);
                SetConsoleTextAttribute(hConsole, color);


}
