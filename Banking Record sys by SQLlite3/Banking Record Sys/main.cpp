#include <stdio.h>
#include <iostream>
#include "sqlite3.h"

using namespace std;

int callback(void *NotUsed, int argc, char **argv,
char **azColName);

int main()
{
   //printf("%s\n", sqlite3_libversion());
   cout<<sqlite3_libversion();
/***********************************************************/

/*********************************************
 sqlite3 *db;
 sqlite3_stmt *res;

 int rc = sqlite3_open("ttest.db", &db);

 if (rc != SQLITE_OK) {
   fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
   ///sqlite3_errmsg(db) -- to print the type or reason of error
   sqlite3_close(db);
  return 1;
}

   rc = sqlite3_prepare_v2(db, "SELECT SQLITE_VERSION()", -1, &res, 0);
if (rc != SQLITE_OK) {
fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
sqlite3_close(db);
return 1;
}
rc = sqlite3_step(res);
if (rc == SQLITE_ROW) {
printf("%s\n", sqlite3_column_text(res, 0));
}
sqlite3_finalize(res);
sqlite3_close(db);
*****************************************************/
//Global
sqlite3 *db;
sqlite3_stmt *res;
char *err_msg = 0;

int create_db(char *name_db)
{   //static sqlite3 *db;
    int rc = sqlite3_open(named, &db);
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


char *err_msg = 0;
int rc = sqlite3_open("test.db", &db);
if (rc != SQLITE_OK) {
fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
sqlite3_close(db);
return 1;
}
char *sql = "DROP TABLE IF EXISTS Cars;"
"CREATE TABLE Cars(Id INT, Name TEXT, Price INT);"
"INSERT INTO Cars VALUES(1, 'Audi', 52642);"
"INSERT INTO Cars VALUES(2, 'Mercedes', 57127);"
"INSERT INTO Cars VALUES(3, 'Skoda', 9000);"
"INSERT INTO Cars VALUES(4, 'Volvo', 29000);"
"INSERT INTO Cars VALUES(5, 'Bentley', 350000);"
"INSERT INTO Cars VALUES(6, 'Citroen', 21000);"
"INSERT INTO Cars VALUES(7, 'Hummer', 41400);"
"INSERT INTO Cars VALUES(8, 'Volkswagen', 21600);";

rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
if (rc != SQLITE_OK ) {
fprintf(stderr, "SQL error: %s\n", err_msg);
sqlite3_free(err_msg);
sqlite3_close(db);
return 1;
}

char *sqlX = "DROP TABLE IF EXISTS CarsX;"
"CREATE TABLE CarsX(Id INT, Name TEXT, Price INT);"
"INSERT INTO CarsX VALUES(1, 'Audi', 52642);"
"INSERT INTO CarsX VALUES(2, 'Mercedes', 57127);"
"INSERT INTO CarsX VALUES(3, 'Skoda', 9000);"
"INSERT INTO CarsX VALUES(4, 'Volvo', 29000);"
"INSERT INTO CarsX VALUES(5, 'Bentley', 350000);"
"INSERT INTO CarsX VALUES(6, 'Citroen', 21000);"
"INSERT INTO CarsX VALUES(7, 'Hummer', 41400);"
"INSERT INTO CarsX VALUES(8, 'Volkswagen', 21600);";

rc = sqlite3_exec(db, sqlX, 0, 0, &err_msg);
if (rc != SQLITE_OK ) {
fprintf(stderr, "SQL error: %s\n", err_msg);
sqlite3_free(err_msg);
sqlite3_close(db);
return 1;
}
 /// INSERT DATA AGAIN
      sqlX = "INSERT INTO CarsX VALUES(1, 'Audi', 52642);"
             "INSERT INTO CarsX VALUES(2, 'Mercedes', 57127);";

rc = sqlite3_exec(db, sqlX, 0, 0, &err_msg);

if (rc != SQLITE_OK ) {
fprintf(stderr, "SQL error: %s\n", err_msg);
sqlite3_free(err_msg);
sqlite3_close(db);
return 1;
}

int last_id = sqlite3_last_insert_rowid(db);
cout<<endl<<last_id;
 sql = "SELECT * FROM Cars";
 rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
cout<<sql;
sqlite3_close(db);

return 0;

}

int callback(void *NotUsed, int argc, char **argv,
char **azColName) {
NotUsed = 0;
for (int i = 0; i < argc; i++) {
printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
}
printf("\n");
return 0;
}
