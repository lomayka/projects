#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int run(int moves[], int movesLen, int res[], int resLen);
enum operations {push, pop , repeat ,break , Continue , nothing};//
struct Move {
enum operations left;
int right;

};
int run(int moves[], int movesLen, int res[], int resLen){
    currentState=0;
    struct Move auto[3][3];
    auto[0][0].left = 11;
    auto[0][0].right = 1;
    auto[0][1].left = 55;
    auto[0][1].right = 2;
    auto[0][2].left = 101;
    auto[0][2].right = 3;
    auto[0][3].left = Continue;
    auto[0][3].right = 0;
    auto[1][0].left = nothing;
    auto[1][0].right = /* */;
    auto[1][1].left = pop;
    auto[1][1].right = 1;
    auto[1][2].left = 1;
    auto[1][2].right = 2;
    auto[1][3].left = nothing;
    auto[1][3].right = /* */;
    auto[2][0].left = pop;
    auto[2][0].right = 0;
    auto[2][1].left = 5;
    auto[2][1].right = 3;
    auto[2][2].left = repeat;
    auto[2][2].right = 1
    auto[2][2].left = 11;
    auto[2][2].right = 2;
    auto[3][0].left = nothing ;
    auto[3][0].right = /* */;
    auto[3][1].left = nothing ;
    auto[3][1].right = /* */;
    auto[3][2].left = break ;
    auto[3][2].right = /* */;
    auto[3][3].left = 2 ;
    auto[3][3].right = 1;



}



int main(void){


}
