#include "Node.h"
#include <iostream>
#include <locale>
#include <string>
#include "GameOverNode.h"

Node::Node()
{
	Node::ThisNodeDescription = "";
	Node::ADescription = "";
	Node::BDescription = "";
	Node::CDescription = "";
	Node::ANode = nullptr;
	Node::BNode = nullptr;
	Node::CNode = nullptr;
	Node::bIsGameOver = false;
	Node::bCIsOption = false;
}

void Node::InitializeN(std::string ThisNodeDescription, std::string ADescription, std::string BDescription, std::string CDescription,
	Node* ANode, Node* BNode, Node* CNode)
{
	Node::ThisNodeDescription = ThisNodeDescription;
	Node::ADescription = ADescription;
	Node::BDescription = BDescription;
	Node::CDescription = CDescription;
	Node::ANode = ANode;
	Node::BNode = BNode;
	Node::CNode = CNode;
	Node::bIsGameOver = false;
}

//This processes the Node, 
Node* Node::process()
{
	PrintDescriptions();
	std::string input;
	std::locale locale;
	
	std::cin >> input;
	for (char letter : input)
	{
		std::toupper(letter, locale);
	}
	if (input == "A" || input == "a")
	{
		if (ANode != nullptr)
		{
			return ANode;
		}
	}
	if (input == "B" || input == "b")
	{
		if (BNode != nullptr)
		{
			return BNode;
		}
	}
	if ((input == "C" || input == "c") && bCIsOption)
	{
		return CNode;
	}
	else
	{
		std::cout << "You did not enter valid option or your option returned a nullptr. Restarting this node.";
		return this;
	}
}

bool Node::getGameOver()
{
	return Node::bIsGameOver;
}

void Node::PrintDescriptions()
{
	std::cout << ThisNodeDescription << std::endl;
	std::cout << std::endl;
	std::cout << "A) " << ADescription << std::endl;
	std::cout << "B) " << BDescription << std::endl;
	if (CNode != nullptr)
	{
		bCIsOption = true;
		std::cout << "C) " << CDescription << std::endl;
	}
}