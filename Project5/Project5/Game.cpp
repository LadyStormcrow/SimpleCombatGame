#include "Game.h"
#include <iostream>

Game::Game(PlayableCharacter &_player) {
	player = _player; 
	battleEnd = false;
}

void Game::battle(Character &_monster, bool _playerSpecial) {

	playerAttack(_monster, _playerSpecial); 
	if (_monster.getHealth() <= 0) {
		playerBattleWin(); 
	}

	monsterAttack(_monster); 
	if (player.getHealth() <= 0) {
		monsterBattleWin(_monster); 
	}
}

int Game::diceRoll() {
	//seed rand
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
		int health = _monster.getHealth() - (attack - defence);
		_monster.setHealth(health);
	}

}

void Game::monsterAttack(Character &_monster) {
	attack = diceRoll() + _monster.getAttack();
	defence = diceRoll() + player.getDefence();

	if (attack > defence) {
		int health = player.getHealth() - (attack - defence);
		player.setHealth(health);
	}
}

void Game::playerBattleWin() {
	std::cout << "You win!\n"; 
	battleEnd = true;
}

void Game::monsterBattleWin(Character &_monster) {
	std::cout << "You lose.\n"; 
	battleEnd = true;
}