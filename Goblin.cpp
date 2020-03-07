//Nathan Peereboom
//March 6, 2020
//Learn how to learn assignment. Take the role of the wizard and defeat the pesky goblins.

#include "stdafx.h"
#include "Goblin.h"

void Goblin::set_name(std::string goblin_name)
{
	name = goblin_name;
}

std::string Goblin::get_name()
{
	return name;
}

void Goblin::set_health(int goblin_health)
{
	health = goblin_health;
}

int Goblin::get_health()
{
	return health;
}

void Goblin::damaged(int amount)
{
	health = health - amount;
	std::cout << name << " took " << amount << " damage.\n";
	if (health <= 0)
	{
		std::cout << name << " has been defeated.\n";
		alive = false;
	}
}

bool Goblin::is_alive()
{
	return alive;
}

void Goblin::attack(int action)
{
	stole_mana = false;
	if (charged_flurry)
	{
		attack_damage = 15;
		std::cout << name << " uses flurry attack. 15 damage dealt.\n";
		charged_flurry = false;
		
	}
	else
	{
		if (action <= 2)
		{
			attack_damage = 5;
			std::cout << name << " uses stab. 5 damage dealt.\n";
			
		}
		else if (action == 3)
		{
			attack_damage = 5;
			std::cout << name << " uses mana sap. 5 damage dealt and 5 mana stolen.\n";
			stole_mana = true;
		}
		else
		{
			attack_damage = 0;
			charged_flurry = true;
			std::cout << name << " prepares flurry attack and will be ready next turn.\n";
			
		}
	}
}

int Goblin::damage_dealt()
{
	return attack_damage;
}

bool Goblin::did_steal_mana()
{
	return stole_mana;
}