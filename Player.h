//Nathan Peereboom
//March 6, 2020
//Learn how to learn assignment. Take the role of the wizard and defeat the pesky goblins.

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Goblin.h"

class Player
{
	int health;
	int mana;
	bool alive = true;
	int shield;
public:
	void set_health(int player_health);
	int get_health();
	void set_mana(int player_mana);
	int get_mana();
	void charge_mana(int amount);
	void use_mana(int amount);
	int select_spell();
	int select_target();
	void damaged(int amount);
	bool is_alive();
	void protection(int divisor);
};

