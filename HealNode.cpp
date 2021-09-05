#include "HealNode.h"
#include <iostream>


/*
NOTE: THIS CLASS IS NEVER USED. Was meant to be able to get HP amount AFTER battle from a combat node, and heal based on that
but it could only get the default values
*/

HealNode::HealNode()
{
	playerHP = 0;
	HealAmount = 0;
	WhereToGetHP = CombatNode();
}

void HealNode::InitializeH(std::string ThisNodeDescription, std::string ADescription, std::string BDescription, std::string CDescription,
	Node* ANode, Node* BNode, CombatNode* WhereToGetHP, int HealAmount, Node* CNode)
{
	HealNode::ThisNodeDescription = ThisNodeDescription;
	HealNode::ADescription = ADescription;
	HealNode::BDescription = BDescription;
	HealNode::CDescription = CDescription;
	HealNode::ANode = ANode;
	HealNode::BNode = BNode;
	HealNode::CNode = CNode;
	HealNode::playerHP = WhereToGetHP->GetPlayerHP();
	HealNode::HealAmount = HealAmount;
}

Node* HealNode::process()
{
	playerHP += HealAmount;
	std::cout << playerHP << std::endl;
	return Node::process();
}

int HealNode::GetPlayerHP()
{
	return playerHP;
}