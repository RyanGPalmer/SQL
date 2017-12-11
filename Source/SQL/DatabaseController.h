#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DatabaseController.generated.h"

UCLASS(Blueprintable, BlueprintType)
class SQL_API UDatabaseController : public UObject
{
	GENERATED_BODY()

private:
	class SQLiteDB* DB;
	FString PlayerID;

	void Initialize();

public:
	UDatabaseController();

	UFUNCTION(BlueprintCallable)
	TArray<FString> GetPlayerList();

	UFUNCTION(BlueprintCallable)
	void SelectPlayer(const FString name);

	UFUNCTION(BlueprintCallable)
	void CreatePlayer(const FString name);

private:
	// Deprecated
	// struct PlayerData LoadPlayerData(const FString);
};
