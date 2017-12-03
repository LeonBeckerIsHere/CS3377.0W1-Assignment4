//File: book2.cpp
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

	//This program inserts 6 elements into the sql database "book.db"
	sqlite3 *db;
	char *zErrMsg;
	int rc;
	const char *sql;

	rc = sqlite3_open("book.db", &db);
	
	if(rc){
		fprintf(stderr, "Can't open database %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else{
		fprintf(stdout, "Opened database successfully\n");
	}

	sql = "INSERT INTO `classics` (`author`, `title`, `category`, `year`, `isbn`) VALUES" \
	"('Mark Twain', 'The Adventures of Tom Sawyer', 'Fiction', '1876', '9781598184891')," \
	"('Jane Austen', 'Pride and Prejudice', 'Fiction', '1811', '9780582506206')," \
	"('Charles Darwin', 'The Origin of Species', 'Non-Fiction', '1856', '9780517123201')," \
	"('Charles Dickens', 'The Old Curiosity Shop', 'Fiction', '1841', '9780099533474')," \
	"('William Shakespeare', 'Romeo and Juliet', 'Fiction', '1594', '9780192814968')," \
	"('Herman Melville', 'Moby Dick', 'Fiction', '1851', '9780199535729');";

	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

	if(rc != SQLITE_OK){
		fprintf(stderr, "SQL Error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else{
		fprintf(stdout, "Records created successfully\n");
	}
	sqlite3_close(db);
	return 0;

}
