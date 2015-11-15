#include <math.h>
#include <stdlib.h>
double calc (int n, int m);
int main(){
    int n,m;
    printf("Enter n and m: ");
    scanf("%d%d", &n, &m);
    printf("%f", calc(n,m));
}
double calc (int n, int m){
    int i,j;
    int n1=1;
    double x;
    for (i=1;i<=n;i++){
        for (j=1;j<=m;j++){
                x+=(double)(n1+1)/(i+j)+i*(j-n1);

        }
    }
    return x;
}




