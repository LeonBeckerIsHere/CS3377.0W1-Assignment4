//File: book1.cpp
//Name: Leon Becker
//Class: CS3377.0W1
//Professor: Dr. Richard Min

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

static int callback(void *NotUsed, int argc, char *argv[], char *azColName[]){
	for(int i = 0; i < argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : NULL);
	}
	printf("\n");
	return 0;
}

int main(int argc, char *argv[]){
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	const char *sql;
	
	//Create/open book.db to be given instructions by sqlite
	rc = sqlite3_open("book.db", &db);

	if(rc){
		fprintf(stderr, "Can't open database %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else{
		fprintf(stdout, "Opened datable successfully\n");
	}

	//Instructions for sql
	sql = "CREATE TABLE IF NOT EXISTS `classics` (" \
	"`author` varchar(128) DEFAULT NULL," \
	"`title` varchar(128) DEFAULT NULL," \
	"`category` varchar(16) DEFAULT NULL," \
	"`year` char(4) DEFAULT NULL," \
	"`isbn` char(13) NOT NULL DEFAULT ''," \
	"PRIMARY KEY (`isbn`));";

	//This will create a sql table in book.db
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if(rc != SQLITE_OK){
		fprintf(stderr, "SQL Error: %s\n", zErrMsg);
		sqlite3_free(&zErrMsg);
	}
	else{
		fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);
	return 0;


}
