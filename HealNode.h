#pragma once
#include "Node.h"
#include "CombatNode.h"

class HealNode : public Node
{
	private:
		int playerHP;
		int HealAmount;
		CombatNode WhereToGetHP;
	public:
		HealNode();
		void InitializeH(std::string ThisNodeDescription, std::string ADescription, std::string BDescription, std::string CDescription,
			Node* ANode, Node* BNode, CombatNode* WhereToGetHP, int HealAmount, Node* CNode = nullptr);
		virtual Node* process() override;
		int GetPlayerHP();
};

