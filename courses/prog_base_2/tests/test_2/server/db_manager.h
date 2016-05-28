#ifndef DB_MANAGER_H_INCLUDED
#define DB_MANAGER_H_INCLUDED

#include "programmers.h"
#include "sqlite3.h"
typedef struct db_s db_t;

db_t * db_new(const char * dbFile);
void db_free(db_t * self);

int db_insertProgrammer(db_t * self, programmer_t * programmer);
programmer_t * db_getProgrammerById(db_t * self, int id);
void db_updateProgrammer(db_t * self, programmer_t * programmer, int id);
void db_deleteProgrammer(db_t * self, int id);

int db_countProgrammers(db_t * self);

int db_getProgrammersTask(db_t * self, int K, char * P, programmer_t * arr, int arrMax);
static void _fillProgrammers(sqlite3_stmt * stmt, programmer_t * st);
#endif // DB_MANAGER_H_INCLUDED

