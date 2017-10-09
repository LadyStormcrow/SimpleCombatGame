#pragma once

#ifndef ADVANCEDCHARACTER_H
#define ADVANCEDCHARACTER_H


#include "Character.h"; 
#include <string>; 

//class is for Boss Monsters 
class AdvancedCharacter : public Character {
public:
	AdvancedCharacter(); 
	AdvancedCharacter(std::string _name, int _attack, int _defence, int _health, int _special); 
	void setSpecial(int &_special); 
	int getSpecial(); 
protected:
	int special;
};

#endif // !ADVANCEDCHARACTER_H