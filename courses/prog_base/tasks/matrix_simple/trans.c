/*#include <time.h>
#include <stdio.h>
#include <stdlib.h>
void fillRand (int mat[4][4]);
void rotateCW90(int mat[4][4]);
void flipV(int mat[4][4]);
void transposMain(int mat[4][4]);
void printmatrix(int mat[4][4]);
int main(){
    int mat[4][4],n,m;
    srand(time(NULL));

    fillRand(mat);
    printmatrix(mat);

    rotateCW90(mat);
    printmatrix(mat);

    flipV(mat);
    printmatrix(mat);

    transposMain(mat);
     printmatrix(mat);


    return 0;
}
void printmatrix(int mat[4][4]){
    int m,n;
                 for (n=0;n<4;n++)
    {
    for (m=0;m<4;m++){
           printf("%i\t",mat[n][m]);
            }
        printf("\n");
    }
    printf("\n");

}*/
void fillRand (int mat[4][4]){
    int a,b;
    for (a=0;a<4;a++)
        {
        for (b=0;b<4;b++)
            {
                mat[a][b]=rand()%1999-999;
            }
        }
}
void rotateCW90(int mat[4][4]){
    int mat1[4][4];
    int d,f;
        for (d=0;d<4;d++){
        for (f=0;f<4;f++){

            mat1[d][f]=mat[d][f];
            }
    }
    int a,b,c;
    for (a=0;a<4;a++){
        for (b=0;b<4;b++){
                c=3-b;
            mat[a][b]=mat1[c][a];
        }
    }
}
void flipV(int mat[4][4]){
    int mat1[4][4];
    int mat2[4][4];
     int a,b,c,d,f,i,g,h,k;
     for (i=0;i<3;i++){
        for (d=0;d<4;d++){
        for (f=0;f<4;f++){

            mat1[d][f]=mat[d][f];
            }
    }
    for (a=0;a<4;a++){
        for (b=0;b<4;b++){
                c=3-b;
            mat2[a][b]=mat1[c][a];
        }
    }
}
for (a=0;a<4;a++){
        for (b=0;b<4;b++){
            c=3-b;
           mat[a][b]=mat2[a][c];

        }
}
}
void transposMain(int mat[4][4]){
    int mat1[4][4];
    int a,b,i,j;
 for (a=0;a<4;a++){
        for (b=0;b<4;b++){
           mat1[a][b]=mat[a][b];

        }
}
for (i=0;i<4;i++){
    for (j=0;j<4;j++){
        mat[i][j]=mat1[j][i];
    }
}
}











