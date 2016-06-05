#ifndef DB_MANAGER_H_INCLUDED
#define DB_MANAGER_H_INCLUDED
#include "sqlite3.h"
typedef struct db_s db_t;

db_t * db_new(const char * dbFile);
void db_free(db_t * self);


char * db_getProgrammers(db_t * self);
#endif // DB_MANAGER_H_INCLUDED


