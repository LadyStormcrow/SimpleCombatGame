#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H


#include <string>

//Character class is for basic monsters in game
class Character {
public:
	Character(); 
	Character(std::string _name, int _attack, int _defence, int _health); 
	std::string getName();
	int getAttack();
	int getDefence();
	int getHealth();
	void setAttack(int &_attack);
	void setDefence(int &_defence);
	void setHealth(int &_health);
protected:
	std::string name;
	int attack;
	int defence;
	int health;
};

#endif // !CHARACTER_H