#include <math.h>
#include <stdio.h>
#include <stdlib.h>

enum operations {Pop=-5, Push, Repeat, Continue, Break };
int run(int moves[], int movesLen, int res[], int resLen);
int main(void){
int  movesLen, resLen, i, result;
int moves[] = {2,10,20,10,200,20,2};
movesLen = sizeof(moves)/sizeof(int);
resLen = sizeof(moves)/sizeof(int);
int res[resLen];
for ( i = 0; i < movesLen; i++){
    printf("%d ", moves[i]);
}

result = run(moves, movesLen, res, resLen);
printf("\n");
for (i = 0; i < movesLen; i++){
    printf("%d ", res[i]);
}
printf("\n");
printf("Result: ");
printf("%d ", result);
return 0;
}
int run(int moves[], int movesLen, int res[], int resLen){
int i, a, j = 0, n = 0, current_state = 0;
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
                return n;
                }
            else {
            res[j-1] = operation[current_state][a];
            j++;
            n++;
            }
        }
    }
}
current_state = state[current_state][a];
}
}
