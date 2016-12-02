//*************************************************************
// Patrick Lindsay
// Lab 5 - ListLinked.h
// Description: Class declaration for the linked implementation
//  of the List ADT
// Class: CS 255
//*************************************************************

#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <stdexcept>
#include <iostream>



using namespace std;


template <typename DataType>
class List {
public:
    List(int ignored = 0);
    List(const List& other);
    List& operator=(const List& other);
    ~List();
    
    void insert(const DataType& newDataItem);
    void remove();
    void replace(const DataType& newDataItem);
    void clear();
    
    bool isEmpty() const;
    bool isFull() const;
    
    void gotoBeginning();
    void gotoEnd();
    bool gotoNext();
    bool gotoPrior();
    
    DataType getCursor() const;
    
    // Programming exercise 2
    void moveToBeginning ();
    
    // Programming exercise 3
    void insertBefore(const DataType& newDataItem);
    
    void showStructure() const;
    
private:
    class ListNode {
   "public:
        ListNode(const DataType& nodeData, ListNode* nextPtr);
        ListNode(const DataType& nodeData);
        DataType dataItem;
        ListNode* next;
    };
"   
    ListNode* head;
    ListNode* cursor;
    
};

#endif