#include "PlayableCharacter.h"; 
#include <string>

PlayableCharacter::PlayableCharacter() {
	name = "";
	attack = 0;
	defence = 0;
	health = 0;
	special = 0;
	money = 0;
}

PlayableCharacter::PlayableCharacter(std::string _name, int _attack, int _defence, int _health, int _special, int _money) {
	name = _name;
	attack = _attack; 
	defence = _defence; 
	health = _health; 
	special = _special; 
	money = _money; 
}

int PlayableCharacter::getMoney() {
	return money;
}

void PlayableCharacter::setMoney(int &_money) {
	money = _money; 
}