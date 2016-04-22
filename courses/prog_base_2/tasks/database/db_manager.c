#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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





int db_insertProgrammer(db_t * self, programmer_t * programmer)
{
   int newStudentId = -1;
   sqlite3_stmt * stmt = NULL;
   int rc = 0;
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Programmers  (Name, Surname, Language, Rating, Data, Year) VALUES (?,?,?, ?, ?, ?);", -1, &stmt, NULL)) {
        printf("Not prepared!\n");
    }
    sqlite3_bind_text(stmt, 1,programmer->name,strlen(programmer->name),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2,programmer->surname,strlen(programmer->surname),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3,programmer->language,strlen(programmer->language),SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt,4,programmer->rating);
    sqlite3_bind_text(stmt, 5,programmer->data,strlen(programmer->data),SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,6,programmer->year);

    if (SQLITE_DONE != (rc = sqlite3_step(stmt))) {
        printf("Not inserted! %i\n", rc);
    }
     newStudentId = (int) sqlite3_last_insert_rowid (self->db);
     sqlite3_finalize(stmt);
    return newStudentId;
}

programmer_t * db_getProgrammerById(db_t * self, int id)
{
    programmer_t * programmer = malloc(sizeof(programmer_t*));
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT * FROM Programmers WHERE Id = ?;", -1, &stmt, 0);
    sqlite3_bind_int(stmt, 1, id);
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
            return programmer;
}
        else
        {
            _fillProgrammers(stmt,programmer);
        }
    }
    sqlite3_finalize(stmt);
}



void db_updateProgrammer(db_t * self, programmer_t * programmer, int id)
{
    sqlite3_stmt * stmt = NULL;
   int rc = 0;
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"UPDATE Programmers SET Name = ?,Surname = ?,Language = ?, Rating = ?, Data = ?, Year = ? WHERE Id = ?;", -1, &stmt, NULL)) {
        printf("Not prepared!\n");
    }
    sqlite3_bind_text(stmt, 1,programmer->name,strlen(programmer->name),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2,programmer->surname,strlen(programmer->surname),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3,programmer->language,strlen(programmer->language),SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt,4,programmer->rating);
    sqlite3_bind_text(stmt, 5,programmer->data,strlen(programmer->data),SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,6,programmer->year);
    sqlite3_bind_int(stmt,7,id);

     if (SQLITE_DONE != (rc = sqlite3_step(stmt))) {
        printf("Not updated! %i\n", rc);
    }
     sqlite3_finalize(stmt);
}

void db_deleteProgrammer(db_t * self, int id)
{
    sqlite3_stmt * stmt = NULL;
    if(SQLITE_OK != sqlite3_prepare_v2(self->db, "DELETE FROM Programmers WHERE Id = ?;", -1, &stmt, 0)){
        printf("Not prepared!\n");
    }
    sqlite3_bind_int(stmt, 1, id);
    int rc = sqlite3_step(stmt);
    if (SQLITE_DONE != rc) {
        printf("Not deleted! %i\n", rc);
    }
    sqlite3_finalize(stmt);
}

int db_countProgrammers(db_t * self)
{
    int rc;
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT COUNT(*) FROM Programmers;", -1, &stmt, 0);
    rc = sqlite3_step(stmt);
    if (SQLITE_ERROR == rc)
    {
        printf("can't select count\n");
        exit(1);
    }
    int count = sqlite3_column_int(stmt,0);
    sqlite3_finalize(stmt);
    return count;
}






static void _fillProgrammers(sqlite3_stmt * stmt, programmer_t * st)
{
    int id = sqlite3_column_int(stmt, 0);
    const unsigned char * name = sqlite3_column_text(stmt, 1);
    const unsigned char * surname = sqlite3_column_text(stmt, 2);
    const unsigned char * language = sqlite3_column_text(stmt, 3);
    double rating = sqlite3_column_double(stmt, 4);
    const unsigned char * data = sqlite3_column_text(stmt, 5);
    int year = sqlite3_column_int(stmt, 6);
    st->id = id;
    strcpy(st->name, (const char *)name);
    strcpy(st->surname, (const char *)surname);
    strcpy(st->data, (const char *)data);
    strcpy(st->language, (const char *)language);
    st->rating = rating;
    st->year = year;
}

int db_getProgrammersTask(db_t * self, int K, char * P, programmer_t * arr, int arrMax)
{
    sqlite3_stmt * stmt = NULL;
    const char * sqlQuery = "SELECT * FROM Programmers WHERE Year > ? AND Language = ?;";
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
    sqlite3_bind_int(stmt, 1, K);
    sqlite3_bind_text(stmt, 2,P,strlen(P),SQLITE_STATIC);
    int count = 0;
    while (1)
    {
        int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc)
        {
            printf("can't select students\n");

            exit(1);
        }
        else if (SQLITE_DONE == rc)
        {

            break;
        }
        else
        {
            _fillProgrammers(stmt,&arr[count]);
            count++;
        }
    }

    sqlite3_finalize(stmt);
    return count;
}


