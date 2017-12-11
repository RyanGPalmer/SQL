#include "PlayerData.h"

PlayerData::PlayerData(const string ID, map<string, string> Profile) :
    ID(stoi(ID)),
    Name(Profile["name"]),
    Race((PlayerRace)stoi(Profile["race"])),
    Class((PlayerClass)stoi(Profile["class"]))
{
    Level = stoi(Profile["level"]);
    Experience = stoi(Profile["experience"]);
    Health = stoi(Profile["health"]);
    Money = stoi(Profile["money"]);
}

void PlayerData::Print()
{
    printf("ID = %lld\nName = %s\nRace = %s\nClass = %s\nLevel = %d\nExperience = %d\nHealth = %d\nMoney = %d\n", ID, Name.c_str(), GetRace().c_str(), GetClass().c_str(), Level, Experience, Health, Money);
}

string PlayerData::GetRace()
{
    return PlayerRaceText[(int)Race];
}

string PlayerData::GetClass()
{
    return PlayerClassText[(int)Class];
}