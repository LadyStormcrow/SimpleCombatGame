#include <string>
#include <iostream>
#include "PlayableCharacter.h"
#include "Character.h"
#include "AdvancedCharacter.h"
#include "Game.h"

int main() {
	std::string playerName; 
	bool battle = true; 
	
	std::cout << "What's your name? "; 
	std::cin >> playerName; 

	PlayableCharacter player(playerName, 3, 3, 20, 2, 0); 
	Game game(player); 
	

	Character monsterOne("MonsterOne", 1, 1, 10); 
	Character monsterTwo("MonsterTwo", 3, 2, 20); 
	Character monsterThree("MonsterThree", 5, 4, 30); 
	Character monsterFour("MonsterFour", 6, 7, 40);
	AdvancedCharacter boss("Boss", 8, 8, 50, 5); 

	while (!game.battleEnd) {
		player.displayStats(); 
		std::cout << "Monster Health: " << monsterOne.getHealth() << std::endl; 
		game.battle(monsterOne, false); 
	}

	system("pause"); 

	return 0; 
}