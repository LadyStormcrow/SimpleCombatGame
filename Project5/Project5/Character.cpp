#include "Character.h"; 
#include <string>; 

Character::Character() {
	name = ""; 
	attack = 0; 
	defence = 0; 
	health = 0; 
}

Character::Character(std::string _name, int _attack, int _defence, int _health) {
	name = _name; 
	attack = _attack; 
	defence = _defence; 
	health = _health; 
}

int Character::getAttack() {
	return attack;
}

int Character::getDefence() {
	return defence;
}

int Character::getHealth() {
	return health; 
}

std::string Character::getName() {
	return name; 
}

void Character::setAttack(int &_attack){
	attack = _attack; 
}

void Character::setDefence(int &_defence) {
	defence = _defence; 
}

void Character::setHealth(int &_health) {
	health = _health; 
}

