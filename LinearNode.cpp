#include "LinearNode.h"
#include <iostream>

LinearNode::LinearNode(){}

Node* LinearNode::process()
{
	std::cout << ThisNodeDescription << std::endl;
	std::cout << std::endl;
	std::cout << "A) " << ADescription << std::endl;
	std::string Input;
	std::cin >> Input;
	if (Input == "A" || Input == "a")
	{
		if (ANode != nullptr)
		{
			return ANode;
		}
	}
	else 
	{
		std::cout << "You did not enter valid option or your option returned a nullptr. Restarting this node.";
		return this;
	}
}

void LinearNode::InitializeL(std::string Exposition, std::string NextDescription, Node* NextNode)
{
	LinearNode::ThisNodeDescription = Exposition;
	LinearNode::ADescription = NextDescription;
	LinearNode::BDescription = "";
	LinearNode::CDescription = "";
	LinearNode::ANode = NextNode;
	LinearNode::BNode = nullptr;
	LinearNode::CNode = nullptr;
}