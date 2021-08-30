#include "Game.h"
#include <iostream>
#include "Node.h"
#include "CombatNode.h"
#include "GameOverNode.h"

Game::Game()
{
	startNode = nullptr;
	currentNode = startNode;
	Combat = nullptr;
	GameOver = nullptr;
}

Game::~Game(){}

void Game::PlayGame()
{
	if (currentNode == nullptr)
	{
		GameOver = new GameOverNode("nullptr exception thrown. ending game.");
		GameOver->process();
	}
	if (currentNode != nullptr)
	{
		while (!currentNode->getGameOver())
		{
			currentNode = currentNode->process();
		}
	}
	return;
}

void Game::SampleGame()
{
	Node* TestCNode = new Node("Test C Node", "", "", "", nullptr, nullptr);
	GameOver = new GameOverNode("This is the Game Over Node");
	Combat = new CombatNode("This node is the Combat Node", "Fight", "Game Over Node", "Start", 10, 10, 5, 5, Combat, GameOver, startNode);
	startNode = new Node("This node is the base test node", "Fight Node", "Empty Node", "", Combat, GameOver, TestCNode);
	currentNode = startNode;
	return;
}