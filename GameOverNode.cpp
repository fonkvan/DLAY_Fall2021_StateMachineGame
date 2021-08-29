#include "GameOverNode.h"
#include <iostream>

GameOverNode::GameOverNode()
{
	std::cout << "Game Over!" << std::endl;
}

GameOverNode::GameOverNode(std::string ThisNodeDescription)
{
	GameOverNode::ThisNodeDescription = ThisNodeDescription;
}

Node* GameOverNode::process()
{
	Node::bIsGameOver = true;
	return this;
}