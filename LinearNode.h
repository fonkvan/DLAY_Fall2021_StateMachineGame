#pragma once
#include "Node.h"
class LinearNode : public Node
{
	private:
		
	public:
		LinearNode();
		virtual Node* process() override;
		void InitializeL(std::string Exposition, std::string NextDescription, Node* NextNode);
};

