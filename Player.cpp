//Nathan Peereboom
//March 6, 2020
//Learn how to learn assignment. Take the role of the wizard and defeat the pesky goblins.

#include "stdafx.h"
#include "Player.h"
#include "Goblin.h"

void Player::set_health(int player_health)
{
	health = player_health;
}

int Player::get_health()
{
	return health;
}

void Player::set_mana(int player_mana)
{
	mana = player_mana;
}

int Player::get_mana()
{
	return mana;
}

void Player::charge_mana(int amount)
{
	if (mana > 25 - amount)
	{
		std::cout << "Charged " << 25 - mana << " mana.\n\n";
		mana = 25;
	}
	else
	{
		mana += amount;
		std::cout << "Charged " << amount << " mana.\n\n";
	}
}

void Player::use_mana(int amount)
{
	if (mana - amount < 0)
	{
		mana = 0;
	}
	else
	{
		mana -= amount;
	}
}

int Player::select_spell()
{
	std::cout << "Enter the number of the spell you wish to use:\n"
		<< "Flash (0): Deals 5 damage to a single target. Costs no mana.\n"
		<< "Fireball (1): Deals 10 damage to a single target. Costs 10 mana.\n"
		<< "Lightning (2): Deals 6 damage to a selected target and 3 damage to all other targets. Costs 10 mana.\n"
		<< "Protection (3): Blocks 50% of incoming damage. Lasts 1 turn. Costs no mana.\n";
	std::string spell;
	std::cin >> spell;
	int ispell;
	try {
		return std::stoi(spell);
	}
	catch (...) 
	{
		return -1;
	}
}

int Player::select_target()
{
	std::cout << "Select a goblin to attack:\n"
		<< "Red (0)\n"
		<< "Blue (1)\n"
		<< "Yellow (2)\n";
	int target;
	std::cin >> target;
	return target;
}

void Player::damaged(int amount)
{
	health = health - (amount / shield);
	if (shield > 1 && amount > 0)
	{
		std::cout << "Your protection took effect. Only " << (amount / shield) << " damage taken.\n";
	}
	if (health <= 0)
	{
		alive = false;
	}
}

bool Player::is_alive()
{
	return alive;
}

void Player::protection(int divisor)
{
	shield = divisor;
}