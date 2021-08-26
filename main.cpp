#include "Node.h"
#include "CombatNode.h"

int main()
{
	//std::vector<Node*> Nodes;
	Node* Node3 = new Node("This node is the third test node", "", "", "", nullptr, nullptr);
	Node* Node2 = new Node("This node is the second test node", "", "", "", nullptr, nullptr);
	Node* Node1 = new Node("This node is the base test node", "Node2", "Node3", "", Node2, Node3);
	Node* currentNode = Node1;
	currentNode = currentNode->process();
	currentNode->process();	
	delete Node1;
	delete Node2;
	delete Node3;
	//Nodes = {currentNode, Node1, Node2, Node3};
	//delete[] &Nodes;
	return 0;
}