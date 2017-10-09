#include "PlayableCharacter.h"; 
#include <iostream>
#include <string>

PlayableCharacter::PlayableCharacter() {
	name = "";
	attack = 0;
	defence = 0;
	health = 0;
	special = 0;
	money = 0;
	specialUsed = false; 
	maxHealth = 20;
}

PlayableCharacter::PlayableCharacter(std::string _name, int _attack, int _defence, int _health, int _special, int _money) {
	name = _name;
	attack = _attack; 
	defence = _defence; 
	health = _health; 
	special = _special; 
	money = _money; 
	specialUsed = false;
	maxHealth = 20; 
}

int PlayableCharacter::getMoney() {
	return money;
}

void PlayableCharacter::setMoney(int &_money) {
	money = _money; 
}

void PlayableCharacter::setSpecial(bool _special) {
	specialUsed = _special; 
}

bool PlayableCharacter::getSpecial() {
	return specialUsed; 
}

int PlayableCharacter::getMaxHealth() {
	return maxHealth; 
}

void PlayableCharacter::setMaxHealth(int _health) {
	maxHealth = _health; 
}

void PlayableCharacter::displayStats() {
	std::cout << "Health: " << health << "/" << maxHealth << "\tAttack: " << attack << "\tDefence: " << defence << "\tSpecial: " << special << std::endl; 
}