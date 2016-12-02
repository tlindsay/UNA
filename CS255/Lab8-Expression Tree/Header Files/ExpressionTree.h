//--------------------------------------------------------------------
//
//  Laboratory 8                                     ExpressionTree.h
//
//  Class declarations for the linked implementation of the
//  Expression Tree ADT -- including the recursive helpers for the
//  public member functions
//
//  Instructor copy with the recursive helper function declarations.
//  The student version does not have those, but has a place to write
//  the declarations in the private section.
//
//--------------------------------------------------------------------

#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

template <typename DataType>
class ExprTree {
private:

    class ExprTreeNode {
      public:
        // Constructor
        ExprTreeNode ( char elem,
                       ExprTreeNode *leftPtr, ExprTreeNode *rightPtr );

        // Data members
        char dataItem;          // Expression tree data item
        ExprTreeNode *left,     // Pointer to the left child
                     *right;    // Pointer to the right child
    };

    // Recursive helper functions for the public member functions -- insert
    // prototypes of these functions here.

    // Data member
    ExprTreeNode *root;   // Pointer to the root node  
	void copyHelper(ExprTreeNode*& node1, ExprTreeNode*& node2);
	void buildHelper(ExprTreeNode*& head, string& input, int& index);
	void express_help (const ExprTreeNode* head, string& express) const;
	void clear_help(ExprTreeNode *root);
	void showHelper(ExprTreeNode *p, int level) const;
	void commuteHelper(ExprTreeNode*& head, ExprTreeNode*& new_root);
	void replace_old(ExprTreeNode *head, ExprTreeNode *new_root);
	void destructHelp(ExprTreeNode *head);
	string inFixTraversal(ExprTreeNode *head);
	void isEquiv_help(const ExprTreeNode *head, ExprTreeNode *copy, bool& flag)const;
#if LAB8_TEST1
	bool evaluate_helper(ExprTreeNode* head)const;
#endif
#if !LAB8_TEST1
	DataType evaluate_helper(ExprTreeNode* head, char op)const;
#endif
public:

    // Constructor
    ExprTree ();
    ExprTree(const ExprTree& source);

    ExprTree& operator=(const ExprTree& source);

    // Destructor
    ~ExprTree ();

    // Expression tree manipulation operations
    void build ();
    void expression () const;
	
    DataType evaluate() const;
    void clear ();              // Clear tree
    void commute();
    bool isEquivalent(const ExprTree& source) const;
	bool isEmpty()const;

    // Output the tree structure -- used in testing/debugging
    void showStructure () const;
};

#endif		// #ifndef EXPRESSIONTREE_H
