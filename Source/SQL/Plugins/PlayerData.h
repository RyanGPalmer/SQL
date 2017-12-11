#pragma once
#include <string>
#include <map>

using namespace std;

enum class PlayerRace
{
	INVALID = -1,
	Human,
	Elf,
	Orc,
	Reptilian,
	Worgen,
	MAX
};

static const string PlayerRaceText[] =
{
	"Human",
	"Elf",
	"Orc",
	"Reptilian",
	"Worgen"
};

enum class PlayerClass
{
	INVALID = -1,
	Warrior,
	Hunter,
	Rogue,
	Sorcerer,
	Monk,
	MAX
};

static const string PlayerClassText[] =
{
	"Warrior",
	"Hunter",
	"Rogue",
	"Sorcerer",
	"Monk"
};

struct PlayerData
{
	const long long ID;
	const string Name;
	const PlayerRace Race;
	const PlayerClass Class;
	int Level = 1;
	int Experience = 0;
	int Health = 0;
	int Money = 0;

	PlayerData() : PlayerData("NULL", map<string, string>()) {}
	PlayerData(const string, map<string, string>);

	void Print();
	string GetRace();
	string GetClass();
};
