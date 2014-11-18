#pragma once
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include "treenode.h"
#include "binarytree.hs"

using namespace std;

template<class ItemType>
class binarysearchtree:public treenodeTree <ItemType>
{
private:
  treenode < ItemType > *rootPtr;
  numberOfNodes = 0;
protected:
//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
// Recursively finds where the given node should be placed and
// inserts it in a leaf at that point.
  treenode < ItemType > *insertInorder (treenode < ItemType > *subTreePtr, treenode < ItemType > *newNode);
// Removes the given target value from the tree while maintaining a
// binary search tree.
  treenode < ItemType > *removeValue (treenode < ItemType > *subTreePtr, const ItemType target, bool & success);

// Removes a given node from a tree while maintaining a
// binary search tree.
  treenode < ItemType > *removeNode (treenode < ItemType > *nodePtr);
// Removes the leftmost node in the left subtree of the node
// pointed to by nodePtr.
// Sets inorderSuccessor to the value in this node.
// Returns a pointer to the revised subtree.
  treenodes<ItemType> *removeLeftmostNode (treenode<ItemType> *subTreePtr, ItemType& inorderSuccessor);
// Returns a pointer to the node containing the given value,
// or nullptr if not found.
  treenode<ItemType> *findNode(treenode<ItemType> *treePtr, const ItemType &target) const;

public:
//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
  binarysearchtree ();
  binarysearchtree (const ItemType & rootItem);
  binarysearchtree (const binarysearchtree < ItemType > &tree);

  virtual ~ binarysearchtree();
//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
  bool isEmpty () const;

  int getHeight () const;

  int getNumberOfNodes () const;

  ItemType getRootData () const throw (PrecondViolatedExcep);

  void setRootData (const ItemType & newData) const throw (PrecondViolatedExcep);

  bool add (const ItemType & newEntry);

  bool remove (const ItemType & anEntry);

  void clear ();

  ItemType getEntry (const ItemType & anEntry) const throw (NotFoundException);

  bool contains (const ItemType & anEntry) const;

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------
  void preorderTraverse (void visit (ItemType &)) const;

  void inorderTraverse (void visit (ItemType &)) const;

  void postorderTraverse (void visit (ItemType &)) const;

//------------------------------------------------------------
// Overloaded Operator Section.
//------------------------------------------------------------
  binarysearchtree < ItemType > &operator= (const binarysearchtree < ItemType > &rightHandSide);
};  // end binarysearchtree

/*
	binarysearchtree()
	Precondition: N/A
	Postcondition: an empty binary search tree is initialized with
	no nodes.
*/
template<ItemType>
binarysearchtree<ItemType>::binarysearchtree()
{
	numberOfNodes = 0;
	rootPtr = NULL;
}

/*
	binarysearchtree(const ItemType& rootItem)
	Precondition: N/A
	Postcondition:Initializes a binarysearchtree with one node.
*/
template<ItemType>
binarysearchtree<ItemType>::binarysearchtree(const ItemType& rootItem)
{
	numberOfNodes = 1;
	rootPtr = new treenode<ItemType>(rootItem, NULL, NULL);
}

/*
	binarysearchtree(const binarysearchtree<ItemType> &tree)
	Precondition: N/A
	Postcondition: copies a binarysearchtree over.
*/
template<ItemType>
binarysearchtree<ItemType>::binarysearchtree(const binarysearchtree<ItemType> &tree)
{
	numberOfNodes = 0;
	rootPtr = copytree(tree.rootPtr);
	numberOfNodes += tree.numberOfNodes;
}

/*
	bool isEmpty
	Precondition: N/A
	Postcondition: checks to see if there are any nodes if none return 0;
*/
template<ItemType>
bool binarysearchtree<ItemType>::isEmpty();
{
	if(rootPtr != NULL)
		return true;
	else
		return false;
}

/*
*/
template<ItemType>
int binarysearchtree<ItemType>::getHeight();

/*
	int getNumberOfNodes
	Precondition: N/A
	Postcondition: returns the number of nodes in the tree.
*/
template<ItemType>
int binarysearchtree<ItemType>::getNumberOfNodes() const
{
	return numberOfNodes;
}
/*
	ItemType getRootData() const
	Precondition: the tree must not be empty
	Postcondition: returns item stored at root.
*/
template<ItemType>
ItemType binarysearchtree<ItemType>::getRootData() const
{
	return rootPtr.getItem();
}

/*
	void setRootData(const ItemType& newData)
	Precondition: Data passed over needs to be same data type.
	Postcondition: Data is set to the new data.
*/
template<ItemType>
void binarysearchtree<ItemType>::setRootData(const ItemType& newData)
{
	rootPtr.setItem(newData);
}

/*
	
*/
template<ItemType>
bool binarysearchtree<ItemType>:: add(const ItemType& newData)
{
	treenode<ItemType> temp = new treenode<ItemType>(newData, NULL, NULL);
	insertInorder(rootPtr, temp);
	numberofNodes++;
	return true;
}

/*
	bool remove(const ItemType& anEntry) const
	Precondition: N/A
	Postcondition: removes node if found and returns true, false otherwise.
*/
template<ItemType>
bool binarysearchtree<ItemType>::remove(const ItemType& anEntry) const
{
	bool success
	rootPtr = removeValue(rootPtr, anEntry, success);
	return success;
}

/*
	void clear()
	Precondition: N/A
	Postcondition: All the nodes will be removed from the tree
*/
template<ItemType>
void binarysearchtree<ItemType>::clear()
{
	destroyTree();
	numberOfNodes = 0;
}

template<ItemType>
ItemType binarysearchtree<ItemType>::getEntry(const ItemType &anEntry)
{
	
}

/*
	bool contains(const ItemType &anEntry)
	Precondition: N/A
	Postcondition: calls findNode. Returns false if null is given true otherwise
*/
template<ItemType>
bool binarysearchtree<ItemType>::contains(const ItemType &anEntry)
{
	treeNode<ItemType>* returned;
	returned = findNode(rootPtr, anEntry)
	if(returned == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//Protected Recursion

/*
	treenode <ItemType> *insertInorder(treenode<ItemType>*subTreePtr, treenode<ItemType>*newNode);
	Precondition:N/A
	Postcondition: Finds where the node should be placed and then inserts it.
*/
template<ItemType>
treenode<ItemType>* binarysearchtree::insertInorder(treenode<ItemType>*subTreePtr,treenode<ItemType>*newNode)
{
	treenode<ItemType>* temp;
	if(subTreePtr == NULL)
	{
		return newNode;
	}
	else if(subTreePtr->getItem() > newNode->getItem())
	{
		temp = insertInorder(subTreePtr->getLeftChildPtr(), newNode);
		subTreePtr->setLeftChildPtr(temp);
	}
	else
	{
		temp = insertInorder(subTreePtr->getRightChildPtr(), newNodePtr)
		subTreePtr->setRightChildPtr(temp);
	}
	return subTreePtr;
}

/*
	treenode < ItemType > *removeValue (treenode < ItemType > *subTreePtr, const ItemType target, bool & success);
	Precondition: 
	Postcondition:
*/
template<ItemType>
treenode<ItemType>* binarysearchtree::removeValue(treenode<ItemType>* subTreePtr, treenode<ItemType>* newNode)
{
	treenode<ItemType>* temp;
	if(subtreePtr == NULL)
	{
		success = false;
		return NULL;
	}
	else if(subTreePtr->getItem() == target)
	{
		subTreePtr = removeNode(subTreePtr)
		success = true;
		return subTreePtr;
	}
	else if(subTreePtr->getItem() > target)
	{
		temp = removeValue(subTreePtr->getLeftChildPtr(), target, success);
		subTreePtr->setRightChildPtr(temp);
		return subTreePtr;
	}
	else
	{
		temp = removeValue(subTreePtr->getRightChildPtr(), target, success)
		subTreePtr->setRightChildPtr(tempPtr);
		return subTreePtr;
	}
}

template<ItemType>
treenode<ItemType>* binarysearchtree::removeNode(treenode<ItemType>*nodePtr)
{
	treenode<ItemType>* rightPtr = nodePtr->getRightChildPtr;
	treenode<ItemType>* leftPtr = nodePtr->getLeftChildPtr;
	treenode<ItemType>* nodeToConnectPtr;
	treenode<ItemType>* temp;
	ItemType newValue;
	
	if(leftPtr == NULL && rightPtr == NULL)		//checks to see if the node is a leaf
	{
		delete nodePtr;
		nodePtr = NULL;
		return nodePtr;
	}
	else if(leftPtr == NULL || rightPtr == NULL)
	{
		if(leftPtr != NULL)
		{
			nodeToConnectPtr = leftPtr;
		}
		else
		{
			nodeToConnectPtr = rightPtr;
		}
		delete nodePtr;
		nodePtr = NULL;
		return nodeToConnectPtr;
	}
	else
	{
		temp  = removeLeftMostNode(rightPtr, newValue)
		nodePtr->setRightChildPtr(tempPtr);
		nodePtr->setItem(newValue);
		return nodePtr;
	}
}

template<ItemType>
treenode<ItemType>* binarysearchtree::removeLeftmostNode(treenode<ItemType>*subTreePtr, ItemType& inorderSuccessor)
{
	if(subTreePtr->getLeftChildPtr() == NULL)
	{
		inorderSuccessor = nodePtr(getItem);
		return removeNode(nodePtr);
	}
	else
		return removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccessor);
}

template<ItemType>
treenode<ItemType>* binarysearchtree::findNode(treenode<ItemType>*treePtr, const ItemType &target) const
{
	if(treePtr == NULL)						//Not Found
	{
		return NULL;
	}
	else if(treePtr->getitem() == target)	//Found
	{
		return subTreePtr;
	}
	else if(treePtr->getItem() > target)
	{
		return findNode(treePtr->getLeftChildPtr(), target);
	}
	else
	{
		return findNode(treePtr->getRightChildPtr(), target);
	}
}

#endif
