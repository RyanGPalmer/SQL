#include "DatabaseController.h"
#include "Plugins/PlayerData.h"
#include "Plugins/SQLiteDB.h"

UDatabaseController::UDatabaseController() : UObject()
{
	DB = new SQLiteDB();
	Initialize();
}

// Ensures all necessary tables are set up
void UDatabaseController::Initialize()
{
	DB->Query(
		"CREATE TABLE IF NOT EXISTS user ("
		"name		TEXT	NOT NULL DEFAULT 'Player' UNIQUE,"
		"level		INTEGER NOT NULL DEFAULT 1,"
		"experience INTEGER NOT NULL DEFAULT 0,"
		"health		INTEGER NOT NULL DEFAULT 0,"
		"money		INTEGER NOT NULL DEFAULT 0,"
		"race		INTEGER NOT NULL DEFAULT 0,"
		"class		INTEGER NOT NULL DEFAULT 0)"
	);
}

TArray<FString> UDatabaseController::GetPlayerList()
{
	TArray<FString> Profiles;

	auto profiles = DB->Query("SELECT name FROM user");
	for (auto profile : profiles)
	{
		Profiles.Add(profile["name"].c_str());
	}

	return Profiles;
}

void UDatabaseController::SelectPlayer(const FString name)
{
	string n = TCHAR_TO_UTF8(*name);
	string q = "SELECT * FROM user WHERE name IS '" + n + "'";
	auto profiles = DB->Query(q.c_str());

	if (!profiles.size())
		UE_LOG(LogTemp, Error, TEXT("PROFILE %s NOT FOUND!"), n.c_str());

	auto profile = profiles[0];
	q = "SELECT rowid FROM user WHERE name IS '" + n + "'";
	PlayerID = FString(DB->Query(q.c_str())[0]["rowid"].c_str());
}

void UDatabaseController::CreatePlayer(const FString)
{

}

// Deprecated
// PlayerData UDatabaseController::LoadPlayerData(const FString name)
// {
//	 string n = TCHAR_TO_UTF8(*name);
//	 string q = "SELECT * FROM user WHERE name IS '" + n + "'";
//	 auto profiles = DB->Query(q.c_str());
//
//	 if (!profiles.size())
//	 	return PlayerData();
//
//	 auto profile = profiles[0];
//	 q = "SELECT rowid FROM user WHERE name IS '" + n + "'";
//	 auto rowID = DB->Query(q.c_str())[0]["rowid"];
//
//	 return PlayerData(rowID, profile);
// }