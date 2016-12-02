//********************************************************************
//Name: Chad Farley, Alla Salah, Patrick Lindsay
//Class: CS 255
//Project: Lab 9
//BSTree.cpp
//********************************************************************

#include "BSTree.h"

template <typename DataType, class KeyType>
BSTree <DataType,KeyType>::BSTreeNode::BSTreeNode( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr ){
		dataItem = nodeDataItem;
		left = leftPtr;
		right = rightPtr;
}

template <typename DataType, class KeyType>
BSTree <DataType,KeyType>::BSTree(){
		root = NULL;
}

template <typename DataType, class KeyType>
BSTree <DataType,KeyType>::BSTree(const BSTree<DataType,KeyType>& other){
		if(root)
			setEqualHelp(root, other);
}

template <typename DataType, class KeyType>
BSTree <DataType,KeyType>& BSTree<DataType,KeyType>::operator=(const BSTree<DataType,KeyType>& other){
		//gonna be the same as copy constructor, more or less
	if(root){
		destructHelp(root);
		return setEqualHelp(root,other);
	}
	else
		root = NULL;
}

template <typename DataType, class KeyType>
BSTree <DataType,KeyType>& BSTree <DataType,KeyType>::setEqualHelp(BSTreeNode* copyTo, BSTreeNode* copyFrom){
	cout << "copy constructor" << endl;
		//set root
		copyTo->dataItem = copyFrom->dataItem;
		//go to left
		if(copyTo->left)
			setEqualHelp(copyTo->left, copyFrom->left);
		//go to right
		if(copyTo->right)
			setEqualHelp(copyTo-right, copyFrom->right);

		return copyTo;
		
}

template <typename DataType, class KeyType>
BSTree <DataType,KeyType>::~BSTree (){
	if(root)
		destructHelp(root);
}

template <typename DataType, class KeyType>
void BSTree <DataType,KeyType>::destructHelp(BSTreeNode* b){
	
	//processing left child
		if(b->left)
			destructHelp(b->left);
	//processing right child
		if(b->right)
			destructHelp(b->right);
	//delete root when no more children
		this->remove(b->dataItem.getKey());
}

template <typename DataType, class KeyType>
void BSTree <DataType,KeyType>::insert ( const DataType& newDataItem ){  // Insert data item
		
			insertHelp(newDataItem, root);
}

//------------------------------------------------------------------------------------------
// NOTE ! 
// In the case that we find a duplicate key, we simply changed the code to update the node.
//------------------------------------------------------------------------------------------

template <typename DataType, class KeyType>
void BSTree <DataType,KeyType>::insertHelp(const DataType& newDataItem, BSTreeNode*& b){
	
	if(b==NULL)
		b = new BSTreeNode(newDataItem, NULL, NULL);	
	else{
		KeyType testKey = b->dataItem.getKey();
		if (newDataItem.getKey() < testKey){
			insertHelp(newDataItem, b->left);
		}
		else if(newDataItem.getKey() > testKey)
			insertHelp(newDataItem, b->right);
		else{
			b->dataItem= newDataItem; //updates duplicate
		}	
	}	
}

template <typename DataType, class KeyType>
bool BSTree <DataType,KeyType>::retrieve ( const KeyType& searchKey, DataType& searchDataItem ) const{

			return retrieveHelp(searchKey, searchDataItem, root);
}

template <typename DataType, class KeyType>
bool BSTree <DataType,KeyType>::retrieveHelp(const KeyType& searchKey, DataType& searchDataItem, BSTreeNode* b)const{
		bool success = true;
		if(b->dataItem.getKey() != searchKey){
			if(b->left!=NULL && searchKey < b->dataItem.getKey())
				success = retrieveHelp(searchKey, searchDataItem, b->left);
			else if(b->right != NULL && searchKey > b->dataItem.getKey())
				success = retrieveHelp(searchKey, searchDataItem, b->right);
			else{
				cout << "Search data not found." << endl;
				success = false;
			}
		}
		else if(b->dataItem.getKey() == searchKey){
			searchDataItem = b->dataItem;
			success = true;
		}

		return success;
		

}

template <typename DataType, class KeyType>          // Retrieve data item
bool BSTree <DataType,KeyType>::remove ( const KeyType& deleteKey ){            // Remove data item
		return removeHelp(deleteKey, root);
}

template <typename DataType, class KeyType>
bool BSTree <DataType,KeyType>::removeHelp(const KeyType& deleteKey, BSTreeNode*& b){
		bool success = false;
		if(b){
			if(deleteKey < b->dataItem.getKey())
				return removeHelp(deleteKey, b->left);
			else if(deleteKey > b->dataItem.getKey())
				return removeHelp(deleteKey, b->right);
			else if(deleteKey==b->dataItem.getKey()){
				//no children
				if(!b->left && !b->right){
					BSTreeNode* temp = b;
					b = NULL;
					delete temp;
					success = true;
				}
				//no left, yes right
				else if(!b->left && b->right){
					BSTreeNode* temp = b;
					b= b->right;
					delete temp;
					success=true;
				}
				//yes left, no right
				else if(b->left && !b->right){
					BSTreeNode* temp = b;
					b = b->left;
					delete temp;
					success=true;
				}
				//two children
				else if(b->left && b->right){
					BSTreeNode* temp = b->right;

					while(temp->left)
						temp = temp->left;
					b->dataItem = temp->dataItem;
					return removeHelp(temp->dataItem.getKey(), b->right);
				}
			}
		}

		return success;
}

template <typename DataType, typename KeyType>
void BSTree <DataType,KeyType>::writeKeys () const{                      // Output keys
		if(root)
			writeKeysHelp(root);
}

template <typename DataType, typename KeyType>
void BSTree <DataType,KeyType>::writeKeysHelp(BSTreeNode* b)const{
		if(b->left)
			writeKeysHelp(b->left);
		cout << b->dataItem.getKey() << "\t";

		if(b->right)
			writeKeysHelp(b->right);
}

template <typename DataType, typename KeyType>
void BSTree <DataType,KeyType>::clear (){                                // Clear tree
		if(root)
			destructHelp(root);
}

// Binary search tree status operations
template <typename DataType, typename KeyType>
bool BSTree <DataType,KeyType>::isEmpty () const{                        // Tree is empty
		if(root)
			return false;
		else
			return true;
}
// !! isFull() has been retired. Not very useful in a linked structure.

// Output the tree structure -- used in testing/debugging
template < typename DataType, typename KeyType >
void BSTree <DataType,KeyType>:: showStructure () const

// Outputs the keys in a binary search tree. The tree is output
// rotated counterclockwise 90 degrees from its conventional
// orientation using a "reverse" inorder traversal. This operation is
// intended for testing and debugging purposes only.

{
    if ( root == 0 )
       cout << "Empty tree" << endl;
    else
    {
       cout << endl;
       showHelper(root,1);
       cout << endl;
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

template < typename DataType, typename KeyType >
void BSTree <DataType,KeyType>:: showHelper ( BSTreeNode *p, int level)const{

// Recursive helper for showStructure. 
// Outputs the subtree whose root node is pointed to by p. 
// Parameter level is the level of this node within the tree.


     int j;   // Loop counter

     if ( p != 0 )
     {
        showHelper(p->right,level+1);         // Output right subtree
        for ( j = 0 ; j < level ; j++ )    // Tab over to level
            cout << "\t";
        cout << " " << p->dataItem;   // Output key
        if ( ( p->left != 0 ) &&           // Output "connector"
             ( p->right != 0 ) )
           cout << "<";
        else if ( p->right != 0 )
           cout << "/";
        else if ( p->left != 0 )
           cout << "\\";
        cout << endl;
        showHelper(p->left,level+1);          // Output left subtree
    }
}

// In-lab operations
template <typename DataType, class KeyType>
int BSTree< DataType,KeyType>::getHeight () const{                       // Height of tree
		int height=0;
		int max=0;
		if(root)
			heightHelp(root, height, max);
		return max;
}

template <typename DataType, class KeyType>
void BSTree<DataType,KeyType>::heightHelp(BSTreeNode* b, int height, int& max)const{
	height++;
	if(b->left)
			heightHelp(b->left, height, max);
	if(b->right)
			heightHelp(b->right, height, max);
		if(height>max)
			max=height;
			
}

template <typename DataType, class KeyType>
int BSTree<DataType,KeyType>::getCount () const{  		  // Number of nodes in tree
	int count=0;
	if(root)
		countHelper(root, count);
	return count;

}

template <typename DataType, class KeyType>
void BSTree <DataType,KeyType>::countHelper(BSTreeNode* b, int& count)const{
		count++;
		if(b->left)
			countHelper(b->left, count);
		if(b->right)
			countHelper(b->right, count);
}
template <typename DataType, class KeyType>
void BSTree <DataType,KeyType>::writeLessThan ( const KeyType& searchKey ) const{ // Output keys < searchKey
	if(root){
			if(root->dataItem > searchKey)
				writeLessHelper(searchKey, root->left);
			else
				writeLessHelper(searchKey, root);
	}
}

template <typename DataType, class KeyType>
void BSTree <DataType,KeyType>::writeLessHelper(const KeyType& searchKey, BSTreeNode* b)const{
		if(b->left)
			writeLessHelper(searchKey, b->left);

		if(b->dataItem < searchKey)
		cout << b->dataItem << "\t";

		if(b->right)
			writeLessHelper(searchKey, b->right);
}