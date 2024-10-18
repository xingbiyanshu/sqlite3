#include <iostream>
#include "sqlite3.h"
#include <thread>

using namespace std;

static auto ts = std::time(nullptr);

static int query_callback(void *NotUsed, int argc, char **argv, char **azColName)
{

    auto tid = std::this_thread::get_id();

    cout << "=========query_callback tid="<< tid<<endl;

    int i = 0;
    for(i = 0; i < argc; i++)
    {
        printf("%s = %s\n",azColName[i], argv[i]?argv[i]:"NULL");
    }

    printf("\n");

    cout << "===========callback cost= " << std::time(nullptr)-ts <<endl;
    return 0;
}


int main()
{
    cout << "Hello World!" << endl;

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;


    auto now = std::time(nullptr);
    cout << "now=" << now <<endl;

    rc = sqlite3_open("test.db", &db);
    if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      return(1);
    }
    cout << "open cost " << std::time(nullptr)-now <<endl;

    std::thread::id tid = std::this_thread::get_id();

    cout << "main tid="<< tid<<endl;

    printf("create table company(ID, NAME, AGE, ADDRESS)\n");


    now = std::time(nullptr);
    // 建表
    char *sql = "create table company(ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL, AGE TEXT NOT NULL, ADDRESS CHAR(50))";
    rc = sqlite3_exec(db, sql, nullptr, 0, &zErrMsg);
    if( rc!=SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
    }
    cout << "create table cost " << std::time(nullptr)-now <<endl;

    printf("insert into company\n");

    now = std::time(nullptr);
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
    cout << "insert table cost " << std::time(nullptr)-now <<endl;

    printf("select * from  company\n");

    // 查询
    sql = "select * from  company;";
    ts = std::time(nullptr);
    rc = sqlite3_exec(db, sql, query_callback, 0, &zErrMsg);
    if( rc!=SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    cout << "query table cost " << std::time(nullptr)-now <<endl;

    printf("delete then query\n");

    // 删除并查询
    sql = "delete from company where ID = 2;\
          select * from company;";
    rc = sqlite3_exec(db, sql, query_callback, 0, &zErrMsg);
    if( rc!=SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }

    sqlite3_close(db);

    cout << "finish!" << endl;
    return 0;
}
