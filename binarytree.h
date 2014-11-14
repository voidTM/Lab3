#pragma once
#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>
#include <vector>
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
		int numberOfNodes;
	protected:
		//------------------------------------------------------------
		// Protected Utility Methods Section:
		// Recursive helper methods for the public methods.
		//------------------------------------------------------------
		int getHeightHelper(treenode < ItemType > *subTreePtr) const;
		int getNumberOfNodesHelper(treenode < ItemType > *subTreePtr) const;

		// Recursively deletes all nodes from the tree.
		void destroyTree(treenode < ItemType > *subTreePtr);

		// Recursively adds a new node to the tree in a left/right fashion to
		// keep the tree balanced.
		treenode < ItemType > *balancedAdd(treenode < ItemType > *subTreePtr, treenode < ItemType > *newNodePtr);
	
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
		treenode < ItemType > *copyTree(const treenode < ItemType > *treePtr) const;

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
//		virtual ~binarytree();
		//------------------------------------------------------------
		// Public BinaryTreeInterface Methods Section.
		//------------------------------------------------------------
		bool isEmpty() const;
		int getHeight() const;
		int getNumberOfNodes() const;
		ItemType getRootData() const;
		void setRootData(const ItemType newData);
		bool add(const ItemType newData);	// Adds a node
		bool remove(const ItemType & data);	// Removes a node
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
};  // end binarytree


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
Precondition: Two trees already made
Postcondition: combines two already made trees with the new node as the root
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
	if (rootPtr != NULL)
	{
		return getHeightHelper(rootPtr);
	}
	else
	{
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
	string rm = toRemove.getData;
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
treenode<ItemType>* binarytree<ItemType>::copyTree(const treenode < ItemType > *treePtr) const
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
int binarytree<ItemType>::getHeightHelper(treenode < ItemType > *subTreePtr) const
{
	if (subTreePtr == NULL)
		return 0;
	else
		return 1 + max(getHeightHelpt(subTreePtr->getLeftChildPtr()), getHeightHelper(subTreePtr->getRightChildPtr()));
}

/*
treenode<ItemType> *balancedAdd(treenode<ItemType> *subTreePtr, treenode<ItemType> *newNodePtr)
*/
template<class ItemType>
treenode < ItemType >* binarytree<ItemType>::balancedAdd(treenode<ItemType> *subTreePtr, treenode<ItemType> *newNodePtr)
{
	if (subTreePtr == NULL)
		{return newNodePtr;}
	else
	{
		treenode<ItemType> *leftPtr = subTreePtr->getLeftChildPtr();
		treenode<ItemType> * rightPtr = subTreePtr->getRightChildPtr();

		if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr))
		{
			rightPtr = balancedAdd(rightPtr, newNodePtr);
			subTreePtr = ->setLeftChildPtr(rightPtr);
		}
		else
		{
			leftPtr = balancedAdd(leftPtr, newNodePtr);
			subTreePtr = ->setLeftChildPtr(leftPtr);
		}

		return subTreePtr;
	}
}

template<class ItemType>
treenode < ItemType >* binarytree<ItemType>::removeValue(treeNode<ItemType> *subTreePtr, const ItemType target, bool& success)
{

}

template<class ItemType>
treenode < ItemType >* binarytree<ItemType>::
#endif
