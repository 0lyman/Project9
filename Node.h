#pragma once
#include "NodeInterface.h"
class Node : public NodeInterface
{
public:
	Node();
	Node(int data);
	Node(int data, Node * leftchild, Node * rightchild);
	virtual ~Node();

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	virtual int getData() ;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	virtual Node * getLeftChild() ;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	virtual Node * getRightChild() ;

	/*
	Sets LeftChild to the given memory location
	*/
	virtual void setLeftChild(Node* newLeftChild);

	/*
	Sets RightChild to the given memory location
	*/
	virtual void setRightChild(Node* newRightChild);

	/*
	* Returns the height of this node. The height is the number of edges
	* from this node to this nodes farthest child.

	- A NULL child has a height of -1
	- A leaf node has a height of 0
	- The height of each node is equal to the maximum of the 
	    heights of its children plus 1 
	*/
	virtual int getHeight();

	/*
	helps in recursively searching for the nodes height
	*/
	int recurseHeight(Node* GetHeightOf);

	/*
	return the balance of the node if balance is -1, 0, or 1 it is balanced
	*/
	int NodesBalance();
protected:
	Node* LeftChild;
	Node* RightChild;
	int Data;
};

