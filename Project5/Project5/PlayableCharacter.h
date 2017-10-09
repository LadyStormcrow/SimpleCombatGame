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
private:
	int money; 
};

#endif