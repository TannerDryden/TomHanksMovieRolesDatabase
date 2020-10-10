// Name: Tanner Dryden
// Description: This class is a binary tree class

#pragma once
#include "BinKeyedNode.h"
#include "Queue.h"
#include <ostream>
using namespace std;

template<class K, class P>

class BinSearchTree
{
private:

	// Attributes
	BinKeyedNode<K, P>* head;

	// Helpers
	BinKeyedNode<K, P>* copyHelper(BinKeyedNode<K, P>* temp)
	{
		BinKeyedNode<K, P>* newNode = nullptr;
		if (temp != nullptr)
		{
			try {
				newNode = new BinKeyedNode<K, P>(temp->getPayload(), nullptr, nullptr);
				newNode->setLeft(copyHelper(temp->getLeft()));
				newNode->setRight(copyHelper(temp->getRight()));
			}
			catch (exception & error)
			{
				error;
			}
		}
		return newNode;
	}

	// function to return memory and clear the created tree
	void clearTree(BinKeyedNode<K, P>* temp)
	{
		if (temp != nullptr)
		{
			clearTree(temp->getLeft());
			clearTree(temp->getRight());
			delete temp;
		}
	}

	// Tree traversal method
	void inOrderTraversal(ostream& outStream, const BinKeyedNode<K, P>* temp) const
	{
		if (temp != nullptr)
		{
			inOrderTraversal(outStream, temp->getLeft());
			outStream << *temp;
			inOrderTraversal(outStream, temp->getRight());
		}
	}


	// Insert node helper
	BinKeyedNode<K, P>* insertNode(BinKeyedNode<K, P>* nodePtr, const K& newKey, const P& newPayload)
	{

		if (nodePtr == nullptr) // if empty
		{
			nodePtr = new BinKeyedNode<K, P>(newKey, newPayload, nullptr, nullptr);
		}
		else if (newKey < nodePtr->getKey()) // if less than
		{
			nodePtr->setLeft(insertNode(nodePtr->getLeft(), newKey, newPayload));
		}
		else // greater than or equal to
		{
			nodePtr->setRight(insertNode(nodePtr->getRight(), newKey, newPayload));
		}
		return nodePtr;
	}

	// Find function helper
	bool findNode(BinKeyedNode<K, P>* nodePtr, const K& searchKey, P& returnPayload)
	{
		bool retVal(false);
		if (nodePtr != nullptr) // tree is not empty
		{
			if (searchKey == nodePtr->getKey()) // if the key is found
			{
				retVal = true;
				returnPayload = nodePtr->getPayload();
			}
			else if (searchKey < nodePtr->getKey()) // if key is less than current key then search to the left
			{
				retVal = findNode(nodePtr->getLeft(), searchKey, returnPayload);
			}
			else // if key is less than current key then search to the right
			{
				retVal = findNode(nodePtr->getRight(), searchKey, returnPayload);
			}
		}

		return retVal;
	}

public:
	// Constructors
	BinSearchTree()
	{
		head = nullptr;
	}

	BinSearchTree(const BinSearchTree& fromHead)
	{
		head = nullptr;

		this->head = copyHelper(fromHead.head);
	}


	// Operators
	friend ostream& operator <<(ostream& outStream, const BinSearchTree<K, P>& tree)
	{
			tree.inOrderTraversal(outStream, tree.head);
			return outStream;
	}
	BinSearchTree& operator=(const BinSearchTree& tree)
	{
		if (this != &tree)
		{
			this->clearTree(this->getHead());
			this->head = this->copyHelper(tree.head);
		}
		return(*this);
	}

	// Function to insert into a tree
	void insert(const K& newKey, const P& newPayload)
	{
		head = insertNode(head, newKey, newPayload);
	}

	// Function to search through tree
	bool find(const K& searchKey, P& returnPayload)
	{
		return(findNode(head, searchKey, returnPayload));
	}

	// Destructor
	~BinSearchTree()
	{
		clearTree(head);
	}
};

