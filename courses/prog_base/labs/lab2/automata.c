#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum operations {Pop=-5, Push, Repeat, Continue, Break = -1 };
int run(int moves[], int movesLen, int res[], int resLen);
int main(void){
int  movesLen, resLen;
int moves[] = {2,10,20,10,2};
movesLen = sizeof(moves)/sizeof(int);
resLen = sizeof(moves)/sizeof(int);
int res[resLen];
printf("%d ", run(moves, movesLen, res, resLen));
return 0;
}
int run(int moves[], int movesLen, int res[], int resLen){
int i, a, j, n = 0, current_state = 0;
int state[][4]={{1,2,3,0},
                {-1,1,2,-1},
                {0,3,1,2},
                {-1,-1,-1,2}};
int operation[][4]={{11,55,101,Continue},
                {-1,Pop,1,-1},
                {Pop,5,Repeat,11},
                {-1,-1,-1,2}};
for (i = resLen-1; i >= j; i-- ){
    res[i] = 0;
}
for (i = 0; i < movesLen; i++){
switch (moves[i]){
case 2: a = 0;
    break;
case 10: a = 1;
    break;
case 20: a = 2;
    break;
case 200: a = 3;
    break;
default: a = 4;
break;

}
if (a == 4){
    break;
}
if (operation[current_state][a] == Pop){
    //res[j] = 0;
    if (j!=0){
    n--;
    }
    else{
        return n;
    }
}
else {
    if (operation[current_state][a] == Continue){


    }
    else {
        if(operation[current_state][a] == Repeat){
                i--;
        }
        else{
            if(operation[current_state][a] == Break){
                printf("Result: ");
                return n;
                }
            else {
            res[j] = a;
            j++;
            n++;
           // printf("%d ", n);
            }
        }
    }
}
current_state = state[current_state][a];
}
}
