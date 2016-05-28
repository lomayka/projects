#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "sqlite3.h"
#include "db_manager.h"
#include "programmers.h"

struct db_s
{
    sqlite3 * db;
};


db_t * db_new(const char * dbFile)
{
    db_t * self = malloc(sizeof(struct db_s));
    int rc = sqlite3_open(dbFile, & self->db);
    if (SQLITE_ERROR == rc)
    {
        printf("can't open database\n");
        exit(1);
    }
    return self;
}

void db_free(db_t * self)
{
    sqlite3_close(self->db);
}







void db_getProgrammers(db_t * self,list_t * list)
{
    programmer_t * programmer = malloc(sizeof(programmer_t*));
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT * FROM Programmers;", -1, &stmt, 0);
     while (1)
    {
        int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc)
        {
            printf("can't select students\n");
            exit(1);
        }
        else if (SQLITE_DONE == rc)
        {   sqlite3_finalize(stmt);
            break;
}
        else if (SQLITE_ROW == rc)
        {
            _fillProgrammers(stmt,programmer);
            list_add(list,programmer);
        }
    }
    sqlite3_finalize(stmt);
}



static void _fillProgrammers(sqlite3_stmt * stmt, programmer_t * st)
{
    const unsigned char * name = sqlite3_column_text(stmt, 1);
    const unsigned char * surname = sqlite3_column_text(stmt, 2);
    const unsigned char * language = sqlite3_column_text(stmt, 3);
    double rating = sqlite3_column_double(stmt, 4);
    const unsigned char * data = sqlite3_column_text(stmt, 5);
    int year = sqlite3_column_int(stmt, 6);
    programmer_setName(st,(const char *)name);
    programmer_setSurname(st,(const char *)surname);
    programmer_setLanguage(st,(const char *)language);
    programmer_setData(st,(const char *)data);
    programmer_setRating(st,rating);
    programmer_setYear(st,year);

}

