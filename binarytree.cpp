#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "treenode.h"
#include "binarytree.h"

using namespace std;


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
}

/*
	binarytree(ItemType rootItem, const binarytree < ItemType > *leftTreePtr, const binarytree < ItemType > *rightTreePtr)
	Precondition: none
	Postcondition: 
*/
template<class ItemType>
binarytree<ItemType>::binarytree(ItemType rootItem, const binarytree < ItemType > *leftTreePtr, const binarytree < ItemType > *rightTreePtr)
{
	rootPtr = new treenode<ItemType>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr));
	height = 1;
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
	bool isEmpty()
	Precondition: N/A
	Postcondition: Checks to see if there are any branchs left in front
	of the particular node.
*/
template<class ItemType>
bool binarytree<ItemType>::isEmpty() const
{
	if (height == 0 && rootPtr == NULL)
		{return true;}
	else
		{return false;}
}

/*
	int getHeight()
	Precondition: N/A
	Postcondition: Finds the distance from the root to the most distant node.
*/
template<class ItemType>
int binarytree<ItemType>::getHeight() const
{
	if (rootPtr != NULL)
		{return getHeightHelper(rootPtr);}
	else
		{return 0;}
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
	and then puts the binary tree into the right place.
*/
template<class ItemType>
bool binarytree<ItemType>::add(ItemType newData)
{
	treenode<ItemType> * newNodePtr = new treenode<ItemType>(newData);
	rootPtr = balancedAdd(rootPtr, newNodePtr)
}

/*
	bool remove(const ItemyType &toRemove)
	Precondition: N/A
	Postcondition: searches for a particular node and then removes it.
*/
template<class ItemType>
bool binarytree<ItemType>::remove(const ItemType &toRemove) 
{
	
}

/*
	void clear()
	Precondition: N/A
	Postcondition: Removes all the nodes within the binary tree.
*/
template<class ItemType>
void  binarytree<ItemType>::clear()
{

}

/*
	ItemType getEntry(const ItemType & anEntry) const
	Precondition: N/A
	Postcondition: will look for a particular entry
*/
template<class ItemType>
ItemType  binarytree<ItemType>::getEntry(const ItemType & anEntry) const
{
	
}


template<class ItemType>
void  binarytree<ItemType>::postorderTraverse(void visit(ItemType &)) const
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
treenode<ItemType> binarytree::*copyTree(const treenode<ItemType> *treePtr) const
{
	treeNode<ItemType>* newTreePtr = NULL;

	if (treePtr != NULL)
	{
		newTreePtr = new treenode<ItemType>(treePtr->getItem())
		newTreePtr->setLeftChildPtr(copyTree(treePtr->getLeftChildPtr()));
		newTreePtr->setRightChildPtr(copyTree(treePtr->getRightChildPtr()));
	}

	return newTreePtr;
}

/*
	int getHeightHelper(treenode<ItemType>* subtreePtr)
	Precondition: N/A
	Postconditon: Finds the maximum height of the tree and then returns it.
*/
template<class ItemType>
int getHeightHelper(treenode < ItemType > *subTreePtr) const
{
	if (subTreePtr == NULL)
		return 0;
	else
		return 1 + max(getHeightHelpt(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
}

