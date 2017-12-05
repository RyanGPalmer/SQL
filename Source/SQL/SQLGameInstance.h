// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SQLGameInstance.generated.h"

UCLASS()
class SQL_API USQLGameInstance : public UGameInstance
{
	GENERATED_BODY()

	class SQLiteDB *DB;
	
public:
	USQLGameInstance();

	virtual void OnStart() override;
};
