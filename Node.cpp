#include "Node.h"


Node::Node()
{
	LeftChild = NULL;
	RightChild = NULL;
}

Node::Node(int data)
{
	Data = data;
	LeftChild = NULL;
	RightChild = NULL;
}

Node::Node(int data, Node * leftchild, Node * rightchild)
{
	Data = data;
	LeftChild = leftchild;
	RightChild = rightchild;
}

Node::~Node()
{
}


/*
* Returns the data that is stored in this node
*
* @return the data that is stored in this node.
*/
int Node::getData()
{
	return Data;
}

/*
* Returns the left child of this node or null if it doesn't have one.
*
* @return the left child of this node or null if it doesn't have one.
*/
Node * Node::getLeftChild()
{
	return LeftChild;
}

/*
* Returns the right child of this node or null if it doesn't have one.
*
* @return the right child of this node or null if it doesn't have one.
*/
Node *Node::getRightChild()
{
	return RightChild;
}

/*
Sets LeftChild to the given memory location
*/
void Node::setLeftChild(Node* newLeftChild)
{
	LeftChild = newLeftChild;
}

/*
Sets RightChild to the given memory location
*/
void Node::setRightChild(Node* newRightChild)
{
	RightChild = newRightChild;
}


/*
* Returns the height of this node. The height is the number of edges
* from this node to this nodes farthest child.

- A NULL child has a height of -1
- A leaf node has a height of 0
- The height of each node is equal to the maximum of the
heights of its children plus 1
*/
int Node::getHeight()
{
	int HeightLeft, HeightRight;
	if (RightChild != NULL)   // if not null find height else set as NULL (-1)
	{
		HeightRight = recurseHeight(RightChild);
	}
	else
	{
		HeightRight = -1;
	}

	if (LeftChild != NULL)   // if not null find height else set as NULL (-1)
	{
		HeightLeft = recurseHeight(LeftChild);
	}
	else
	{
		HeightLeft = -1;
	}
	// ( recurseHeight(...) + 1 ) is equall to current Height
	if (HeightLeft > HeightRight)
	{
		return HeightLeft + 1;
	}
	else
	{
		return HeightRight + 1;
	}
}


/*
helps in recursively searching for the nodes height and if its balanced
*/
int Node::recurseHeight(Node* GetHeightOf)
{
	int HeightLeft, HeightRight;
	if (GetHeightOf->getRightChild() != NULL)   // if not null find height else set as NULL (-1)
	{
		HeightRight = recurseHeight(GetHeightOf->getRightChild());
	}
	else
	{
		HeightRight = -1;
	}

	if (GetHeightOf->getLeftChild() != NULL)   // if not null find height else set as NULL (-1)
	{
		HeightLeft = recurseHeight(GetHeightOf->getLeftChild());
	}
	else
	{
		HeightLeft = -1;
	}
	// ( recurseHeight(...) + 1 ) is equall to current Height
	if (HeightLeft > HeightRight)
	{
		return HeightLeft + 1;
	}
	else
	{
		return HeightRight + 1;
	}
}

/*
- return the balance of the node if balance is -1, 0, or 1 it is balanced
- The formula HeightR – HeightL is used to calculate the balance of each node

*/
int Node::NodesBalance()
{
	int HeightLeft, HeightRight;
	if (RightChild != NULL)   // if not null find height else set as NULL (-1)
	{
		HeightRight = recurseHeight(RightChild);
	}
	else
	{
		HeightRight = -1;
	}

	if (LeftChild != NULL)   // if not null find height else set as NULL (-1)
	{
		HeightLeft = recurseHeight(LeftChild);
	}
	else
	{
		HeightLeft = -1;
	}
	return (HeightRight - HeightLeft);
}