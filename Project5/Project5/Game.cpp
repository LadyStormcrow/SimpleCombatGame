#include "Game.h"
#include <iostream>
#include <algorithm>
#include <time.h>

Game::Game(PlayableCharacter &_player) {
	player = _player; 
	battleEnd = false;
	gameEnd = false; 
}

void Game::battle(Character &_monster, bool _playerSpecial) {

	std::cout << "You prepare to attack...\n";
	playerAttack(_monster, _playerSpecial); 
	if (_monster.getHealth() <= 0) {
		playerBattleWin(); 
	}

	if (!battleEnd) {
		std::cout << "The Monster swipes at you...\n";
		monsterAttack(_monster);
		if (player.getHealth() <= 0) {
			monsterBattleWin();
		}
	}
	
}

void Game::battleBoss(AdvancedCharacter &_monster, bool _playerSpecial, bool _monsterSpecial) {

	std::cout << "You prepare to attack the Boss Monster...\n"; 
	playerAttack(_monster, _playerSpecial);
	if (_monster.getHealth() <= 0) {
		playerBossBattleWin();
	}

	if (!battleEnd) {
		std::cout << "The Boss Monster swipes at you...\n";
		bossAttack(_monster, _monsterSpecial);
		if (player.getHealth() <= 0) {
			monsterBattleWin();
		}
	}
	
}

int Game::diceRoll() {
	srand(time(NULL)); //seed rand
	return (rand() % 6 + 1); 
}

void Game::playerAttack(Character &_monster, bool _special) {

	if (_special) {
		attack = diceRoll() + player.getAttack() + player.getSpecial(); 
	}
	else {
		attack = diceRoll() + player.getAttack();
	}
	
	defence = diceRoll() + _monster.getDefence();

	if (attack > defence) {
		std::cout << "You strike the Monster!!\n\n"; 
		int health = _monster.getHealth() - (attack - defence);
		_monster.setHealth(health);
	}
	else {
		std::cout << "You miss the the Monster!\n\n"; 
	}

}

void Game::monsterAttack(Character &_monster) {
	attack = diceRoll() + _monster.getAttack();
	defence = diceRoll() + player.getDefence();

	if (attack > defence) {
		std::cout << "The Monster's attack hits!!\n\n";
		int health = player.getHealth() - (attack - defence);
		player.setHealth(health);
	}
	else {
		std::cout << "The Monster misses!\n\n"; 
	}
}

void Game::bossAttack(AdvancedCharacter &_monster, bool _special) {

	if (_special) {
		std::cout << "The Boss Monster uses his special!!\n";
		attack = diceRoll() + _monster.getAttack() + _monster.getSpecial(); 
	}
	else {
		attack = diceRoll() + _monster.getAttack(); 
	}
	
	defence = diceRoll() + player.getDefence();

	if (attack > defence) {
		std::cout << "The Boss Monster's attack hits!!\n\n";
		int health = player.getHealth() - (attack - defence);
		player.setHealth(health);
	}
	else {
		std::cout << "The Boss Monster misses!\n\n";
	}
}

void Game::playerBossBattleWin() {
	std::cout << "CONGRATULATIONS!! YOU'VE WON THE MONSTER BATTLE TOURNAMENT!!\nYOU WIN " << player.getMoney() << " IN PRIZE MONEY" << std::endl; 
	battleEnd = true; 
	gameEnd = true; 

}

void Game::playerBattleWin() {
	std::cout << "You win!\n\n"; 
	battleEnd = true;

	int healthReward = std::min(player.getHealth() + 20, 50); 
	int attackReward = std::min(player.getAttack() + rand() % 3, 10); 
	int defenceReward = std::min(player.getDefence() + rand() % 3, 10);
	int specialReward = std::min(player.getSpecial() + rand() % 3, 10);
	int moneyReward = player.getMoney() + player.getHealth(); 
	player.setAttack(attackReward); 
	player.setDefence(defenceReward); 
	player.setSpecial(specialReward); 
	player.setMoney(moneyReward); 
	player.setMaxHealth(healthReward); 
	player.setHealth(healthReward); 
}

void Game::monsterBattleWin() {
	std::cout << "You lose the tournament.\n\n"; 
	battleEnd = true;
	gameEnd = true; 
}

void Game::displayPlayerStats() {
	std::cout << "Health: " << player.getHealth() << "/" << player.getMaxHealth() << "\tAttack: " << player.getAttack() << "\tDefence: " << player.getDefence() << "\tSpecial: " << player.getSpecial() << std::endl;
}