#pragma once
#include "CoreMinimal.h"

class SQL_API SQLiteDB
{
	const char *DB_NAME = "data.db";

	struct sqlite3 *DB;
	bool isOpen = false;
	TArray<class SQLiteRecord*> ResultSet;

public:
	SQLiteDB() {}
	~SQLiteDB() { Close(); }

	bool Open();
	void Close();
	void Query(const char*, void*);

private:
	static int QueryCallback(void*, int, char**, char**);

	void Log(FString);
};
