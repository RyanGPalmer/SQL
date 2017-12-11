#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

class SQLiteDB
{
	const char *DB_NAME = "data.db";

	struct sqlite3 *db;
	bool isOpen = false;
	bool verbose = true;

public:
	SQLiteDB() { Open(); }
	~SQLiteDB() { Close(); }

	vector<map<string, string>> Query(const char*);
	void SetVerbose(bool b) { verbose = b; };
	string GetErrorCode();

private:
	bool Open();
	void Close();
	static int QueryCallback(void*, int, char**, char**);
	void Log(string);
};
