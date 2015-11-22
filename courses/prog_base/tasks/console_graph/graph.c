#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void curs(int x, int y, int color){
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
pos.X = x;
pos.Y = y;
SetConsoleCursorPosition(hConsole, pos);
SetConsoleTextAttribute(hConsole, color);
}
int main(void){
int red = FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN| BACKGROUND_RED | BACKGROUND_INTENSITY;
int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
int blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY| BACKGROUND_BLUE | BACKGROUND_INTENSITY;
int white = FOREGROUND_RED| FOREGROUND_GREEN|BACKGROUND_BLUE | BACKGROUND_GREEN| BACKGROUND_RED | BACKGROUND_INTENSITY ;

int i = 0, m = 0, n = 0,y = 0, x = 0,l = 0;
char c;
double k = 1;


while(1){
system("color F6");
i = 0;
while (i*k < 25){
curs(40+n*k,i*k,red);
if ((int)k*i % 2 == 0){
printf("+");
 }
 else {
 printf("|");
 }

 i++;
}
i = 0;
while(i*k < 80){
curs(i*k,12+m*k,red);
 if ((int)k*i % 5 == 0){
printf("+");
 }
 else {
 printf("-");
 }
   i++;
}
x = (-5+n)/k;
while(x < 40){
 y =(7 - sqrt(x+5-n)+m)*k;
 curs(x+40, y+12,green);
if (x + 40 >=0 && y+12 >=0 && x+40 < 80 && y+12 < 25)
 printf(".");
    x = x+1;

}
x = (-90-n)/k;
while(x<40){
y = (-(ctan(x-5-n)-sin(x-n)-m))*k;
 curs(x+40, y+12,blue);
 if (x + 40 >=0 && y+12 >=0 && x+40 < 80 && y+12 < 25 )
 printf("*");
    x = x+1;
}
curs(0, 0,white);
printf("F(x) = sqrt(x+5)-7\n");
printf("F(x) = ctg(x-5)-sin(x)\n");
printf("w - up\n");
printf("s - down\n");
printf("a - left\n");
printf("d - right\n");
printf("p - zoom+\n");
printf("n - zoom-\n");
c=getch();
switch(c){
case 'w': m = m+2;
break;
case 's': m = m-2;
break;
case 'a': n = n+5;
break;
case 'd': n = n-5;
break;
case 'p': k = 2*k;
break;
case 'n': k = k/2;
break;
case 13:
    exit(1);

}
system("cls");





}
system("cls");
return 0;
}
