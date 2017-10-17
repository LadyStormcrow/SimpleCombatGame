#pragma once

#ifndef GAME_H
#define GAME_H 

#include "PlayableCharacter.h"
#include "Character.h"

class Game {
public:
	Game(PlayableCharacter &_player); 
	void battle(Character &_monster, bool _playerSpecial); 
	int diceRoll();
	bool battleEnd; 
	void displayPlayerStats(); 
private:
	int diceValue; 
	int attack; 
	int defence; 
	PlayableCharacter player; 
	void playerBattleWin();
	void monsterBattleWin(Character &_monster);
	void playerAttack(Character &_monster, bool _special); 
	void monsterAttack(Character &_monster); 

};

#endif
