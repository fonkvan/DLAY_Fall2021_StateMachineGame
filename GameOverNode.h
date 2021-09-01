#pragma once
#include "Node.h"
#include <string>
class GameOverNode : public Node
{
	private:
		
	public:
		GameOverNode();
		//GameOverNode(std::string ThisNodeDescription);
		virtual Node* process() override;
		void InitializeG(std::string ThisNodeDescription);
};

