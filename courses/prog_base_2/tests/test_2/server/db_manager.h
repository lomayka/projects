#ifndef DB_MANAGER_H_INCLUDED
#define DB_MANAGER_H_INCLUDED

#include "programmers.h"
#include "sqlite3.h"
#include "list.h"
typedef struct db_s db_t;

db_t * db_new(const char * dbFile);
void db_free(db_t * self);


void db_getProgrammers(db_t * self,list_t * list);
static void _fillProgrammers(sqlite3_stmt * stmt, programmer_t * st);
#endif // DB_MANAGER_H_INCLUDED

