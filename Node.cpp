#include "Node.h"
#include <iostream>
#include <locale>

Node::Node()
{
	Node::ThisNodeDescription = "";
	Node::ADescription = "";
	Node::BDescription = "";
	Node::CDescription = "";
	Node::ANode = nullptr;
	Node::BNode = nullptr;
	Node::CNode = nullptr;
}

Node::Node(std::string ThisNodeDescription, std::string ADescription, std::string BDescription, std::string CDescription, 
	Node* ANode, Node* BNode, Node* CNode)
{
	Node::ThisNodeDescription = ThisNodeDescription;
	Node::ADescription = ADescription;
	Node::BDescription = BDescription;
	Node::CDescription = CDescription;
	Node::ANode = ANode;
	Node::BNode = BNode;
	Node::CNode = CNode;
}

Node::~Node(){}

Node* Node::process()
{
	bool bCIsOption = false;

	std::string input;
	std::locale locale;
	std::cout << ThisNodeDescription << std::endl;
	std::cout <<std::endl;
	std::cout << "A) " << ADescription << std::endl;
	std::cout << "B) " << BDescription << std::endl;

	if (CNode != nullptr)
	{
		bCIsOption = true;
		std::cout << "C) " << CDescription << std::endl;
	}
	
	std::cin >> input;
	for (char letter : input)
	{
		std::toupper(letter, locale);
	}
	if (input == "A")
	{
		return ANode;
	}
	if (input == "B")
	{
		return BNode;
	}
	if (input == "C" && bCIsOption)
	{
		return CNode;
	}
	else
	{
		std::cout << "You did not enter valid option. Restarting this node.";
		return this;
	}
}