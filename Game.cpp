#include "Game.h"
#include <iostream>
#include "Node.h"
#include "CombatNode.h"
#include "GameOverNode.h"

Game::Game()
{
	startNode = Node();
	currentNode = &startNode;
	Combat = CombatNode();
	GameOver = GameOverNode();
}

//Game::~Game(){}

void Game::PlayGame()
{
	while (!currentNode->getGameOver() && currentNode != nullptr)
	{
		currentNode = currentNode->process();
	}
	return;
}

void Game::SampleGame()
{
	Node TestCNode = Node();
	TestCNode.InitializeN("Test C Node", "", "", "", nullptr, nullptr);
	GameOver.InitializeG("This is the Game Over Node");
	Combat.InitializeC("This node is the Combat Node", "Fight", "Game Over Node", "Start Over", "TestCNode", 10, 10, 5, 5,
	&Combat, &GameOver, &startNode, &TestCNode);
	startNode.InitializeN("This node is the base test node", "Fight Node", "Game Over Node", "TestCNode", &Combat, &GameOver, &TestCNode);
	currentNode = &startNode;
	return;
}