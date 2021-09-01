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
		bool bIsGameOver;
		bool bCIsOption;
	public:
		Node();
		//virtual because this function will be overwritten by child classes.
		virtual Node* process();
		bool getGameOver();
		//CNode is optional
		void InitializeN(std::string ThisNodeDescription, std::string ADescription, std::string BDescription, std::string CDescription,
			Node* ANode, Node* BNode, Node* CNode = nullptr);
		void PrintDescriptions();
		Node* GetNodeFromInput();
};

