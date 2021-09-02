#pragma once

#include "Node.h"
#include "CombatNode.h"
#include "GameOverNode.h"

class Game
{
	private:
		Node* currentNode;
		Node MakeCamp;
		Node ContinueOn;
		Node WaitNode;
		Node Sneak;
		CombatNode FightGoblins;
		GameOverNode GoblinCamp;
		GameOverNode RunAway;
		//CombatNode Combat;
		//GameOverNode GameOver;
	public:
		Game();
		void PlayGame();
		//void DebugGame();
		void MainQuest();
		Node startNode;
};

