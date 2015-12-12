#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Project {
int index;
int amount;
int month;
char info[20];
int i;


};

struct Programmer {
char name[10];
struct Project * p;
};


void filldef_1(struct Project * pVar){
    pVar->index = rand() % 3 + 1;
    pVar->amount = rand() % 50+1;
    pVar->month = rand() % 100;
    strcpy(pVar->info, "Something interesting here");
    pVar->i = 1;//rand()%2;// if KPI student


}

void filldef_2(struct Programmer * pVar){
    strcpy(pVar->name, "Something interesting here");
    pVar->p->i =rand()%2;// if KPI student


}

void print_1(struct Project * pVar){
if ((pVar -> i) == 1 && (pVar->month) > 3 ){
printf("\n");
printf(" Index:%d\n Workers:%d\n Month:%d\n Info:%s\n If KPI student:%i" , pVar->index, pVar->amount, pVar->month, pVar->info , pVar->i );
printf("\n");
}
}


void print_2(struct Programmer * pVar){
printf("Name :%s\n Student KPI: %i" , pVar->name, pVar->p->i );
}

void filldef_1_us(struct Project * pVar){
    char s[20];
    printf("Enter index:");
    scanf("%d", &pVar->index) ;
    printf("\n");
printf("Enter amount of workers: ");
 scanf("%d", &pVar->amount) ;
 printf("\n");
 printf("Enter time in month: ");
 scanf("%d", &pVar->month) ;
 printf("\n");
 printf("Please enter info: ");
scanf("%s",pVar->info);

 printf("\n");
printf("Please enter if KPI student(0 - False or 1 - True): ");
   scanf("%d",&pVar->i) ;

}

struct Project *  d_mem_1 (void){
struct Project * pt;
pt = (struct Project *)malloc(sizeof(struct Project));
return pt;
};

struct Project *  d_free_1 (struct Project * pVar){
free(pVar);
};

struct Programmer *  d_mem_2 (void){
struct Programmer * tp;
tp = (struct Programmer *)malloc(sizeof(struct Programmer));
return tp;
};

struct Programmer *  d_free_2 (struct Project * pVar){
free(pVar);
};



int main(void)
{
    srand(time(NULL));;
    struct Project newProject_1;
    struct Project newProject_2;
    struct Project newProject_3;
    struct Programmer P_1;
    struct Programmer P_2;
    struct Programmer P_3;
    P_1.p -> i;
    P_2.p -> i;
    P_3.p -> i;
    filldef_1(&newProject_1);
    filldef_1(&newProject_2);
    filldef_1(&newProject_3);
   // filldef_2(&P_1);
   // filldef_2(&P_2);
    //filldef_2(&P_3);
    print_1(&newProject_1);
    print_1(&newProject_2);
     print_1(&newProject_3);
     //print_2(&P_1);
     //print_2(&P_2);
     //print_2(&P_3);

       printf("\n");
      filldef_1_us(&newProject_1);
      printf("\n");
      filldef_1_us(&newProject_2);
      printf("\n");
      filldef_1_us(&newProject_3);
      d_mem_1();
      d_mem_2();

      d_free_1(&newProject_1);
      d_free_1(&newProject_2);
      d_free_1(&newProject_3);
      d_free_2(&P_1);
      d_free_2(&P_2);
      d_free_2(&P_3);

    return 0;
}





