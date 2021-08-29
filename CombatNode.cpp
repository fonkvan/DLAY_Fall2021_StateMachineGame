#include "CombatNode.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

CombatNode::CombatNode()
{
	CombatNode::playerDMGRange = 5;
	CombatNode::playerHP = 10;
	CombatNode::eDMGRange = 5;
	CombatNode::eHP = 5;
	CombatNode::ThisNodeDescription = "";
	CombatNode::ADescription = "";
	CombatNode::BDescription = "";
	CombatNode::CDescription = "";
	CombatNode::ANode = nullptr;
	CombatNode::BNode = nullptr;
	CombatNode::CNode = nullptr;
}

CombatNode::CombatNode(std::string ThisNodeDescription, std::string ADescription, std::string BDescription, std::string CDescription,
	int playerHP, int eHP, int playerDMGRange, int eDMGRange, Node* ANode, Node* BNode, Node* CNode)
{
	CombatNode::ThisNodeDescription = ThisNodeDescription;
	CombatNode::ADescription = ADescription;
	CombatNode::BDescription = BDescription;
	CombatNode::CDescription = CDescription;
	CombatNode::playerHP = playerHP;
	CombatNode::eHP = eHP;
	CombatNode::playerDMGRange = playerDMGRange;
	CombatNode::eDMGRange = eDMGRange;
	CombatNode::ANode = ANode;
	CombatNode::BNode = BNode;
	CombatNode::CNode = CNode;
}

Node* CombatNode::process()
{
	Node* NextNode = Node::process();
	//needs to check if next node was chosen as a specific node, but that it is also this node
	//needs to check specific node because NextNode == this could return true if the user inputs an invalid input
	if ((NextNode == ANode && ANode == this) || (NextNode == BNode && BNode == this) || (NextNode == CNode && CNode == this))
	{
		CombatCalculation();
	}
	return NextNode;
}

void CombatNode::CombatCalculation()
{
	std::srand(std::time(NULL));
	playerHP = playerHP - (std::rand() % eDMGRange);
	std::cout << "You lost %i HP!" << playerHP << std::endl;
	eHP = eHP - (std::rand() % playerDMGRange);
	std::cout << "You dealt %i damage to the enemy!" << std::endl;
	if (playerHP <= 0)
	{
		std::cout << "You lose!" << std::endl;
		return;
	}
	if (eHP <= 0)
	{
		std::cout << "You win!" << std::endl;
		return;
	}
}