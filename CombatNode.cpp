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
	CombatNode::bPlayerKIA = false;
}

Node* CombatNode::process()
{
	if (bPlayerKIA)
	{
		ResetDefaults();
		return &PlayerDied;
	}
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
	std::srand((unsigned int)std::time(NULL));
	int DMGEInflicts = std::rand() % eDMGRange;
	playerHP = playerHP - DMGEInflicts;
	std::cout << std::endl;
	std::cout << "You lost " << DMGEInflicts << " HP!" << std::endl;
	int DMGToInflict = std::rand() % playerDMGRange;
	eHP = eHP - DMGToInflict;
	std::cout << "You dealt " <<  DMGToInflict << " damage to the enemy!" << std::endl;
	std::cout << "HP: " << playerHP << std::endl;
	std::cout << std::endl;
	if (playerHP <= 0)
	{
		bPlayerKIA = true;
		std::cout << "You were killed in action!" << std::endl;
		std::cout << "What will you do now?" << std::endl;
		std::cout << std::endl;
		return;
	}
	if (eHP <= 0)
	{
		std::cout << "You win!" << std::endl;
		this->ANode = ChangePointer(ANode, BNode);
		this->BNode = ChangePointer(BNode, CNode);
		this->CNode = ChangePointer(CNode, nullptr);
		this->ADescription = BDescription;
		this->BDescription = CDescription;
		this->CDescription = "";
		return;
	}
	std::cout << std::endl;
	return;
}

//StartNode is required and should be the the highest level Node which would allow the player to restart
void CombatNode::InitializeC(std::string ThisNodeDescription, std::string ADescription, std::string BDescription, std::string StartString,
	std::string CDescription, int playerHP, int eHP, int playerDMGRange, int eDMGRange, 
	Node* ANode, Node* BNode, Node* StartNode, Node* CNode)
{
	KilledInAction.InitializeG("Ending Game.");
	PlayerDied.InitializeN("What will you do now?", "Start Over", "End Game", "", StartNode, &KilledInAction, nullptr);
	bPlayerKIA = false;
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
	CombatNode::StartNode = StartNode;
	CombatNode::CNode = CNode;
	CombatNode::StartString = StartString;
	DEFAULTThisNodeDescription = ThisNodeDescription;
	DEFAULTADescription = ADescription;
	DEFAULTBDescription = BDescription;
	DEFAULTCDescription = CDescription;
	DEFAULTplayerHP = playerHP;
	DEFAULTeHP = eHP;
	DEFAULTplayerDMGRange = playerDMGRange;
	DEFAULTeDMGRange = eDMGRange;
	DEFAULTANode = ANode;
	DEFAULTBNode = BNode;
	DEFAULTCNode = CNode;
}

void CombatNode::ResetDefaults()
{
	ThisNodeDescription = DEFAULTThisNodeDescription;
	ADescription = DEFAULTADescription;
	BDescription = DEFAULTBDescription;
	CDescription = DEFAULTCDescription;
	playerHP = DEFAULTplayerHP;
	eHP = DEFAULTeHP;
	playerDMGRange = DEFAULTplayerDMGRange;
	eDMGRange = DEFAULTeDMGRange;
	ANode = ChangePointer(ANode, DEFAULTANode);
	BNode = ChangePointer(BNode, DEFAULTBNode);
	CNode = ChangePointer(CNode, DEFAULTCNode);
	bPlayerKIA = false;
}

Node* CombatNode::ChangePointer(Node* A, Node* B)
{
	A = B;
	return A;
}