#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sqlite3.h"
#include "db_manager.h"
#include "programmer.h"


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







char * db_getProgrammers(db_t * self)
{
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT * FROM Programmers;", -1, &stmt, 0);
    char * str = malloc(sizeof(char)*10000);
    str[0] = '\0';
    strcat(str,"[");
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
        else if (SQLITE_ROW == rc)
        {
            programmer_t * programmer = programmer_new();
            fillProgrammer(stmt,programmer);
            strcat(str,programmer_toJSON(programmer));
            strcat(str,",\n");
        }
    }
    strcat(str,"]");
    sqlite3_finalize(stmt);
    return str;
}

char * db_getProgrammers_HTML(db_t * self)
{
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT * FROM Programmers;", -1, &stmt, 0);
    char * str = malloc(sizeof(char)*10000);
    str[0] = '\0';
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
        else if (SQLITE_ROW == rc)
        {
            programmer_t * programmer = programmer_new();
            fillProgrammer(stmt,programmer);
            char buff[1000];
            sprintf(buff,"<a href=\"http://127.0.0.1:5000/programmers/%d\">%s %s</a><br>",sqlite3_column_int(stmt,0),sqlite3_column_text(stmt,1),sqlite3_column_text(stmt,2));
            strcat(str,buff);
        }
    }
    sqlite3_finalize(stmt);
    return str;
}

char * db_getProgrammerById(db_t * self, int id)
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
            return "{ \"Status\": \"Error\" ";
        }
        else if (SQLITE_DONE == rc)
        {
            return programmer_toJSON(programmer);
}
        else
        {
            fillProgrammer(stmt,programmer);
        }
    }
    sqlite3_finalize(stmt);
}

char * db_getProgrammerById_HTML(db_t * self, int id)
{
    programmer_t * programmer = malloc(sizeof(programmer_t*));
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, "SELECT * FROM Programmers WHERE Id = ?;", -1, &stmt, 0);
    sqlite3_bind_int(stmt, 1, id);
    int index = 0;
     while (1)
    {
        int rc = sqlite3_step(stmt);
        if (SQLITE_ERROR == rc)
        {
            return "{ \"Status\": \"Error\" ";
        }
        else if (SQLITE_DONE == rc)
        {
            return programmer_toHTML(programmer,index);
}
        else
        {
            fillProgrammer(stmt,programmer);
            index = sqlite3_column_int(stmt,0);
        }
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

int db_insertProgrammer(db_t * self, programmer_t * programmer)
{
   int newStudentId = -1;
   sqlite3_stmt * stmt = NULL;
   int rc = 0;
    if(SQLITE_OK != sqlite3_prepare_v2(self->db,"INSERT INTO Programmers  (Name, Surname, Language, Rating, Data, Year,Company) VALUES (?,?,?, ?, ?,?,?);", -1, &stmt, NULL)) {
        printf("Not prepared!\n");
    }
    sqlite3_bind_text(stmt, 1,programmer_getName(programmer),strlen(programmer_getName(programmer)),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2,programmer_getSurname(programmer),strlen(programmer_getSurname(programmer)),SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3,programmer_getLanguage(programmer),strlen(programmer_getLanguage(programmer)),SQLITE_TRANSIENT);
    sqlite3_bind_double(stmt,4,programmer_getRating(programmer));
    sqlite3_bind_text(stmt, 5,programmer_getDate(programmer),strlen(programmer_getDate(programmer)),SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,6,programmer_getYear(programmer));
    sqlite3_bind_text(stmt, 7,programmer_getCompany(programmer),strlen(programmer_getCompany(programmer)),SQLITE_TRANSIENT);

    if (SQLITE_DONE != (rc = sqlite3_step(stmt))) {
        printf("Not inserted! %i\n", rc);
    }
     newStudentId = (int) sqlite3_last_insert_rowid (self->db);
     sqlite3_finalize(stmt);
    return newStudentId;
}

char * db_getProgrammersTask(db_t * self, int K, char * P,const char * sqlQuery)
{
    sqlite3_stmt * stmt = NULL;
    sqlite3_prepare_v2(self->db, sqlQuery, strlen(sqlQuery), &stmt, 0);
     //sqlite3_bind_text(stmt,1,">",1,SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 1, K);
    sqlite3_bind_text(stmt, 2,P,strlen(P),SQLITE_TRANSIENT);
    int index = 0;
    char * str = malloc(sizeof(char) * 1000);
    str[0] = '\0';
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

         return str;
        }
        else if (SQLITE_ROW == rc)
        {
           programmer_t * programmer = programmer_new();
           fillProgrammer(stmt,programmer);
           //index = sqlite3_column_int(stmt,0);
           char buff[1000];
           sprintf(buff,"<a href=\"http://127.0.0.1:5000/programmers/%d\">%s %s</a><br>",sqlite3_column_int(stmt,0),sqlite3_column_text(stmt,1),sqlite3_column_text(stmt,2));
           strcat(str,buff);
        }
    }


}

void fillProgrammer(sqlite3_stmt * stmt, programmer_t * programmer){
            const unsigned char * name = sqlite3_column_text(stmt, 1);
            const unsigned char * surname = sqlite3_column_text(stmt, 2);
            const unsigned char * language = sqlite3_column_text(stmt, 3);
            double rating = sqlite3_column_double(stmt, 4);
            const unsigned char * data = sqlite3_column_text(stmt, 5);
            int year = sqlite3_column_int(stmt, 6);
            const unsigned char * company = sqlite3_column_text(stmt, 7);
            programmer_set(programmer,name,surname,company,language,rating,year,data);

}

