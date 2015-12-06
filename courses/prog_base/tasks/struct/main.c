#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Factory {
int amount;
char name[20];
char best_worker[20];
};


int count(int size, struct Factory arr[size]){
    int cnt = 0;
    for (int i = 0; i < size; i++){
        if (((arr+i)->amount)/* or arr[i].amount*/ > 50){
            cnt++;
        }
    }
    return cnt;
}
void change(struct Factory * pVar, const char * newValue){
    strcpy(pVar->name, newValue);
}
void print(struct Factory * pVar){
    for (int i = 0; i < 4; i++){
    printf("Factory %d:\n Name: %s;\n Workers: %d;\n Worker of month: %s;\n",i,(pVar+i)->name,(pVar+i)->amount,(pVar+i)->best_worker);

     }

}

int main()
{
   srand(time(NULL));
   struct Factory arr[4] = {{rand()%100+1, "Dell", "Tom Johns"},{rand()%100+1,"Asus", "Peter Cooper"}, {rand()%100+1,"MSI", "Henry Parker"}, {rand()%100+1,"HP", "Steve MacGee"}};
    int N = 0;
    char * newValue = (char*)malloc(30*sizeof(char));
    print(arr);
    printf("\n");
    printf("More than 50 workers in %d factories; \n",count(4,arr));
    printf("\n");
    printf("Please, enter index of factory (0-3) and new name: ");
    scanf("%d %s",&N,newValue);
    change(&arr[N],newValue);
    printf("\n");
    printf("Renamed factory number %d:\n Name: %s;\n Workers: %d;\n Worker of month: %s;\n",N,(arr+N)->name,(arr+N)->amount,(arr+N)->best_worker);
    free(newValue);
    return 0;
}


