#pragma once

#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H
#include "AdvancedCharacter.h"; 
#include <string>; 

//Playable character inherits from Advanced Character
class PlayableCharacter : public AdvancedCharacter {
public:
	PlayableCharacter(); 
	PlayableCharacter(std::string _name, int _attack, int _defence, int _health, int _special, int _money); 
	int getMoney(); 
	void setMoney(int &_money); 
	bool getSpecial(); 
	void setSpecial(bool _special); 
	int getMaxHealth();
	void setMaxHealth(int _health);
	void displayStats(); 
private:
	int money; 
	bool specialUsed; 
	int maxHealth; 
};

#endif