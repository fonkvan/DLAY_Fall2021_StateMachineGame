#pragma once
#include "Node.h"
#include <string>
class GameOverNode : public Node
{
	private:
		
	public:
		GameOverNode();
		virtual Node* process() override;
		void InitializeG(std::string ThisNodeDescription);
};

