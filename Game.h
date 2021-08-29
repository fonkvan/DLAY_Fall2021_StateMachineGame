#pragma once

class Node;
class CombatNode;
class GameOverNode;

class Game
{
	private:
		Node* currentNode;
		Node* startNode;
		CombatNode* Combat;
		GameOverNode* GameOver;
	public:
		Game();
		~Game();
		void PlayGame();
		void SampleGame();
};

