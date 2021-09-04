#pragma once

#include "Node.h"
#include "CombatNode.h"
#include "GameOverNode.h"
#include "LinearNode.h"

class Game
{
	private:
		CombatNode FightGoblins;
		GameOverNode GoblinCamp;
		GameOverNode RunAway;
		GameOverNode Flee;
		GameOverNode FightGuard;
		LinearNode WaitNode;
		Node* currentNode;
		Node MakeCamp;
		Node ContinueOn;
		Node Sneak;
		Node ExitForest;
		Node River;
		Node RiverSkip;
		Node CastleNight;
		Node Tavern;
		Node Reason;
		//CombatNode Combat;
		//GameOverNode GameOver;
	public:
		Game();
		void PlayGame();
		//void DebugGame();
		void MainQuest();
		Node startNode;
};

