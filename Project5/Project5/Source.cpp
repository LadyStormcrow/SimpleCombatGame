#include <string>
#include <iostream>
#include <time.h>
#include "PlayableCharacter.h"
#include "Character.h"
#include "AdvancedCharacter.h"
#include "Game.h"

int main() {
	std::string playerName; 
	bool battle = true; 
	bool special = false; 
	char special_ans = 'u'; 
	bool special_used = false; 
	bool boss_special = false; 
	bool boss_special_used = false; 
	int monsters = 0; 	

	std::cout << "Welcome to the Monster Battle Tournament!\n"; 
	std::cout << "What's your name? "; 
	std::cin >> playerName; 

	PlayableCharacter player(playerName, 3, 3, 20, 2, 0); 
	Game game(player); 

	Character monster[] = {Character("MonsterOne", 1, 1, 10), Character("MonsterTwo", 3, 2, 20), Character("MonsterThree", 5, 4, 30), Character("MonsterFour", 6, 7, 40)};

	AdvancedCharacter boss("Boss", 8, 8, 50, 5); 

	

	while (monsters < 4) {
		game.battleEnd = false;
		system("CLS"); 
		while (!game.battleEnd) {
			game.displayPlayerStats(); 
			std::cout << "Monster Health: " << monster[monsters].getHealth() << std::endl;
			if (!special_used) {
				std::cout << "Do you want to use your special ability? (y)es or (n)o ";
				std::cin >> special_ans;
				while (special_ans != 'y' && special_ans != 'n') {
					std::cout << "\nPlease select y for yes or n for no.\n";
					std::cin >> special_ans;
				}
				if (special_ans == 'y') {
					std::cout << "You choose to use your attack!\n"; 
					special = true;
					special_used = true; 
				}
			}
			game.battle(monster[monsters], special);
			special = false; 

			if (game.battleEnd) {
				monsters++; 
				special_used = false; 
				system("pause");
			}
		}
	}

	if (monsters == 4 && !game.gameEnd) {
		while (!game.battleEnd) {
			game.displayPlayerStats();
			std::cout << "Monster Health: " << boss.getHealth() << std::endl;
			if (!special_used) {
				std::cout << "Do you want to use your special ability? (y)es or (n)o ";
				std::cin >> special_ans;
				while (special_ans != 'y' && special_ans != 'n') {
					std::cout << "\nPlease select y for yes or n for no.\n";
					std::cin >> special_ans;
				}
				if (special_ans == 'y') {
					std::cout << "You choose to use your attack!\n";
					special = true;
					special_used = true;
				}
			}

			if (!boss_special_used) {
				srand(time(NULL));
				int r = rand() / (1) + 1; 
				if (r == 1) { 
					boss_special = true; 
					boss_special_used = true; 
				}
			}

			game.battleBoss(boss, special, boss_special); 
			special = false;
			boss_special = false; 

			if (game.battleEnd) {
				monsters++;
				special_used = false;
				boss_special_used = false; 
			}
		}
	}
	

	system("pause"); 

	return 0; 
}