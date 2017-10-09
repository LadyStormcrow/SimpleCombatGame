#include "AdvancedCharacter.h"; 
#include <string>; 

AdvancedCharacter::AdvancedCharacter() {
	name = ""; 
	attack = 0;
	defence = 0;
	health = 0;
	special = 0;
}

AdvancedCharacter::AdvancedCharacter(std::string _name, int _attack, int _defence, int _health, int _special) {
	name = _name; 
	attack = _attack; 
	defence = _defence; 
	health = _health; 
	special = _special; 
}

int AdvancedCharacter::getSpecial() {
	return special; 
}

void AdvancedCharacter::setSpecial(int &_special) {
	special = _special; 
}

