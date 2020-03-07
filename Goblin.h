//Nathan Peereboom
//March 6, 2020
//Learn how to learn assignment. Take the role of the wizard and defeat the pesky goblins.

#pragma once
#include <iostream>
#include <string>

class Goblin
{
	std::string name;
	int health;
	int attack_damage;
	bool alive = true;
	bool charged_flurry;
	bool stole_mana;
public:
	void set_name(std::string goblin_name);
	std::string get_name();
	void set_health(int goblin_health);
	int get_health();
	void damaged(int amount);
	bool is_alive();
	void attack(int action);
	int damage_dealt();
	bool did_steal_mana();
};

