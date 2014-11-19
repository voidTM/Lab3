#pragma once
#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include "treenode.h"

using namespace std;

template<class ItemType>
class binarytree
{
private:
	treenode<ItemType>* rootPtr;
	int height;
	int leftHeight;
	int rightHeight;
	int numberOfNodes;
protected:
	//------------------------------------------------------------
	// Protected Utility Methods Section:
	// Recursive helper methods for the public methods.
	//------------------------------------------------------------
	int getHeightHelper(treenode < ItemType > *subTreePtr) const;			//done
	int getNumberOfNodesHelper(treenode < ItemType > *subTreePtr) const;	//done
	// Recursively deletes all nodes from the tree.
	void destroyTree(treenode < ItemType > *subTreePtr);					
	// Recursively adds a new node to the tree in a left/right fashion to
	// keep the tree balanced.
	treenode < ItemType > *balancedAdd(treenode < ItemType > *subTreePtr, treenode < ItemType > *newNodePtr);	//done
	// Removes the target value from the tree by calling moveValuesUpTree
	// to overwrite value with value from child.
	treenode < ItemType > *removeValue(treenode < ItemType > *subTreePtr, const ItemType target, bool & success);
	// Copies values up the tree to overwrite value in current node until
	// a leaf is reached; the leaf is then removed, since its value is
	// stored in the parent.
	treenode < ItemType > *moveValuesUpTree(treenode < ItemType > *subTreePtr);
	// Recursively searches for target value in the tree by using a
	// preorder traversal.
	treenode < ItemType > *findNode(treenode < ItemType > *treePtr, const ItemType & target, bool & success) const;
	// Copies the tree rooted at treePtr and returns a pointer to
	// the copy.
	treenode < ItemType > *copyTree(const treenode < ItemType > *treePtr) const;	//done
	// Recursive traversal helper methods:
	void preorder(void visit(ItemType &), treenode < ItemType > *treePtr) const;
	void inorder(void visit(ItemType &), treenode < ItemType > *treePtr) const;
	void postorder(void visit(ItemType &), treenode < ItemType > *treePtr) const;
public:
	//------------------------------------------------------------
	// Constructor and Destructor Section.
	//------------------------------------------------------------
	binarytree();
	binarytree(const ItemType rootItem);
	binarytree(const ItemType rootItem, const binarytree < ItemType > *leftTreePtr, const binarytree < ItemType > *rightTreePtr);
	binarytree(const binarytree < ItemType > &tree);
//	virtual ~binarytree();
	//------------------------------------------------------------
	// Public BinaryTreeInterface Methods Section.
	//------------------------------------------------------------
	bool isEmpty() const;
	int getHeight() const;
	int getNumberOfNodes() const;
	ItemType getRootData() const;
	void setRootData(const ItemType newData);
	bool add(const ItemType newData); // Adds a node
	bool remove(const ItemType & data); // Removes a node
	void clear();
	ItemType getEntry(const ItemType & anEntry) const;
	bool contains(const ItemType & anEntry) const;
	//------------------------------------------------------------
	// Public Traversals Section.
	//------------------------------------------------------------
	void postorderTraverse(void visit(ItemType &)) const;
	//------------------------------------------------------------
	// Overloaded Operator Section.
	//------------------------------------------------------------
	binarytree & operator= (const binarytree & rightHandSide);
}; // end binarytree
/*
binarytree()
Precondition: N/A
Postcondition: Initializes a binary tree with no nodes
and height of 0;
*/
template<class ItemType>
binarytree<ItemType>::binarytree()
{
	rootPtr = NULL;
	height = 0;
	leftHeight = 0;
	rightHeight = 0;
	numberOfNodes = 0;
}
/*
binarytree(ItemType rootItem)
Precondition: N/A
Postcondition: Initializes a binary tree with one root nodes
and height of 0;
*/
template<class ItemType>
binarytree<ItemType>::binarytree(ItemType rootItem)
{
	rootPtr = new treenode<ItemType>(rootItem, NULL, NULL);
	height = 1;
	leftHeight = 0;
	rightHeight = 0;
	numberOfNodes = 0;
}
/*
binarytree(ItemType rootItem, const binarytree < ItemType > *leftTreePtr, const binarytree < ItemType > *rightTreePtr)
Precondition: Two trees already made
Postcondition: combines two already made trees with the new node as the root
*/
template<class ItemType>
binarytree<ItemType>::binarytree(ItemType rootItem, const binarytree < ItemType > *leftTreePtr, const binarytree < ItemType > *rightTreePtr)
{
	rootPtr = new treenode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
	leftHeight = leftTreePtr->getHeight();
	rightHeight = rightTreePtr->getHeight();

	if (leftHeight > rightHeight)
		height = leftHeight;
	else
		height = rightHeight;
}
/*
binarytree(const binarytree <ItemType> &tree)
Precondition: An address to another valid binary tree.
Postcondition: The binary tree has been copied over to this object.
*/
template<class ItemType>
binarytree<ItemType>::binarytree(const binarytree<ItemType> &tree)
{
	rootPtr = copyTree(treePtr.rootPtr);
}

/*
~binarytree()
Precondition: N/A
Postcondition: delete all the nodes in the tree.
*/
/*
template<class ItemType>
binarytree<ItemType>::~binarytree()
{
	destroyTree(rootPtr);
}*/
/*
bool isEmpty()
Precondition: N/A
Postcondition: Checks to see if there are any branchs left in front
of the particular node.
*/
template<class ItemType>
bool binarytree<ItemType>::isEmpty() const
{
	if (height == 0 && rootPtr == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*
int getHeight()
Precondition: N/A
Postcondition: Finds the distance from the root to the most distant node.
*/
template<class ItemType>
int binarytree<ItemType>::getHeight() const
{
	cout << "attempting to find height: at getHeight" << endl;
	if (rootPtr != NULL)
	{
		return getHeightHelper(rootPtr);
	}
	else
	{
		cout << "root is null" << endl;
		return 0;
	}
}
/*
ItemType getRootData()
Preconditon: The data at root has already been defined.
Postcondition: Returns the data stored within root.
*/
template<class ItemType>
ItemType binarytree<ItemType>::getRootData() const
{
	return rootPtr->getItem();
}
/*
void setRootData(ItemType newData)
Precondition: N/A
Postcondition: sets the newData to the
*/
template<class ItemType>
void binarytree<ItemType>::setRootData(ItemType newData)
{
	rootPtr->setItem(newData);
}
/*
bool add(ItemType newData)
Precondition: N/A
Postcondition: adds a new node to the binary tree
and then puts the binary tree into the based on height.
*/
template<class ItemType>
bool binarytree<ItemType>::add(ItemType newData)
{
	treenode<ItemType> * newNodePtr = new treenode<ItemType>(newData);
	treenode<ItemType>* currPtr = rootPtr;
	treenode<ItemType>* movingPtr;
//	cout << "newPtr" << newNodePtr->getItem() << endl;
	if (rootPtr == NULL)
	{
//		cout << "root was null" << endl;
		rootPtr = newNodePtr;
//		cout << "rootPtr" << rootPtr->getItem() << endl;
	}
	else
	{
		rootPtr = balancedAdd(rootPtr, newNodePtr);
//		cout << "rootPtr" << rootPtr->getItem() << endl;
//		cout << "testing" << endl;
	}
	return true;
}
/*
bool remove(const ItemyType &toRemove)
Precondition: N/A
Postcondition: searches for a particular node and then removes it.
*/
template<class ItemType>
bool binarytree<ItemType>::remove(const ItemType &toRemove)
{
	string rm = toRemove.getData;
}
/*
void clear()
Precondition: N/A
Postcondition: Removes all the nodes within the binary tree.
*/
template<class ItemType>
void binarytree<ItemType>::clear()
{
}
/*
ItemType getEntry(const ItemType & anEntry) const
Precondition: N/A
Postcondition: will look for a particular entry
*/
template<class ItemType>
ItemType binarytree<ItemType>::getEntry(const ItemType & anEntry) const
{
}
template<class ItemType>
void binarytree<ItemType>::postorderTraverse(void visit(ItemType &)) const
{
}
//Protected recursive equations
/*
treenode <ItemType> *copyTree(const treenode <ItemType> *treePtr) const
Precondition: The pointer recieved poitns to another binary tree
Postcondtion: Copies the binary tree over and then returns the root
of that newly created tree.
*/
template<class ItemType>
treenode<ItemType>* binarytree<ItemType>::copyTree(const treenode < ItemType > *treePtr) const
{
	treeNode<ItemType>* newTreePtr = NULL;
	if (treePtr != NULL)
	{
		newTreePtr = new treenode<ItemType>(treePtr->getItem())
		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightPtr()));
	}
	return newTreePtr;
}
/*
int getHeightHelper(treenode<ItemType>* subtreePtr)
Precondition: N/A
Postconditon: Finds the maximum height of the tree and then returns it.
*/
template<class ItemType>
int binarytree<ItemType>::getHeightHelper(treenode < ItemType > *subTreePtr) const
{
	if (subTreePtr == NULL)
	{
		cout << "ENdFound "<< endl;
		return 0;
	}
	else
	{
		int  i = 1 + max(getHeightHelper(subTreePtr->getLeftPtr()), getHeightHelper(subTreePtr->getRightPtr()));
		cout << "end not found currently at" << i << endl;
		return i;
	}
}
/*
treenode<ItemType> *balancedAdd(treenode<ItemType> *subTreePtr, treenode<ItemType> *newNodePtr)
*/
template<class ItemType>
treenode < ItemType >* binarytree<ItemType>::balancedAdd(treenode<ItemType> *subTreePtr, treenode<ItemType> *newNodePtr)
{
	if (subTreePtr == NULL) //If the tree is empty or at end for that particular node.
	{
		cout << " null found returning" << endl;
		cout << "newNodePtr in balance" << newNodePtr->getItem() << endl;
		return newNodePtr;
	}
	/*
	if(subTreePtr->getLeftPtr() == NULL)
		subTreePtr->setLeftChildPtr(newNodePtr);
	else if(subTreePtr->getRightPtr() == NULL)
		subTreePtr->setRightChildPtr(newNodePtr); */
	else
	{
		treenode<ItemType> *leftPtr = subTreePtr->getLeftPtr();
		treenode<ItemType> *rightPtr = subTreePtr->getRightPtr();
		cout << "getting height from add function" << endl;
		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{	
			cout << "Entering right Branch" << endl;
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			if (rightPtr != NULL)
			{
				cout << "rightPtr in balance" << rightPtr->getItem() << endl;
			}
			subTreePtr->setRightChildPtr(rightPtr);
		}
		else
		{
			cout << "Entering Left Branch" << endl;
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			if (leftPtr != NULL)
			{
				cout << "leftPtr in balance" << leftPtr->getItem() << endl;
			}
			subTreePtr->setLeftChildPtr(leftPtr);
		}
		return subTreePtr; //<-This is returning null atm
	}
}
/*
	treenode<ItemType>* moveValuesUpTree(treenode<ItemType>* subTreePtr)
*/
template<class ItemType>
treenode<ItemType>* binarytree<ItemType>::moveValuesUpTree(treenode<ItemType>* subTreePtr)
{
	treenode<ItemType>* left = subTreePtr->getLeftPtr();
	treenode<ItemType>* right = subTreePtr->getRightPtr();
	treenode<ItemType>* temp;

	if (left == NULL && right == NULL)		//if leaf delete the leaf.
	{
		delete subTreePtr;
		subTreePtr = NULL;
		return subTreePtr;
	}
	else if (left != NULL && right != NULL)
	{
		if (left->getItem() > right->getItem)
		{
			temp = moveValuesUpTree(left);
			return temp;
		}
		else
		{
			temp = moveValuesUpTree(right);
			return temp;
		}
	}
	else if (left == NULL || right == NULL)
	{
		if (left != NULL)
		{

		}
	}
}

/*
	treenode < ItemType > *findNode(treenode < ItemType > *treePtr, const ItemType & target, bool & success) const;
	Precondition: N/A
	Postcondition: Looks for the particular node and then returns the location of the node if found.
*/
template<class ItemType>
treenode<ItemType>* binarytree<ItemType>::findNode(treenode<ItemType> *treePtr, const ItemType& target, bool& success) const
{
	if (treePtr == NULL)
	{
		success = false;
		return NULL;
	}
	else if (treePtr->getItem() == target)		//the node matches that of 
	{
		success = true;
		return treePtr;
	}
	else if (treePtr->getItem() > target)
	{
		treePtr = findNode(treePtr->getLeftChildPtr(), target, success);
		return treePtr;
	}
	else if (tree->getItem() < target)
	{
		tempPtr = findNode(treePtr->getRightChildPtr(), target, success);
		return treePtr;
	}
}

#endif