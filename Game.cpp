#include "Game.h"
#include <iostream>
#include "Node.h"
#include "CombatNode.h"
#include "GameOverNode.h"

Game::Game()
{
	startNode = Node();
	currentNode = &startNode;
	MakeCamp = Node();
	ContinueOn = Node();
	WaitNode = Node();
	Sneak = Node();
	FightGoblins = CombatNode();
	GoblinCamp = GameOverNode();
	RunAway = GameOverNode();
	//Combat = CombatNode();
	//GameOver = GameOverNode();
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

//DebugGame is to Test Nodes to make sure game works properly.
//void Game::DebugGame()
//{
//	Node TestCNode = Node();
//	TestCNode.InitializeN("Test C Node", "", "", "", nullptr, nullptr);
//	GameOver.InitializeG("This is the Game Over Node");
//	Combat.InitializeC("This node is the Combat Node", "Fight", "Game Over Node", "Start Over", "TestCNode", 10, 10, 5, 5,
//	&Combat, &GameOver, &startNode, &TestCNode);
//	startNode.InitializeN("This node is the base test node", "Fight Node", "Game Over Node", "TestCNode", &Combat, &GameOver, &TestCNode);
//	currentNode = &startNode;
//	return;
//}
//actual game made for class
void Game::MainQuest()
{
	startNode.InitializeN("You are on your way to a nearby kingdom to deliver an important message to their king.\n"
							"The sun has begun to fall. What will you do?\n", 
							"Stop and make camp.", "Continue on. This is important", "",
							&MakeCamp, &ContinueOn);
	currentNode = &startNode;
	MakeCamp.InitializeN("\nYou have stopped to make camp. You lay down your cot, and setup a camp fire.\n"
							"You close your eyes, and begin to drift off...\n...\nHOURS LATER\n\n"
							"You wake up just as dawn is beginning to break, and you hear shuffling. Someone is approaching.\n"
							"You hide in the brush and see them. Goblins, but only a few. You may be able to take them...\n",
							"Wait for them to leave.", "Ambush and fight them.", "RUN AWAY!",
							&WaitNode, &FightGoblins, &RunAway);
	ContinueOn.InitializeN("\nYou've decided to continue on. Nothing is more important this message being delivered.\n"
							"As you're walking through the dark, you start to see a light. You approach it to find a very large camp.\n"
							"Goblins. And alot of them. Too many for one person to fight. You don't have many options here...\n",
							"Sneak around them.", "Fight anyways. You're no coward.", "RUN AWAY",
							&Sneak, &GoblinCamp, &RunAway);
	RunAway.InitializeG("\nYou begin sprinting away from the goblins, without any regard for how much noise you're making.\n"
							"Unfortunately for you, the goblins heard you. Heck, they may have even smelled you.\n"
							"They shout their warcry as loud as they can, and begin to string their bows.\n"
							"You try your best to avoid the arrows but it was no use. More arrows than necessary flew into your back.\n"
							"You have died.\n"
							"Game over.");
}