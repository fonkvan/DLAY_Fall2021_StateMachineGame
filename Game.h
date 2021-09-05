#pragma once

#include "Node.h"
#include "CombatNode.h"
#include "GameOverNode.h"
#include "HealNode.h"
#include "LinearNode.h"

class Game
{
	private:
		CombatNode FightGoblins;
		GameOverNode GoblinCamp;
		GameOverNode RunAway;
		GameOverNode Flee;
		GameOverNode CowardEnding;
		GameOverNode Dehydrate;
		GameOverNode FightGuard;
		GameOverNode ValiantEnding;
		LinearNode LateKing;
		LinearNode RiverSkip;
		LinearNode LateTavern;
		LinearNode WaitNode;
		Node* currentNode;
		Node MakeCamp;
		Node ContinueOn;
		Node Sneak;
		Node ExitForest;
		Node CastleNight;
		Node Reason;
		Node Surrender;
		Node River;
		//CombatNode Combat;
		//GameOverNode GameOver;
	public:
		Game();
		void PlayGame();
		//void DebugGame();
		void MainQuest();
		Node startNode;
};

