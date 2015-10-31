#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(void){
    srand(time(NULL));
    int N,j,i;
    int min;
    printf("Enter the number ");
    scanf("%i", &N);
    int arr[N];
    for (i=0;i<N;i++){
        arr[i]=rand()%1999-1000;
    }
    for (i=0;i<N;i++){
        printf("%i ", arr[i]);
    }
     printf("\n");
     printf("Index: ");
    for (i=0;i<N;i++){
        if (arr[i]<0){
          printf("%i ", i);
           };
    }
    min=arr[0];
    for (i=0;i<N;i++){
        if (arr[i]<min){
            min=arr[i];
        }
    }
    printf("\n");
    printf("Min=%i ", min);
}
