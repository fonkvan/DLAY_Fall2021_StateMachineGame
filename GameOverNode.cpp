#include "GameOverNode.h"
#include <iostream>

GameOverNode::GameOverNode(){}

Node* GameOverNode::process()
{
	std::cout << ThisNodeDescription << std::endl;
	Node::bIsGameOver = true;
	return this;
}

void GameOverNode::InitializeG(std::string ThisNodeDescription)
{
	GameOverNode::ThisNodeDescription = ThisNodeDescription;
	GameOverNode::ADescription = "";
	GameOverNode::BDescription = "";
	GameOverNode::CDescription = "";
	GameOverNode::ANode = nullptr;
	GameOverNode::BNode = nullptr;
	GameOverNode::CNode = nullptr;
	Node::bIsGameOver = false;
}