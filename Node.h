#pragma once

#include <string>

class Node
{
	protected:
		Node* ANode;
		Node* BNode;
		Node* CNode;
		std::string ThisNodeDescription;
		std::string ADescription;
		std::string BDescription;
		std::string CDescription;
	public:
		Node();
		//CNode is optional
		Node(std::string ThisNodeDescription, std::string ADescription, std::string BDescription, std::string CDescription, 
								Node* ANode, Node* BNode, Node* CNode = nullptr);
		~Node();
		//virtual because this function will be overwritten by child classes.
		virtual Node* process();
};

