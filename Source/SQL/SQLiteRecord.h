#pragma once
#include "CoreMinimal.h"

class SQL_API SQLiteRecord
{
	const long long ID;
	TArray<class SQLiteField*> fields;

public:
	SQLiteRecord() : SQLiteRecord(-1) {}
	SQLiteRecord(long long RowID) : ID(RowID) {}
	~SQLiteRecord() {}

	long long GetID() { return ID; }
};
