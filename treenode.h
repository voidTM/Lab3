#pragma
#ifndef TREE_NODE
#define TREE_NODE

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

template<class Type>
class treenode
{
private:
	Type data;
	int height;
	int lHeight;
	int rHeight;
	treenode<Type> *rChildPtr;
	treenode<Type> *lChildPtr;
public:
	//Constructor
	treenode();
	treenode(const Type item);
	treenode(const Type item, treenode<Type> *leftPtr, treenode<Type> *rightPtr);
	//Destructor
	//Method
	void setItem(const Type anItem);
	Type getItem() const;
	bool isLeaf() const;
	treenode<Type> *getLeftPtr();
	treenode<Type> *getRightPtr();
	void setLeftChildPtr(treenode<Type> *leftPtr);
	void setRightChildPtr(treenode<Type> *rightPtr);
};
/*
treenode()
Precondition: N/A
Postcondition: It initiallizes an empty tree node.
*/
template<class Type>
treenode<Type>::treenode()
{
	rChildPtr = NULL;
	lChildPtr = NULL;
}
/*
treenode(Type item)
Precondition: N/A
Postcondition: initializes a tree node with data but points to NULL.
*/
template<class Type>
treenode<Type>::treenode(Type item)
{
	data = item;
	rChildPtr = NULL;
	lChildPtr = NULL;
}
/*
treenode(Type item, treenode<Type> *leftPtr, treenode<Type> *rightPtr)
Precondition: N/A
Postcondition: It initiallizes a tree that contains data and points to two other nodes.
*/
template<class Type>
treenode<Type>::treenode(Type item, treenode<Type> *leftPtr, treenode<Type> *rightPtr)
{
	data = item;
	rChildPtr = leftPtr;
	lChildPtr = rightPtr;
}
/*
void setItem(Type anItem)
Precondition: anItem should be of valid data type.
Postcondition: sets data to the same value as anItem.
*/
template<class Type>
void treenode<Type>::setItem(Type anItem)
{
	data = anItem;
}
/*
Type getItem()
Precondition: data must already contain some value;
Postcondition: Returns the value stored in data
*/
template<class Type>
Type treenode<Type>::getItem() const
{
	return data;
}
/*
bool isLeaf()
Precondition: N/A
Postcondition: Checks to see if the particular tree node points to any other
tree node.
Returns true if the node doesnt point to anything.
Returns false if the node points to anything.
*/
template<class Type>
bool treenode<Type>::isLeaf() const
{
	if (rChildPtr == NULL && lChildPtr == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*
treenode<Type> *getLeftPtr()
Preconditon: N/A
Postcondition: returns the address to the left branch
*/
template<class Type>
treenode<Type>* treenode<Type>:: getLeftPtr() 
{
	return lChildPtr;
}
/*
treenode<Type> *getRightPtr()
Preconditon: N/A
Postcondition: returns the address to the right branch
*/
template<class Type>
treenode<Type>* treenode<Type>:: getRightPtr() 
{
	return rChildPtr;
}
/*
void setLeftChildPtr
Precondition: N/A
PostCondition: Sets lChildPtr to point at the same data
as leftPtr
*/
template<class Type>
void treenode<Type>::setLeftChildPtr(treenode<Type> *leftPtr)
{
	lChildPtr = leftPtr;
}
/*
void setLeftChildPtr
Precondition: N/A
PostCondition: Sets rChildPtr to point at the same data
as rightPtr
*/
template<class Type>
void treenode<Type>::setRightChildPtr(treenode<Type> *rightPtr)
{
	rChildPtr = rightPtr;
}

#endif