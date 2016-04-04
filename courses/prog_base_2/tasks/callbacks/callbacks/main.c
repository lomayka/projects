#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Size 3


typedef void (*cb_two)(int  first_val, int second_val, int third_val);
typedef void (*cb_three)(int * count,int  first_val, int second_val, int third_val);

void bingo(cb_two twoCB,cb_three threeCB)
{
    int arr[Size];
    int * count = malloc(sizeof(int));
    *count = 0;
    while(!kbhit())
    {
        srand ( time(NULL) );
        for(int i = 0; i < Size; i++)
        {
            arr[i] = rand()  % 10;


        }
        if (arr[0] == arr[1] && arr[0] == arr[2] && threeCB != NULL)
        {
            threeCB(count,arr[0],arr[1],arr[2]);
            getch();
        }
        else if ((arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2]) && twoCB != NULL)
        {
            twoCB(arr[0],arr[1],arr[2]);


        }
    }
    free(count);
    getch(); // to fix kbhit
}

void print_cb_two (int  first_val, int second_val, int third_val)
{
    printf("First value: %d\n", first_val);
    printf("Second value: %d\n", second_val);
    printf("Third value: %d\n", third_val);

}

void equals_cb_two (int  first_val, int second_val, int third_val)
{
    if (first_val == second_val) printf("Equals are first and second values: %d\n", first_val);
    if (first_val == third_val) printf("Equals are first and third values: %d\n", first_val);
    if (second_val == third_val) printf("Equals are second and third values: %d\n", second_val);
}

void sum_cb_two(int  first_val, int second_val, int third_val)
{
    int sum = first_val + second_val + third_val;
    printf("Sum twoCB is: %d\n", sum );
}

void print_cb_three(int * count,int  first_val, int second_val, int third_val)
{
    printf("All values are equal!\n");
    printf("First value: %d\n", first_val);
    printf("Second value: %d\n", second_val);
    printf("Third value: %d\n", third_val);
    *count++;
}

void print_count_cb_three(int * count,int  first_val, int second_val, int third_val)
{
    *count++;
    printf("Count is: %d\n", *count);
}

void sum_cb_three(int * count,int  first_val, int second_val, int third_val)
{
    int sum = first_val + second_val + third_val;
    printf("Sum threeCB is: %d\n", sum );
    *count++;
}




int main()
{

    bingo(print_cb_two,print_cb_three);
    bingo(equals_cb_two,print_count_cb_three);
    bingo(sum_cb_two,sum_cb_three);

    return 15;
}
