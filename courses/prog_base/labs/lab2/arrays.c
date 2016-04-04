#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fillRand1(int arr[], int size);
int checkRand1(int arr[], int size);
int maxValue(int arr[], int size);
int meanIndex(int arr[], int size);
int maxIndex(int arr[], int size);
int maxOccurance(int arr[], int size);
int diff(int arr1[], int arr2[], int res[], int size);
void add(int arr1[], int arr2[], int res[], int size);
int eq(int arr1[], int arr2[], int size);
void lor(int arr1[], int arr2[], int res[], int size);



int main(void){
    int size = 10;
    int arr[size];
    int arr1[size];
    int arr2[size];
    int res[size];
    int i;
    srand(time(NULL));
    fillRand1(arr, size);
    printf("\n");
    printf("Check: %d", checkRand1(arr, size));
    printf("\n");
    printf("Max Value: %d", maxValue(arr, size));
    printf("\n");
    printf("Mean Index: %d", meanIndex(arr, size));
    printf("\n");
    printf("Max Index: %d", maxIndex(arr, size));
    printf("\n");
    printf("Max Occurance: %d", maxOccurance(arr, size));
    printf("\n");
    printf("Diff: %d", diff(arr1,arr2,res, size));
    printf("\n");
    add(arr1,arr2,res, size);
    printf("\n");
    printf("Equal: %d", eq(arr1,arr2, size));
    lor(arr1,arr2,res, size);

}

void fillRand1(int arr[], int size){
    int i;
    for (i = 0; i < size; i++ ){
        arr[i]=rand() % 99 + 1;
        printf("%d ", arr[i]);
    }

}
int checkRand1(int arr[], int size){
    int i,count = 0;
    int res = 0;
    for (i = 0; i < size; i++ ){
      if ((arr[i]>0) && (arr[i]<100)){
        count++;
      }
    }
    res = count/size;
    if (res==1){
        return 1;
    }
    else {
        return 0;
    }

}
int maxValue(int arr[], int size){
int i;
int max = arr[0];
for (i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
}
return max;
}
int meanIndex(int arr[], int size){
    int i, mean_index=0;
    double avr = 0,min_d = 0,a = 0;
    for (i = 0; i < size; i++){
      avr+=(double)arr[i]/size;
}
     printf("Average: %f", avr); //must be deleted
     printf("\n");// and this too
     min_d = abs(avr - arr[0]);
   for (i = 0; i < size; i++){
        a = abs(avr-arr[i]);
     if ( a < min_d){
        min_d = abs(avr-arr[i]);
        mean_index=i;
     }
}


return mean_index;

}
int maxIndex(int arr[], int size){
    int i = 0, max_index = 0, max = arr[0];
for (i = 0; i < size; i++){
        if (arr[i] > max){
            max = arr[i];
            max_index=i;
        }
}
return max_index;
}
int maxOccurance(int arr[], int size){
    int i = 0, j =0, counter = 0, max_counter = 0, max_index = 0;
    for (i = 0; i < size; i++){
            counter = 0;
       for (j = 0; j < size; j++){
            if (arr[i]==arr[j]){
                counter++;
            }

      }
      if (counter > max_counter){
                max_counter = counter;
                max_index = i;
            }
      if (counter == max_counter){
        if (arr[i] > arr[max_index]){
            max_index = i;
        }
      }
    }
    return arr[max_index];
}
int diff(int arr1[], int arr2[], int res[], int size){
    int i = 0, result = 0;
    for (i = 0; i < size; i++){
        arr1[i] = rand()%3;
        arr2[i] = rand()%3;
        res[i]=arr1[i]-arr2[i];
        result+=abs(res[i]);
    }

        if (result == 0){
            return 1;
        }
        else {
            return 0;
        }

}
void add(int arr1[], int arr2[], int res[], int size){
    int i = 0;
     printf("res: ");
    for (i = 0; i < size; i++){
        arr1[i] = rand()% 50;
        arr2[i] = rand()% 50;
        res[i]=arr1[i]+arr2[i];
        printf("%d ", res[i]);
    }
}
int eq(int arr1[], int arr2[], int size){
    int i = 0, counter = 0;
    for (i = 0; i < size; i++){
        arr1[i] = rand()%3;
        arr2[i] = rand()%3;
        if (arr1[i]==arr2[i]){
            counter++;
        }
    }
    if (counter/size==1){
        return 1;
    }
    else {
        return 0;
    }

}
void lor(int arr1[], int arr2[], int res[], int size){
    printf("\n");
    printf("logical OR:\n");
    int i = 0;
    for (i = 0; i < size; i++){
        arr1[i] = rand()%2;
        arr2[i] = rand()%2;
    res[i] = arr1[i] || arr2[i];

    printf("%d", arr1[i]);
    printf("v%d", arr2[i]);
    printf("=%d ", res[i]);
    printf("\n");
}

}
