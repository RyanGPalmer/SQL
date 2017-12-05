// Fill out your copyright notice in the Description page of Project Settings.

#include "SQLGameInstance.h"
#include "SQLiteDB.h"

USQLGameInstance::USQLGameInstance() : UGameInstance()
{
	DB = new SQLiteDB();
}

void USQLGameInstance::OnStart()
{
	UE_LOG(LogTemp, Warning, TEXT("Starting..."));
	DB->Open();
	DB->Close();
}