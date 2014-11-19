#pragma once
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include "treenode.h"
#include "binarytree.h"

using namespace std;

template<class ItemType>
class binarysearchtree:public binarytree<ItemType>
{
private:
  treenode < ItemType > *rootPtr;
  int numberOfNodes;
  int height;
protected:
//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------
// Recursively finds where the given node should be placed and
// inserts it in a leaf at that point.
  treenode < ItemType > *insertInorder (treenode < ItemType > *subTreePtr, treenode < ItemType > *newNode, int& height);
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
  treenode<ItemType>* removeLeftmostNode(treenode<ItemType>* subTreePtr, ItemType& inorderSuccessor);
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

//  virtual ~ binarysearchtree();
//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
  bool isEmpty () const;

  int getHeight () const;

  int getNumberOfNodes () const;

  ItemType getRootData () const;

  void setRootData (const ItemType & newData) const;

  bool add (const ItemType & newEntry);

  bool remove (const ItemType & anEntry);

  void clear ();

  ItemType getEntry (const ItemType & anEntry) const;

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
  binarysearchtree <ItemType> &operator= (const binarysearchtree < ItemType > &rightHandSide);
};  // end binarysearchtree

/*
	binarysearchtree()
	Precondition: N/A
	Postcondition: an empty binary search tree is initialized with
	no nodes.
*/
template<class ItemType>
binarysearchtree<ItemType>::binarysearchtree()
{
	numberOfNodes = 0;
	rootPtr = NULL;
	height = 0;
}

/*
	binarysearchtree(const ItemType& rootItem)
	Precondition: N/A
	Postcondition:Initializes a binarysearchtree with one node.
*/
template<class ItemType>
binarysearchtree<ItemType>::binarysearchtree(const ItemType& rootItem)
{
	numberOfNodes = 1;
	rootPtr = new treenode<ItemType>(rootItem, NULL, NULL);
	height = 1;
}

/*
	binarysearchtree(const binarysearchtree<ItemType> &tree)
	Precondition: N/A
	Postcondition: copies a binarysearchtree over.
*/
template<class ItemType>
binarysearchtree<ItemType>::binarysearchtree(const binarysearchtree<ItemType> &tree)
{
	numberOfNodes = 0;
	height = 0;
	rootPtr = copytree(tree.rootPtr);
	numberOfNodes += tree.numberOfNodes;
	height += tree.height;
}

/*
	bool isEmpty
	Precondition: N/A
	Postcondition: checks to see if there are any nodes if none return 0;
*/
template<class ItemType>
bool binarysearchtree<ItemType>::isEmpty() const
{
	if(rootPtr != NULL)
		return true;
	else
		return false;
}

/*
	int getNumberOfNodes
	Precondition: N/A
	Postcondition: returns the number of nodes in the tree.
*/
template<class ItemType>
int binarysearchtree<ItemType>::getNumberOfNodes() const
{
	return numberOfNodes;
}
/*
	ItemType getRootData() const
	Precondition: the tree must not be empty
	Postcondition: returns item stored at root.
*/
template<class ItemType>
ItemType binarysearchtree<ItemType>::getRootData() const
{
	return rootPtr.getItem();
}

/*
	void setRootData(const ItemType& newData)
	Precondition: Data passed over needs to be same data type.
	Postcondition: Data is set to the new data.
*/
template<class ItemType>
void binarysearchtree<ItemType>::setRootData(const ItemType& newData) const
{
	rootPtr.setItem(newData);
}

/*
	bool add(const ItemType& newData)
	Precondition: N/A
	Postcondition: Takes in the new entry and adds it to the binary search tree.
	Also updates the height if the height of the new leaf is greater than that of
	the previously recorded height.
*/
template<class ItemType>
bool binarysearchtree<ItemType>:: add(const ItemType& newData)
{
	int tempHeight = 0;
	cout << "Adding :   temporary Height is " << tempHeight <<endl;
	cout << "height before search is" << height << endl;
	treenode<ItemType>* temp = new treenode<ItemType>(newData, NULL, NULL);
	cout << "Node to be added" << temp->getItem() << endl;
	rootPtr = insertInorder(rootPtr, temp, tempHeight);
	numberOfNodes += 1;
	if (tempHeight > height)
		height = tempHeight;
	return true;
}

/*
	bool remove(const ItemType& anEntry) const
	Precondition: N/A
	Postcondition: removes node if found and returns true, false otherwise.
*/
template<class ItemType>
bool binarysearchtree<ItemType>::remove(const ItemType& anEntry)
{
	bool success
	rootPtr = removeValue(rootPtr, anEntry, success);
	return success;
}

/*
	int getHeight() const
*/
template<class ItemType>
int binarysearchtree<ItemType>::getHeight() const
{
	return height;
}
/*
	void clear()
	Precondition: N/A
	Postcondition: All the nodes will be removed from the tree
*/
template<class ItemType>
void binarysearchtree<ItemType>::clear()
{
	destroyTree();
	numberOfNodes = 0;
}

/*
	ItemType getEntry
	Precondition: N/A
	Postcondition: 
*/
template<class ItemType>
ItemType binarysearchtree<ItemType>::getEntry(const ItemType &anEntry) const
{
	return anEntry;
}

/*
	bool contains(const ItemType &anEntry)
	Precondition: N/A
	Postcondition: calls findNode. Returns false if null is given true otherwise
*/
template<class ItemType>
bool binarysearchtree<ItemType>::contains(const ItemType &anEntry) const
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
	Also keeps track of the height of the leaf that is being added.
*/
template<class ItemType>
treenode<ItemType>* binarysearchtree<ItemType>::insertInorder(treenode<ItemType>*subTreePtr, treenode<ItemType>*newNode, int& traveled)
{
	traveled += 1;
	cout << "now traveled " << traveled << endl;
	treenode<ItemType>* temp;
	if(subTreePtr == NULL)
	{
		return newNode;
	}
	else if(subTreePtr->getItem() > newNode->getItem())
	{
		cout << "current node " << subTreePtr->getItem() << endl;
		temp = insertInorder(subTreePtr->getLeftPtr(), newNode, traveled);
		subTreePtr->setLeftChildPtr(temp);
	}
	else
	{
		cout << "current node " << subTreePtr->getItem() << endl;
		temp = insertInorder(subTreePtr->getRightPtr(), newNode, traveled);
		subTreePtr->setRightChildPtr(temp);
	}
	return subTreePtr;
}

/*
	treenode < ItemType > *removeValue (treenode < ItemType > *subTreePtr, const ItemType target, bool & success);
	Precondition: N/A
	Postcondition: Searches for the value and then attempts to remove it.
	Success = true if removed, false otherwise.
*/
template<class ItemType>
treenode<ItemType>* binarysearchtree<ItemType>::removeValue(treenode<ItemType>* subTreePtr, ItemType target, bool & success)
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
		temp = removeValue(subTreePtr->getLeftPtr(), target, success);
		subTreePtr->setRightChildPtr(temp);
		return subTreePtr;
	}
	else
	{
		temp = removeValue(subTreePtr->getRightPtr(), target, success)
		subTreePtr->setRightChildPtr(tempPtr);
		return subTreePtr;
	}
}

/*
	treendoe<ItemType>* removeNode(treenode<ItemType>*nodePtr)
	Precondition: Node that is being removed should actually exist.
	Postcondition: Removes the node and shifts the nodes below it up accordingly.
*/
template<class ItemType>
treenode<ItemType>* binarysearchtree<ItemType>::removeNode(treenode<ItemType>*nodePtr)
{
	treenode<ItemType>* rightPtr = nodePtr->getRightPtr;
	treenode<ItemType>* leftPtr = nodePtr->getLeftPtr;
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

/*
	treenode<ItemType>* removeLeftmostNode(treenode<ItemType>*subTreePtr, ItemType& inorderSuccessor)
	Precondition: Node must actually exist
	Postcondition: Overrides the node with the 
*/
template<class ItemType>
treenode<ItemType>* binarysearchtree<ItemType>::removeLeftmostNode(treenode<ItemType>*subTreePtr, ItemType& inorderSuccessor)
{
	if(subTreePtr->getLeftPtr() == NULL)
	{
		inorderSuccessor = nodePtr(getItem);
		return removeNode(nodePtr);
	}
	else
		return removeLeftmostNode(nodePtr->getLeftPtr(), inorderSuccessor);
}

/*
	treenode<ItemType>* findNode(treenode<ItemType>*treePtr, const ItemType &target) const
	Precondition: N/A
	Postcondition: Searches for particular node based on the given data and then returns its address,
	otherwise returns NULL if not found.
*/
template<class ItemType>
treenode<ItemType>* binarysearchtree<ItemType>::findNode(treenode<ItemType>*treePtr, const ItemType &target) const
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
		return findNode(treePtr->getLeftPtr(), target);
	}
	else
	{
		return findNode(treePtr->getRightPtr(), target);
	}
}

#endif
