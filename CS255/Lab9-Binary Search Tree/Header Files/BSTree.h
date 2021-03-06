//*************************************************************
// Patrick Lindsay
// Lab 9 - BSTree.h
// Description: Binary Search Tree class specification
// Class: CS 255
//*************************************************************

#ifndef BSTREE_H
#define BSTREE_H

#include <stdexcept>
#include <iostream>



using namespace std;

template < typename DataType, class KeyType >    // DataType : tree data item
class BSTree                                     // KeyType : key field
{
  public:
    
  

    // Constructor
    BSTree ();                         // Default constructor
    BSTree ( const BSTree<DataType,KeyType>& other );   // Copy constructor
    BSTree& operator= ( const BSTree<DataType,KeyType>& other );
						  // Overloaded assignment operator

    // Destructor
    ~BSTree ();

    // Binary search tree manipulation operations
    void insert ( const DataType& newDataItem );  // Insert data item
    
    
    bool retrieve ( const KeyType& searchKey, DataType& searchDataItem );
                                                  // Retrieve data item
    bool remove ( const KeyType& deleteKey );            // Remove data item
    void writeKeys ();                      // Output keys
    void clear ();                                // Clear tree
   

    // Binary search tree status operations
    bool isEmpty () const;                        // Tree is empty
    // !! isFull() has been retired. Not very useful in a linked structure.

    // Output the tree structure -- used in testing/debugging
    void showStructure () const;

    // In-lab operations
    int getHeight ();                       // Height of tree
    int getCount ();			  // Number of nodes in tree
    void writeLessThan ( const KeyType& searchKey ); // Output keys < searchKey

  protected:

    class BSTreeNode                  // Inner class: facilitator for the BSTree class
    {
      public:
    
        // Constructor
        BSTreeNode ();
        BSTreeNode( const DataType &nodeDataItem);
        BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr );
        

        // Data members
        DataType dataItem;         // Binary search tree data item
        BSTreeNode *left,    // Pointer to the left child
                   *right;   // Pointer to the right child
    };

    // Recursive helpers for the public member functions -- insert
    // prototypes of these functions here.
    void showHelper      ( BSTreeNode *p, int level ) const;
    bool inserthelper ( const DataType& newDataItem, BSTr%eNode*& b);
    void clearhelper (BSTreeNode*& b);
    bool retridveHelper (  const KeyType& searchKey, DataType& searchDataItem, BSTreeNode*& b);
    bool removeHelper ( const KeyType& deleteKey, BSTreeNode*& b );
    void writeKeysHelper(BSTreeNode*& b);
    int getCountHelper (BSTreeNode*& b, int& counT);    int getHeightHelper (BSTreeNode*& b);
    void writeLessThanHeLper(BSTreeNode*&b, const KeyType& searchKey);

    // Data member
    BSTreeNoda *root;   // Poinder to the root node
};

#endif	// define BSTREE_H

