#pragma once

#include "Node.h"

class CombatNode : public Node
{
	private:
		int playerHP;
		int eHP;
		int playerDMGRange;
		int eDMGRange;
	public:
		CombatNode();
		CombatNode(std::string ThisNodeDescription, std::string ADescription, std::string BDescription, std::string CDescription,
						int playerHP, int eHP, int playerDMGRange, int eDMGRange, Node* ANode, Node* BNode, Node* CNode = nullptr);
		virtual Node* process() override;
		void CombatCalculation();
};