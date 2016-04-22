#include <stdio.h>
#include <stdlib.h>
#include "db_manager.h"
#include "programmers.h"

int main()
{
    const char * dbFile = "programmers.db";
    programmer_t programmerList[100];
    db_t * db = db_new(dbFile);

    int count = db_getProgrammersTask(db,2013,"C#",programmerList,100);
    printf("Filtrated: %d\n",count);
    programmer_print(&programmerList[count-1]);
    db_insertProgrammer(db,&programmerList[count-1]);
    db_updateProgrammer(db,&programmerList[count-1],2);
    db_deleteProgrammer(db,2);
    int countAllProgrammers = db_countProgrammers(db);
    printf("Programmers total: %i\n\n", countAllProgrammers);
    programmer_t * programmer = db_getProgrammerById(db,3);
    programmer_print(programmer);



    getch();
    db_free(db);


    return 0;
}
