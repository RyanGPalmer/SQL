#include "SQLiteDB.h"
#include "sqlite3.h"
#include "PlayerData.h"

// Tries to open a database with the name assigned to DB_NAME
bool SQLiteDB::Open()
{
	if (isOpen)
		return true;
	isOpen = (sqlite3_open(DB_NAME, &db) == SQLITE_OK);
	Log((isOpen) ? "Connection successful." : "Failed to initialize.");
	return isOpen;
}

// Closes the database if open
void SQLiteDB::Close()
{
	if (isOpen)
	{
		sqlite3_close(db);
		isOpen = false;
		Log("Closed successfully.");
	}
	else
	Log("Already closed.");
}

// Executes an SQL query and returns the results as a vector of maps
vector<map<string, string>> SQLiteDB::Query(const char *query)
{
	vector<map<string, string>> result;
	if (isOpen)
		Log((sqlite3_exec(db, query, QueryCallback, &result, 0) == SQLITE_OK) ? "Query complete." : "Query failed.");
	else
		Log("Tried to query invalid database.");
	return result;
}

// Invoked by sqlite3_exec when a query has produced results (First param here is passed the fourth from sqlite3_exec)
int SQLiteDB::QueryCallback(void *data, int count, char **flds, char **cols)
{
	auto current = static_cast<vector<map<string, string>> *>(data);
	map<string, string> record;
	for (int i = 0; i < count; i++)
	{
		string col = cols[i], fld = flds[i] ? flds[i] : "NULL";
		record[col] = fld;
	}
	current->push_back(record);
	return 0;
}

// Prints current SQL status along with a custom message (If verbose is false, only prints errors)
void SQLiteDB::Log(string msg)
{
	char *err = (char *)sqlite3_errmsg(db);
	int code = sqlite3_errcode(db);
	if (code && isOpen)
		printf("[SQLITE] %s (Error (%d): %s)\n", msg.c_str(), code, err);
	else if (verbose)
		printf("[SQLITE] %s\n", msg.c_str());
}

// Returns a string containing the current status and error code of the database
string SQLiteDB::GetErrorCode()
{
	return to_string(sqlite3_errcode(db));
}