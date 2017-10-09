#include <string>
#include <iostream>
#include "PlayableCharacter.h"
#include "Character.h"
#include "AdvancedCharacter.h"

int main() {
	std::string playerName; 
	
	std::cout << "What's your name? "; 
	std::cin >> playerName; 

	PlayableCharacter(playerName, 3, 3, 20, 2, 0); 

	Character("MonsterOne", 1, 1, 10); 
	Character("MonsterTwo", 3, 2, 20); 
	Character("MonsterThree", 5, 4, 30); 
	Character("MonsterFour", 6, 7, 40);
	AdvancedCharacter("Boss", 8, 8, 50, 5); 

	return 0; 
}