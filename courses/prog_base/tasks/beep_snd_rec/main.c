#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "header.h"
#define UP   72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESCAPE 27
#define ENTER 13




int main()
{
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD pos;
int b_w = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY;
enum Notes {Do , Do_sh,Re, Re_sh, Mi, Fa, Fa_sh, Sol,Sol_sh, La, La_sh, Si };
enum Oct {Small ,first ,second} oct;
enum time {s = 1, m , l = 4};
char key;
char note;
char smb;
int k = 0, j = 0, p = 0,i = 0;;
start:
for (int y = 0; y < 50; y++){
    for (int x = 0; x < 80; x++){
    print(x,y,b_w);
    printf(" ");
    }
}
print(35,16,252);
printf("Repetition");
print(35,18,240);
printf("Record");
print(35,20,240);
printf("Listen");
print(35,22,240);
printf("Jingle Bells");
k = 3;
while(1){
        if (k <=0)
      {
     k = k + 100;
     }
key = getch();
switch(key){

case UP:
    k--;

    break;

case DOWN:
k++;



    break;

case ENTER:
print(35,16,240);
printf("            ");
print(35,18,240);
printf("            ");
print(35,20,240);
printf("            ");
print(35,22,240);
printf("             ");
if (k % 4 == 3)
  {
keys(1,0,25);
keys(12,15,25);
keys(23,15,25);
keys(34,0,25);
keys(45,15,25);
keys(56,15,25);
keys(67,15,25);
keys(78,0,25);
fill_b(9,1);
fill_b(20,1);
fill_b(42,1);
fill_b(53,1);
fill_b(64,1);

pos.Y = 25;
for (int x = 1; x < 79; x++){
    pos.X = x;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, b_w);
    printf("-");
}
print(1,27,245);
printf("To play: a - Do  , s - Re  , d - Mi  , f - Fa   , g - Sol , h - La , j - Si");
print(10,28,245);
printf("w - Do# , e - Re# , t - Fa# , y - Sol# , u - La#");
print(1,29,245);
printf("Use 1 - 3 to change the octave:\n 1 - small\n 2 - first\n 3 - second\n Set by default: first octave.");
print(1,35,245);
printf("Use Shift (Caps Lock) to increase sounding in 2 times.\n Use Ctrl to decrease sounding in 2 times.");
print(1,38,245);
printf("Press Esc to back to the main page");
oct = first;

while(1){
if (note == 1 || note == 'a' || note == 'A'){
    fill_w_1(2,240);
    }
    if (note == 6 || note == 'f' || note == 'F'){
    fill_w_1(35,240);
}
if (note == 19 || note == 's' || note == 'S'){
    fill_w_2(13,240);
}
if (note == 7 || note == 'g' || note == 'G'){
    fill_w_2(46,240);
}
if (note == 8 || note == 'h' || note == 'H'){
    fill_w_2(57,240);
}
if (note == 4 || note == 'd' || note == 'D'){
    fill_w_3(24,240);
}
if (note == 10 || note == 'j' || note == 'J'){
    fill_w_3(68,240);
}
if (note == 23 || note == 'w' || note == 'W'){
    fill_b(9,1);
}
if (note == 5 || note == 'e' || note == 'E'){
    fill_b(20,1);
}
if (note == 20 || note == 't' || note == 'T'){
    fill_b(42,1);
}
if (note == 25 || note == 'y' || note == 'Y'){
    fill_b(53,1);
}
if (note == 21 || note == 'u' || note == 'U'){
    fill_b(64,1);
}
note = getch();

if (note == 1 || note == 'a' || note == 'A'){
    fill_w_1(2,192);
    }
if (note == 6 || note == 'f' || note == 'F'){
    fill_w_1(35,192);
}
if (note == 19 || note == 's' || note == 'S'){
    fill_w_2(13,192);
}
if (note == 7 || note == 'g' || note == 'G'){
    fill_w_2(46,192);
}
if (note == 8 || note == 'h' || note == 'H'){
    fill_w_2(57,192);
}
if (note == 4 || note == 'd' || note == 'D'){
    fill_w_3(24,192);
}
if (note == 10 || note == 'j' || note == 'J'){
    fill_w_3(68,192);
}
if (note == 23 || note == 'w' || note == 'W'){
    fill_b(9,192);
}
if (note == 5 || note == 'e' || note == 'E'){
    fill_b(20,192);
}
if (note == 20 || note == 't' || note == 'T'){
    fill_b(42,192);
}
if (note == 25 || note == 'y' || note == 'Y'){
    fill_b(53,192);
}
if (note == 21 || note == 'u' || note == 'U'){
    fill_b(64,192);
}

switch(note){

case '1':
    oct = Small;
    break;
case '2':
    oct = first;
    break;
case '3':
    oct = second;
    break;
case 'a':
play(oct,Do,m);
  break;

case 's':
play(oct,Re,m);
  break;

case 'd':
play(oct,Mi,m);
    break;

case 'f':
play(oct,Fa,m);
    break;

case 'g':
play(oct,Sol,m);
    break;

case 'h':
play(oct,La,m);
    break;

case 'j':
play(oct,Si,m);
   break;

case 'w':
play(oct,Do_sh,m);
break;

case 'e':
play(oct,Re_sh,m);
break;

case 't':
play(oct,Fa_sh,m);
break;

case 'y':
play(oct,Sol_sh,m);
break;

case 'u':
play(oct,La_sh,m);
break;

case 'A':
play(oct,Do,l);
  break;

case 'S':
play(oct,Re,l);
  break;

case 'D':
play(oct,Mi,l);
    break;

case 'F':
play(oct,Fa,l);
    break;

case 'G':
play(oct,Sol,l);
    break;

case 'H':
play(oct,La,l);
    break;

case 'J':
play(oct,Si,l);
   break;

case 'W':
play(oct,Do_sh,l);
break;

case 'E':
play(oct,Re_sh,l);
break;

case 'T':
play(oct,Fa_sh,l);
break;

case 'Y':
play(oct,Sol_sh,l);
break;

case 'U':
play(oct,La_sh,l);
break;



case 1:
play(oct,Do,s);
  break;

case 19:
play(oct,Re,s);
  break;

case 4:
play(oct,Mi,s);
    break;

case 6:
play(oct,Fa,s);
    break;

case 7:
play(oct,Sol,s);
    break;

case 8:
play(oct,La,s);
    break;

case 10:
play(oct,Si,s);
   break;

case 23:
play(oct,Do_sh,s);
break;

case 5:
play(oct,Re_sh,s);
break;

case 20:
play(oct,Fa_sh,s);
break;

case 25:
play(oct,Sol_sh,s);
break;

case 21:
play(oct,La_sh,s);
break;

case ESCAPE:
goto start;
    break;
}


}

}

if (k % 4 == 0){

keys(1,0,25);
keys(12,15,25);
keys(23,15,25);
keys(34,0,25);
keys(45,15,25);
keys(56,15,25);
keys(67,15,25);
keys(78,0,25);
fill_b(9,1);
fill_b(20,1);
fill_b(42,1);
fill_b(53,1);
fill_b(64,1);

pos.Y = 25;
for (int x = 1; x < 79; x++){
    pos.X = x;
    SetConsoleCursorPosition(hConsole, pos);
    SetConsoleTextAttribute(hConsole, b_w);
    printf("-");
}
print(1,37,245);
printf("To play: a - Do  , s - Re  , d - Mi  , f - Fa   , g - Sol , h - La , j - Si");
print(10,38,245);
printf("w - Do# , e - Re# , t - Fa# , y - Sol# , u - La#");
print(1,39,245);
printf("Use 1 - 3 to change the octave:\n 1 - small\n 2 - first\n 3 - second\n Set by default: first octave.");
print(1,45,245);
printf("Use Shift (Caps Lock) to increase sounding in 2 times.\n Use Ctrl to decrease sounding in 2 times.");
print(1,48,245);
printf("Press Esc to back to the main page");
oct = first;
rec:
print(1,27,252);
printf("Press s to start recording.\n");
smb = getch();
if (smb == 's'){
print(1,27,252);
printf("                                   ");
print(1,27,252);
printf("Recording was started... Press Enter to stop recording.");
while(1){
if (note == 1 || note == 'a' || note == 'A'){
    fill_w_1(2,240);
    }
    if (note == 6 || note == 'f' || note == 'F'){
    fill_w_1(35,240);
}
if (note == 19 || note == 's' || note == 'S'){
    fill_w_2(13,240);
}
if (note == 7 || note == 'g' || note == 'G'){
    fill_w_2(46,240);
}
if (note == 8 || note == 'h' || note == 'H'){
    fill_w_2(57,240);
}
if (note == 4 || note == 'd' || note == 'D'){
    fill_w_3(24,240);
}
if (note == 10 || note == 'j' || note == 'J'){
    fill_w_3(68,240);
}
if (note == 23 || note == 'w' || note == 'W'){
    fill_b(9,1);
}
if (note == 5 || note == 'e' || note == 'E'){
    fill_b(20,1);
}
if (note == 20 || note == 't' || note == 'T'){
    fill_b(42,1);
}
if (note == 25 || note == 'y' || note == 'Y'){
    fill_b(53,1);
}
if (note == 21 || note == 'u' || note == 'U'){
    fill_b(64,1);
}
note = getch();

if (note == 1 || note == 'a' || note == 'A'){
    fill_w_1(2,192);
    }
if (note == 6 || note == 'f' || note == 'F'){
    fill_w_1(35,192);
}
if (note == 19 || note == 's' || note == 'S'){
    fill_w_2(13,192);
}
if (note == 7 || note == 'g' || note == 'G'){
    fill_w_2(46,192);
}
if (note == 8 || note == 'h' || note == 'H'){
    fill_w_2(57,192);
}
if (note == 4 || note == 'd' || note == 'D'){
    fill_w_3(24,192);
}
if (note == 10 || note == 'j' || note == 'J'){
    fill_w_3(68,192);
}
if (note == 23 || note == 'w' || note == 'W'){
    fill_b(9,192);
}
if (note == 5 || note == 'e' || note == 'E'){
    fill_b(20,192);
}
if (note == 20 || note == 't' || note == 'T'){
    fill_b(42,192);
}
if (note == 25 || note == 'y' || note == 'Y'){
    fill_b(53,192);
}
if (note == 21 || note == 'u' || note == 'U'){
    fill_b(64,192);
}

switch(note){

case '1':
    oct = Small;
    break;
case '2':
    oct = first;
    break;
case '3':
    oct = second;
    break;
case 'a':
play(oct,Do,m);
record(oct,Do,m,j,i);
  break;

case 's':
play(oct,Re,m);
record(oct,Re, m, j,i);
  break;

case 'd':
play(oct,Mi,m);
record(oct,Mi, m, j,i);
    break;

case 'f':
play(oct,Fa,m);
record(oct,Fa, m, j,i);
    break;

case 'g':
play(oct,Sol,m);
record(oct,Sol, m, j,i);
    break;

case 'h':
play(oct,La,m);
record(oct,La, m, j,i);
    break;

case 'j':
play(oct,Si,m);
record(oct,Si, m, j,i);
   break;

case 'w':
play(oct,Do_sh,m);
record(oct,Do_sh, m, j,i);
break;

case 'e':
play(oct,Re_sh,m);
record(oct,Re_sh, m, j,i);
break;

case 't':
play(oct,Fa_sh,m);
record(oct,Fa_sh, m, j,i);
break;

case 'y':
play(oct,Sol_sh,m);
record(oct,Sol_sh, m, j,i);
break;

case 'u':
play(oct,La_sh,m);
record(oct,La_sh, m, j,i);
break;

case 'A':
play(oct,Do,l);
record(oct,Do, l, j,i);
  break;

case 'S':
play(oct,Re,l);
record(oct,Re, l, j,i);
  break;

case 'D':
play(oct,Mi,l);
record(oct,Mi, l, j,i);
    break;

case 'F':
play(oct,Fa,l);
record(oct,Fa, l, j,i);
    break;

case 'G':
play(oct,Sol,l);
record(oct,Sol, l, j,i);
    break;

case 'H':
play(oct,La,l);
record(oct,La, l, j,i);
    break;

case 'J':
play(oct,Si,l);
record(oct,Si, l, j,i);
   break;

case 'W':
play(oct,Do_sh,l);
record(oct,Do_sh, l, j,i);
break;

case 'E':
play(oct,Re_sh,l);
record(oct,Re_sh, l, j,i);
break;

case 'T':
play(oct,Fa_sh,l);
record(oct,Fa_sh, l, j,i);
break;

case 'Y':
play(oct,Sol_sh,l);
record(oct,Sol_sh, l, j,i);
break;

case 'U':
play(oct,La_sh,l);
record(oct,La_sh, l, j,i);
break;



case 1:
play(oct,Do,s);
record(oct,Do, s, j,i);
  break;

case 19:
play(oct,Re,s);
record(oct,Re, s, j,i);
  break;

case 4:
play(oct,Mi,s);
record(oct,Mi, s, j,i);
    break;

case 6:
play(oct,Fa,s);
record(oct,Fa, s, j,i);
    break;

case 7:
play(oct,Sol,s);
record(oct,Sol, s, j,i);
    break;

case 8:
play(oct,La,s);
record(oct,La, s, j,i);
    break;

case 10:
play(oct,Si,s);
record(oct,Si, s, j,i);
   break;

case 23:
play(oct,Do_sh,s);
record(oct,Do_sh, s, j,i);
break;

case 5:
play(oct,Re_sh,s);
record(oct,Re_sh, s, j,i);
break;

case 20:
play(oct,Fa_sh,s);
record(oct,Fa_sh, s, j,i);
break;

case 25:
play(oct,Sol_sh,s);
record(oct,Sol_sh, s, j,i);
break;

case 21:
play(oct,La_sh,s);
record(oct,La_sh, s, j,i);
break;

case ENTER:
print(0,27,245);
printf("                                                                               ");
print(0,27,252);
printf("Recording stoped, press any key to renew. Press Enter again to end recording.");
print(1,30,252);
if (getch() == ENTER){
    print(0,27,245);
    printf("                                                                               ");
    j++;
    i = 0;
    goto rec;


}
else {
 print(0,27,245);
 printf("                                                                               ");
  print(1,27,252);
 printf("Recording has been renewed...");
}
    break;
}

if (note != ENTER){
    i++;
}
}

}
else if (smb == ESCAPE) goto start;
else goto rec;
}

if (k % 4 == 1){
while(1){
char kk;
print(1,1,252);
printf("Press Escape to exit or any key to continue");
kk = getch();
printf("                                           ");
if (k == ESCAPE){
    goto start;
}

print(1,1,245);
printf("While sounding press p to stop, press any key to renew, press Esc to exit");
print(1,3,252);
printf("Please, select number of track (0 - %d): ", j-1);
scanf("%d", &p);
print(1,4,245);
for (int n = 0; n < 200; n++){
if (kbhit()){
    char ck;
ck = getch();
    if (ck == 'p'){
      getch();
    }
    else if(ck == ESCAPE){
        goto start;
    }
}
playnp(p,n);
}

for (int n = 0; n < 8; n++){
        for (int m = 0; m <  80; m++){
print(m,n,252);
printf(" ");
        }
}
}
}
if (k % 4 == 2){
jingle_bells();
}

break;
}


if (k % 4 == 0){
print(35,16,240);
printf("Repetition");
print(35,18,252);
printf("Record");
print(35,20,240);
printf("Listen");
print(35,22,240);
printf("Jingle Bells");
}
if (k % 4  == 1){
print(35,16,240);
printf("Repetition");
print(35,18,240);
printf("Record");
print(35,20,252);
printf("Listen");
print(35,22,240);
printf("Jingle Bells");
}
if (k % 4 == 3){
print(35,16,252);
printf("Repetition");
print(35,18,240);
printf("Record");
print(35,20,240);
printf("Listen");
print(35,22,240);
printf("Jingle Bells");
}

if (k % 4 == 2){
print(35,16,240);
printf("Repetition");
print(35,18,240);
printf("Record");
print(35,20,240);
printf("Listen");
print(35,22,252);
printf("Jingle Bells");
}

}
return 0;
}
