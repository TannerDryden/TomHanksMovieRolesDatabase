// Name: Tanner Dryden
// Description: This class helps create a binary search tree

#pragma once
#include <ostream>
using namespace std;

template<class K, class P>
class BinKeyedNode
{
private:
	K key;
	P payload;
	BinKeyedNode<K, P>* left;
	BinKeyedNode<K, P>* right;

public:

	// Constructors
	BinKeyedNode(K newKey, P newPayload, BinKeyedNode<K, P>* newLeft, BinKeyedNode<K, P>* newRight)
	{
		setKey(newKey);
		setPayload(newPayload);
		setLeft(newLeft);
		setRight(newRight);
	}

	// Accessors 
	P getPayload() const
	{
		return payload;
	}
	K getKey() const
	{
		return key;
	}
	BinKeyedNode* getLeft() const
	{
		return left;
	}
	BinKeyedNode* getRight() const
	{
		return right;
	}

	// Mutators
	void setPayload(P newPayload)
	{
		payload = newPayload;
	}
	void setKey(K newKey)
	{
		key = newKey;
	}
	void setLeft(BinKeyedNode<K, P>* newLeft)
	{
		left = newLeft;
	}
	void setRight(BinKeyedNode <K, P>* newRight)
	{
		right = newRight;
	}

	// Operators
	friend ostream& operator <<(ostream& outStream, const BinKeyedNode<K, P>& node)
	{	
		outStream << node.getPayload();
		return outStream;
	}
};

