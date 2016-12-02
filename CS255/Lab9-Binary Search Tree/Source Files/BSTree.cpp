//*************************************************************
// Patrick Lindsay
// Lab 9 - BSTree.cpp
// Description: Binary Search Tree implemenation
// Class: CS 255
//*************************************************************

#include "BSTree.h"
#include <iostream>
#include <cmath>


using namespace std;


//*************************************************************
//Function Name: BSTree
//Requirements: None
//Description: Default constructor. Creates an empty binary
//  search tree
//*************************************************************
template < typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTree (){
    root = NULL;
}

//*************************************************************
//Function Name: BSTree
//Requirements: None
//Description: Copy constructor. Initializes the binary search
//  tree to be equivalent to the other BSTree object parameter
//*************************************************************
template < typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTree( const BSTree<DataType,KeyType>& other ){
    if (!other.root){ root = NULL; return;}
	root = new BSTreeNode(other.root->dataItem);
    
    if (other.root->left) {
        BSTree(other.root->left);
    }
    if (other.root->right) {
        BSTree(other.root->right);
    }
}

//*************************************************************
//Function Name: operator=
//Requirements: None
//Description: Overloaded assignment operator. Sets the binary
//  search tree to be equivalent to the other BSTree object
//  parameter and returns a reference to this object.
//*************************************************************
template < typename DataType, class KeyType>
BSTree<DataType, KeyType>& BSTree<DataType, KeyType>::operator= ( const BSTree<DataType,KeyType>& other ){
    // makes sure something is not being set equal to itself
    if (other.root == root)
		return *this;
	this->~BSTree();
    
	if (!other.root){root = NULL; return *this;}
	root = new BSTreeNode(other.root->dataItem);
    
    if (other.root->left) {
        BSTree(other.root->left);
    }
    if (other.root->right) {
        BSTree(other.root->right);
    }
    return *this;
}

//*************************************************************
//Function Name: ~BSTree
//Requirements: None
//Description: Destructor. Deallocates the memory used to store
//  the binary search tree.
//*************************************************************
template < typename DataType, class KeyType>
BSTree<DataType, KeyType>::~BSTree (){
    clear();
    delete root;
}


//************************************************************
// Binary search tree manipulation operations
//************************************************************


//*************************************************************
//Function Name: insert
//Requirements: None
//Description: Inserts newDataItem into the binary search tree.
//  If a data item with the same key as newDataItem already
//  exists in the tree, then updates that data item with
//  newDataItem.
//*************************************************************
template < typename DataType, class KeyType>
void BSTree<DataType, KeyType>::insert ( const DataType& newDataItem ){
		return inserthelper(newDataItem, root);
}



//*************************************************************
//Function Name: inserthelper
//Requirements: None
//Description: Helps insert fulfill its function description
//*************************************************************
template < typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::inserthelper ( const DataType& newDataItem, BSTreeNode*& b){
    bool success = true;
    
	if (b != NULL){
        //Checks for a need to traverse left
		if (newDataItem.getKey() < b->dataItem.getKey())
			success = inserthelper(newDataItem, b->left);
        //Checks for a need to traverse right
		else if( newDataItem.getKey() > b->dataItem.getKey())
			success = inserthelper(newDataItem, b->right);
        //Checks for equal keys
		else if(newDataItem.getKey()==b->dataItem.getKey()){
			b->dataItem = newDataItem;
			success = true;
		}	
	}
	else {
        b = new BSTreeNode(newDataItem);
    }
	return success;
}


//*************************************************************
//Function Name: retrieve
//Requirements: None
//Description: Searches the binary search tree for the data item
//  with the key searchKey. If this data item is found, then copies
//  the data item to searchDataItem and returns true. Otherwise,
//  returns false with searchDataItem undefined.
//*************************************************************
template < typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::retrieve ( const KeyType& searchKey, DataType& searchDataItem ){
	bool success1= false;
	success1=retrieveHelper( searchKey, searchDataItem, root);
	return success1;
}

//*************************************************************
//Function Name: retrieveHelper
//Requirements: None
//Description: Helps retrieve perform its job
//*************************************************************
template<typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::retrieveHelper( const KeyType& searchKey, DataType& searchDataItem, BSTreeNode*& b){
	bool success=false;
	if(b){
        //Checks for a need to traverse right
		if(searchKey > b->dataItem.getKey()&&success==false)
			success=retrieveHelper(searchKey, searchDataItem, b->right);
        //Checks for a need to traverse left
		else if(searchKey < b->dataItem.getKey()&&success==false)
			success=retrieveHelper(searchKey, searchDataItem, b->left);
        //Checks for equal keys
		else if(searchKey==b->dataItem.getKey()&&success==false){
			searchDataItem=b->dataItem;
			success=true;
		}
		else if(searchKey!=b->dataItem.getKey()&&success==false){
			success=false;
		}
	}
	return success;
}

//*************************************************************
//Function Name: remove
//Requirements: None
//Description: Deletes the data item with key deleteKey from
//  the binary search tree. If this data item is found, then
//  deletes it from the tree and returns true. Otherwise, returns
//  false.
//*************************************************************
template < typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::remove ( const KeyType& deleteKey ){
    if (root)
		return removeHelper(deleteKey, root);
}


//*************************************************************
//Function Name: removeHelper
//Requirements: None
//Description: helps remove to its job
//*************************************************************
template < typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::removeHelper ( const KeyType& deleteKey, BSTreeNode*& b ){
    bool success = false;
    if (b) {
            // Checks for a need to traverse right
            if(deleteKey > b->dataItem.getKey()&&success==false)
                success=removeHelper(deleteKey, b->right);
            // Checks for a need to traverse left
            else if(deleteKey < b->dataItem.getKey()&&success==false)
                success=removeHelper(deleteKey, b->left);
            // Checks for key equality
            else if(deleteKey==b->dataItem.getKey()&&success==false){
                success = true;
                // If no children
                if (!b->left && !b->right){
                    BSTreeNode* temp = b;
                    b = NULL;
                    delete temp;
                }
                // If right child but no left
                else if (!b->left && b->right){
                    BSTreeNode* temp = b;
                    b=b->right;
                    delete temp;
                }
                // If left child but no right
                else if (b->left && !b->right){
                    BSTreeNode* temp = b;
                    b=b->left;
                    delete temp;
                }
                // If both children exist
                else if (b->left && b->right){
                    BSTreeNode* temp = b;
                    BSTreeNode* traverser = b->right;
                    while (traverser->left != NULL) {
                        traverser = traverser->left;
                    }
                    traverser->left = b->left;
                    b = b->right;
                    delete temp;
                    traverser = NULL;
                }
            }
            else if(deleteKey != b->dataItem.getKey() && success==false){
                success=false;
            }
        }
        return success;
}

//*************************************************************
//Function Name: writeKeys
//Requirements: None
//Description: Outputs the keys of the data items in the binary
//  search tree. The keys are output in ascending order on one
//  line, separated by spaces.
//*************************************************************
template < typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeKeys () {
    writeKeysHelper(root);
	cout<<endl;
}


//*************************************************************
//Function Name: writeKeysHelper
//Requirements: None
//Description: helps writeKeys do its job
//*************************************************************
template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeKeysHelper(BSTreeNode*& b){
	
    //Uses a left, root, right traversal
    if(b->left)
		writeKeysHelper(b->left);
	cout<<b->dataItem.getKey()<<"\t";
	if(b->right)
		writeKeysHelper(b->right);
}

//*************************************************************
//Function Name: clear
//Requirements: None
//Description: Removes all the data items in the binary search
//  tree.
//*************************************************************
template < typename DataType, class KeyType>
void BSTree<DataType, KeyType>::clear (){
    if (root)
        clearhelper(root);
    root = NULL;
    
}

//*************************************************************
//Function Name: clearhelper
//Requirements: None
//Description: helps clear do its job
//*************************************************************
template < typename DataType, class KeyType>
void BSTree<DataType, KeyType>::clearhelper (BSTreeNode*& b){
    if (b->left) {
        clearhelper(b->left);
    }
    if (b->right) {
        clearhelper(b->right);
    }
    delete b; 
}

//*************************************************************
//Function Name: isEmpty
//Requirements: None
//Description: Returns true if the binary search tree is empty.
//  Otherwise, returns false.
//*************************************************************
template < typename DataType, class KeyType>
bool BSTree<DataType, KeyType>::isEmpty () const{
    return (root == NULL);
}



//*************************************************************
//Function Name: showStructure
//Requirements: None
//Description: Output the tree structure, used in 
//  testing/debugging
//*************************************************************
template < typename DataType, class KeyType>
void BSTree<DataType, KeyType>::showStructure () const{
    if ( root == NULL )
        cout << "Empty tree" << endl;
    else
    {
        cout << endl;
        showHelper(root,1);
        cout << endl;
    }
}

//*************************************************************
//Function Name: showHelper
//Requirements: None
//Description: helps showStructure do its job
//*************************************************************
template < typename DataType, typename KeyType >
void BSTree<DataType,KeyType>:: showHelper ( BSTreeNode *p,
                                            int level             ) const
{
    int j;   // Loop counter
    
    if ( p != 0 )
    {
        showHelper(p->right,level+1);         // Output right subtree
        for ( j = 0 ; j < level ; j++ )    // Tab over to level
            cout << "\t";
        cout << " " << p->dataItem.getKey();   // Output key
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

//*************************************************************
//Function Name: getHeight
//Requirements: None
//Description: Returns the height of the binary search tree
//*************************************************************
template < typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getHeight (){
    int height = 0;
    height = getHeightHelper(root);
    return height;
}// Height of tree


//*************************************************************
//Function Name: getHeightHelper
//Requirements: None
//Description: helps getHeight do its job
//*************************************************************
template < typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getHeightHelper (BSTreeNode*& b){
    int left = 0;
    int right = 0;
    
    if(b == NULL)
        return 0;
    {
        left = getHeightHelper(b->left);
        right = getHeightHelper(b->right);
        if( left > right || left == right)
            return (left + 1);
        else
            return (right + 1);
    }
}


//*************************************************************
//Function Name: getCount
//Requirements: None
//Description: Returns the count of the number of data items
//  in the binary search tree.
//*************************************************************
template < typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getCount (){
    int count = 0;
    count = getCountHelper(root, count);
    return count;
}// Number of nodes in tree


//*************************************************************
//Function Name: getCountHelper
//Requirements: None
//Description: helps getCount do its job
//*************************************************************
template < typename DataType, class KeyType>
int BSTree<DataType, KeyType>::getCountHelper (BSTreeNode*& b, int& count){
    if(b->left)
		getCountHelper(b->left, count);
	count++;
	if(b->right)
		getCountHelper(b->right, count);
    return count;
}

//*************************************************************
//Fuoction Name: writeLessThan
//Requirements: None
//Description: Outputs all keys in a binary search tree that
//  are less than searchKey. The Keys are ouput in ascending
//  order using the same normat aó writeKeys. Note that 
//  searchKey need not be a key in the tree.
//*************************************************************
template < typenamu DataType, class KeyType>void BSTree<DataType, KeyType>::writeLessThan ( const KeyType& searchKey ){
    writeLessThanHelper(root, searchKey);
	cout<<endl;
}// Output keys < searchKey


//*************************************************************
//Function Name: writeLessThanHelper
//Requirements: None
//Description: helps writeLessThan do its job
//*************************************************************
template<typename DataType, class KeyType>
void BSTree<DataType, KeyType>::writeLessThanHelper(BSTreeNode*&b, const KeyType& searchKey)
{
	if(b->left)
		writeLessThanHelper(b->left, searchKey);
	if(b->dataItem.getKey()<searchKey)
		cout<<b->dataItem.getKey()<<"\t";
	if(b->right)
		writeLessThanHelper(b->right, searchKey);    
}// Output keys < searchKey


//*************************************************************
//Function Name: BSTreeNode
//Requirements: None
//Description: Constructor. Creates a new binary search tree node
//  Sets left and right to NULL.
//*************************************************************
template < typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode (){
    left = right = NULL;
}

//*************************************************************
//Function Name: BSTreeNode
//Requirements: None
//Description: Constructor. Creates a new binary search tree 
//  node. Sets dataItem to nodeDataItem and left and right to
//  NULL.
//*************************************************************
template < typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode( const DataType &nodeDataItem){
    dataItem = nodeDataItem;
    left = right = NULL;
}


//*************************************************************
//Function Name: BSTreeNode
//Requirements: None
//Description: Constructor. Creates a new binary search tree 
//  node. Sets dataItem to nodeDataItem. Sets left to leftPtr.
//  Sets right to rightPtr.
//*************************************************************
template < typename DataType, class KeyType>
BSTree<DataType, KeyType>::BSTreeNode::BSTreeNode ( const DataType &nodeDataItem, BSTreeNode *leftPtr, BSTreeNode *rightPtr ){
    dataItem = nodeDataItem;
    left = leftPtr;
    right = rightPtr;
}


//--------------------------------------------------------------------
//
//  Laboratory 9                                         test9.cpp
//
//  Test program for the operations in the Binary Search Tree ADT
//
//--------------------------------------------------------------------

using namespace std;


#include "config.h"


void print_help();

//--------------------------------------------------------------------
// Declaration for the binary search tree data item class
//--------------------------------------------------------------------

class TestData
{
public:
    
    void setKey ( int newKey )
    { keyField = newKey; }   // Set the key
    
    int getKey () const
    { return keyField; }     // Returns the key
    
private:
    
    int keyField;                // Key for the data item
};

int main()
{
    BSTree<TestData,int> testTree;   // Test binary search tree
    TestData testData;               // Binary search tree data item
    int inputKey;                    // User input key
    char cmd;                        // Input command
    
    
    print_help();
    
    do
    {
        testTree.showStructure();                     // Output tree
        
        cout << endl << "Command: ";                  // Read command
        cin >> cmd;
        if ( cmd == '+'  ||  cmd == '?'  ||
            cmd == '-'  ||  cmd == '<'     )
            cin >> inputKey;
        
        switch ( cmd )
        {
            case 'P' : case 'p' :
                print_help();
                break; 
                
            case '+' :                                  // insert
                testData.setKey(inputKey);
                cout << "Insert : key = " << testData.getKey()
                << endl;
                testTree.insert(testData);
                break;
                
            case '?' :                                  // retrieve
                if ( testTree.retrieve(inputKey,testData) )
                    cout << "Retrieved : getKey = "
                    << testData.getKey() << endl;
                else
                    cout << "Not found" << endl;
                break;
                
            case '-' :                                  // remove
                if ( testTree.remove(inputKey) )
                    cout << "Removed data item" << endl;
                else
                    cout << "Not found" << endl;
                break;
                
            case 'K' : case 'k' :                       // writeKeys
                cout << "Keys:" << endl;
                testTree.writeKeys();
                break;
                
            case 'C' : case 'c' :                       // clear
                cout << "Clear the tree" << endl;
                testTree.clear();
                break;
                
            case 'E' : case 'e' :                       // empty
                if ( testTree.isEmpty() )
                    cout << "Tree is empty" << endl;
                else
                    cout << "Tree is NOT empty" << endl;
                break;
                
#if   LAB9_TEST1
            case 'G' : case 'g' :                   // Programming Exercise 2
                cout << "Tree nodes count = " << testTree.getCount() << endl;
                break;
#endif	// LAB9_TEST1
                
#if   LAB9_TEST2
            case 'H' : case 'h' :                   // Programming Exercise 2
                cout << "Tree height = " << testTree.getHeight() << endl;
                break;
#endif	// LAB9_TEST2
                
#if   LAB9_TEST3
            case '<' :                              // Programming Exercise 3
                cout << "Keys < " << inputKey << " : " << endl;
                testTree.writeLessThan(inputKey);
                cout << endl;
                break;
#endif	// LAB9_TEST3
                
            case 'Q' : case 'q' :                   // Quit test program
                break;
                
            default :                               // Invalid command
                cout << "Inactive or invalid command. 'P' prints help." << endl;
        }
    }
    while ( cin && ( cmd != 'Q' ) && ( cmd != 'q' ) );
    
    if ( !cin ) {
        cerr << "Error in console input. Exiting." << endl;
    }
    
    return 0;
}

//--------------------------------------------------------------------

void print_help() {
    cout << endl << "Commands:" << endl;
    cout << "  P    : [P]rint Help (displays this message)" << endl;
    cout << "  +key : Insert (or update) data item (use integers)" << endl;
    cout << "  ?key : Retrieve data item" << endl;
    cout << "  -key : Remove data item" << endl;
    cout << "  K    : Write keys in ascending order" << endl;
    cout << "  C    : Clear the tree" << endl;
    cout << "  E    : Empty tree?" << endl;
    cout << "  G    : Get count of nodes          " 
#if LAB9_TEST1
    << "(Active   : " 
#else
    << "(Inactive : " 
#endif
    << "In-lab Exercise 2)" << endl;
    
    cout << "  H    : Height                      " 
#if LAB9_TEST2
    << "(Active   : " 
#else
    << "(Inactive : " 
#endif
    << "In-lab Exercise 2)" << endl;
    
    cout << "  <key : Write keys that are < key   " 
#if LAB9_TEST3
    << "(Active   : " 
#else
    << "(Inactive : " 
#endif
    << "In-lab Exercise 3)" << endl;
    cout << "  Q    : Quit the test program" << endl;
    cout << endl;
}



//IMPORTANT!!!!!!!!
// Uncomment the following and comment the above tester to run the program below!!!!
//IMPORTANT!!!!!!!

/*
//--------------------------------------------------------------------
//
//  Laboratory 11, In-lab Exercise 1                     database.cs
//
//  (Shell) Indexed accounts database program
//
//--------------------------------------------------------------------

// Builds a binary search tree index for the account records in the
// text file accounts.dat.

//#include <iostream>
#include <fstream>
//#include "BSTree.cpp"
#include <string>

using namespace std;

//--------------------------------------------------------------------
//
// Declarations specifying the accounts database
//

const int nameLength      = 11;   // Maximum number of characters in
//   a name
const long bytesPerRecord = 38;   // Number of bytes used to store
//   each record in the accounts
//   database file

struct AccountRecord
{
    int acctID;                   // Account identifier
    char firstName[nameLength],   // Name of account holder
    lastName[nameLength];
    double balance;               // Account balance
};

//--------------------------------------------------------------------
//
// Declaration specifying the database index
//

struct IndexEntry
{
    int acctID;              // (Key) Account identifier
    long recNum;             // Record number
    
    int getKey () const
    { return acctID; }   // Return key field
};

//--------------------------------------------------------------------

int main ()
{
    ifstream acctFile ("accounts.dat");   // Accounts database file
    AccountRecord acctRec;                // Account record
    BSTree<IndexEntry,int> index;         // Database index
    IndexEntry entry;                     // Index entry
    int searchID;                         // User input account ID
    long recNum;                          // Record number
    
    // Iterate through the database records. For each record, read the
    // account ID and add the (account ID, record number) pair to the
    // index.
    
    if ( !acctFile )
    {
        cout << "Error opening file " << endl;
    }
    else
    {
        string one;
        string two;
        int three;
        while (! acctFile.eof()) {
            acctFile >> entry.recNum >> entry.acctID >> one >> two >> three;
            index.insert(entry);
        }
        
    
    
    
    
    
    // Output the account IDs in ascending order.
        index.writeKeys();
    
    // Clear the status flags for the database file.
    
    acctFile.clear();
    
    // Read an account ID from the keyboard and output the
    // corresponding record.
    
        cout  << "Enter in the account ID for the record you wish to retrieve" << endl;
        cin >> searchID;
        
        while (! acctFile.eof()) {
            acctFile >> recNum >> acctRec.acctID >> acctRec.firstName >> acctRec.lastName >> acctRec.balance;
            if (searchID == acctRec.acctID) {
                cout << acctRec.acctID << endl;
                cout << acctRec.firstName << endl;
                cout << acctRec.lastName << endl;
                cout << acctRec.balance << endl;
            }
        }
        
    
    }
    return 0;
}
*/

