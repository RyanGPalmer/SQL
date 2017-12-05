#include "SQLiteDB.h"
#include "Plugins/sqlite3.h"
#include "SQLiteRecord.h"

bool SQLiteDB::Open()
{
	if (isOpen)
	{
		Log("Database already open.");
		return true;
	}

	if (sqlite3_open(DB_NAME, &DB) != SQLITE_OK)
	{
		Log("Failed to open database.");
		return isOpen = false;
	}

	Log("Database connection successful.");
	return isOpen = true;
}

void SQLiteDB::Close()
{
	if (isOpen)
	{
		Log("Database closed.");
		sqlite3_close(DB);
		return;
	}

	Log("Database already closed.");
}

void SQLiteDB::Query(const char *Query, void *data)
{
	if (isOpen)
	{
		if (sqlite3_exec(DB, Query, QueryCallback, data, 0) != SQLITE_OK)
			Log("Database query failed.");
		else
			Log("Database query complete.");
	}
	else Log("Tried to query invalid database.");
}

int SQLiteDB::QueryCallback(void *data, int count, char **flds, char **cols)
{
	for (int i = 0; i < count; i++) {
		FString col = cols[i];
		FString fld = flds[i] ? flds[i] : "NULL";
		UE_LOG(LogTemp, Warning, TEXT("%s = %s"), *col, *fld);
	}

	return 0;
}

void SQLiteDB::Log(FString Msg)
{
	FString ErrStr = sqlite3_errmsg(DB);
	int code = sqlite3_errcode(DB);
	if (code)	UE_LOG(LogTemp, Error, TEXT("[SQLite3]\n%s\nSQLite Status (%d): %s"), *Msg, code, *ErrStr)
	else		UE_LOG(LogTemp, Warning, TEXT("[SQLite3]\n%s\nSQLite Status (%d): OK"), *Msg, code);
}