#pragma once

#ifndef GAME_H
#define GAME_H 

#include "PlayableCharacter.h"
#include "Character.h"

class Game {
public:
	Game(PlayableCharacter &_player); 
	void battle(Character &_monster, bool _playerSpecial); 
	void battleBoss(AdvancedCharacter &_monster, bool _playerSpecial, bool _monsterSpecial); 
	int diceRoll();
	bool battleEnd; 
	void displayPlayerStats(); 
	bool gameEnd; 
private:
	int diceValue; 
	int attack; 
	int defence; 
	PlayableCharacter player; 
	void playerBattleWin();
	void monsterBattleWin();
	void playerBossBattleWin(); 
	void playerAttack(Character &_monster, bool _special); 
	void monsterAttack(Character &_monster); 
	void bossAttack(AdvancedCharacter &_monster, bool _special); 

};

#endif
