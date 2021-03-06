// 312840Wizard_V_Goblin.cpp : Defines the entry point for the console application.
//Nathan Peereboom
//March 6, 2020
//Learn how to learn assignment. Take the role of the wizard and defeat the pesky goblins.

#include "stdafx.h"
#include <iostream>
#include "Player.h"
#include "Goblin.h"
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

Player player;
std::vector<Goblin> goblin(3);
bool game_over;
bool player_wins;

void player_turn()
{
	player.charge_mana(5);
	player.protection(1);
	std::cout << "------------------------------------------------------------\nYou have " << player.get_health() << " health.\n";
	std::cout << "You have " << player.get_mana() << " mana.\n";
	for (int i = 0; i < 3; i++)
	{
		if (goblin[i].is_alive())
		{
			std::cout << goblin[i].get_name() << " has " << goblin[i].get_health() << " health.\n";
		}
		else
		{
			std::cout << goblin[i].get_name() << " is out of the battle.\n";
		}
	}
	std::cout << "------------------------------------------------------------\n\n";
	int spell;
	int spell_power = 0;
	int splash_damage = 0;
	bool successful_cast = false;
	bool offensive_spell;

	while (!successful_cast)
	{
		spell = player.select_spell();
		switch (spell)
		{
		case 0:
			spell_power = 5;
			successful_cast = true;
			offensive_spell = true;
			break;
		case 1:
			if (player.get_mana() >= 10)
			{
				spell_power = 10;
				player.use_mana(10);
				successful_cast = true;
				offensive_spell = true;
			}
			else
			{
				std::cout << "You don't have enough mana to perform that spell.\n";
			}
			break;
		case 2:
			if (player.get_mana() >= 10)
			{
				spell_power = 6;
				splash_damage = 3;
				player.use_mana(10);
				successful_cast = true;
				offensive_spell = true;
			}
			else
			{
				std::cout << "You don't have enough mana to perform that spell.\n";
			}
			break;
		case 3:
				player.protection(2);
				std::cout << "Applied protection.\n";
				offensive_spell = false;
				successful_cast = true;
				break;
		default:
			std::cout << "I don't think that's a spell.\n";
			break;
		}
	}
	
	int target;
	bool successful_hit = false;

	if (offensive_spell)
	{
		while (!successful_hit)
		{
			target = player.select_target();
			if (target >= 0 && target <= 2)
			{
				if (goblin[target].is_alive())
				{
					std::cout << "\n------------------------------------------------------------\n";
					for (int i = 0; i < goblin.size(); i++)
					{
						if (i == target)
						{
							goblin[i].damaged(spell_power);
						}
						else if (splash_damage > 0 && goblin[i].is_alive())
						{
							goblin[i].damaged(splash_damage);
						}
					}
					successful_hit = true;
					std::cout << "------------------------------------------------------------\n\n";
				}
				else
				{
					std::cout << "What are you doing? " << goblin[target].get_name() << " is already dead.\n";
				}
			}
			else
			{
				std::cout << "Where are you aiming? There's no goblin there.\n";
			}
		}
	}
	if (!goblin[0].is_alive() && !goblin[1].is_alive() && !goblin[2].is_alive())
	{
		game_over = true;
		player_wins = true;
	}
}

void goblin_turn()
{
	std::cout << "------------------------------------------------------------\n";
	srand(time(NULL));
	for (int i = 0; i < goblin.size(); i++)
	{
		if (goblin[i].is_alive())
		{
			int goblin_action = rand() % 5;
			goblin[i].attack(goblin_action);
			player.damaged(goblin[i].damage_dealt());
			if (goblin[i].did_steal_mana()) player.use_mana(5);
		}
	}
	if (!player.is_alive())
	{
		game_over = true;
		player_wins = false;
	}
	std::cout << "------------------------------------------------------------\n\n";
}

int main()
{
	
	game_over = false;
	
	player.set_health(100);
	player.set_mana(25);

	for (int i = 0; i < 3; i++) goblin[i].set_health(25);
	goblin[0].set_name("Red");
	goblin[1].set_name("Blue");
	goblin[2].set_name("Yellow");
	while (!game_over)
	{
		player_turn();
		goblin_turn();
	}
	if (player_wins)
	{
		std::cout << "------------------------------------------------------------\nCongratulations on your outstanding victory!\n------------------------------------------------------------\n";
	}
	else
	{
		std::cout << "------------------------------------------------------------\nGame over. Better luck next time.\n------------------------------------------------------------\n";
	}

	std::string end;
	std::cin >> end;
	std::cout << end;

    return 0;
}