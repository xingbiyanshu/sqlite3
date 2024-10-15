#include <iostream>
#include "sqlite3.h"

using namespace std;


static int query_callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i = 0;
    for(i = 0; i < argc; i++)
    {
        printf("%s = %s\n",azColName[i], argv[i]?argv[i]:"NULL");
    }

    printf("\n");
    return 0;
}


int main()
{
    cout << "Hello World!" << endl;

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);
    if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      return(1);
    }

    // 建表
    char *sql = "create table company(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE TEXT NOT NULL, ADDRESS CHAR(50))";
    rc = sqlite3_exec(db, sql, nullptr, 0, &zErrMsg);
    if( rc!=SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    }

    // 增加记录
    sql = "insert into company(ID, NAME, AGE, ADDRESS) values(1, 'Paul', 25, 'USA');\
        insert into company(ID, NAME, AGE, ADDRESS) values(2, 'James', 28, 'JAP');\
        insert into company(ID, NAME, AGE, ADDRESS) values(3, 'Yao', 30, 'CHA');\
        insert into company(ID, NAME, AGE, ADDRESS) values(4, 'kobe', 38, 'USA');";
    rc = sqlite3_exec(db, sql, nullptr, 0, &zErrMsg);
    if( rc!=SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    // 查询
    sql = "select * from  company;";
    rc = sqlite3_exec(db, sql, query_callback, 0, &zErrMsg);
    if( rc!=SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);

    cout << "finish!" << endl;
    return 0;
}
