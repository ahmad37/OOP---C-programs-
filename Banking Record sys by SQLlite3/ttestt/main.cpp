#include <iostream>
#include "sqlite3.h"
using namespace std;

int create_db(sqlite3 *name_db)
{   //static sqlite3 *db;
    int rc = sqlite3_open(name_db, &name_db);
    return rc;
}
void create_table(char * statement, sqlite3 *db_name)
{
   int rc = sqlite3_exec(db_name, statement, 0, 0, &err_msg);

  if (rc != SQLITE_OK ) {
   fprintf(stderr, "SQL error: %s\n", err_msg);
   sqlite3_free(err_msg);
   sqlite3_close(db);
                 }
}
void insert_row(char *statement, sqlite3 *db_name)
 {
  rc = sqlite3_exec(db_name, statement, 0, 0, &err_msg);
 if (rc != SQLITE_OK ) {
  fprintf(stderr, "SQL error: %s\n", err_msg);
  sqlite3_free(err_msg);
  sqlite3_close(db);
 }

int main()
{
    sqlite3 *db;
sqlite3_stmt *res;
char *err_msg = 0;



    return 0;
}
