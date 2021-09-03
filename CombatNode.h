#pragma once

#include "Node.h"
#include "GameOverNode.h"

class CombatNode : public Node
{
	private:
		int playerHP;
		int eHP;
		int playerDMGRange;
		int eDMGRange;
		int DEFAULTplayerHP;
		int DEFAULTeHP;
		int DEFAULTplayerDMGRange;
		int DEFAULTeDMGRange;
		std::string StartString;
		std::string DEFAULTThisNodeDescription;
		std::string DEFAULTADescription;
		std::string DEFAULTBDescription;
		std::string DEFAULTCDescription;
		GameOverNode KilledInAction;
		Node* DEFAULTANode;
		Node* DEFAULTBNode;
		Node* DEFAULTCNode;
		Node* StartNode;
		Node* BattleWon;
		Node* BattleLost;
		Node PlayerDied;
		bool bPlayerKIA;
	public:
		CombatNode();
		virtual Node* process() override;
		void CombatCalculation();
		void InitializeC(std::string ThisNodeDescription, std::string ADescription, std::string BDescription, std::string StartString, 
			std::string CDescription, int playerHP, int eHP, int playerDMGRange, int eDMGRange, 
			Node* ANode, Node* BNode, Node* StartNode, Node* Victory, Node* CNode = nullptr);
		void ResetDefaults();
		Node* ChangePointer(Node* A, Node* B);
		void CheckPlayerState();
};