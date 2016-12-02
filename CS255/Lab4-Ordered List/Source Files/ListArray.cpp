//
//  ListArray.cpp
//  Project 3-List
//
//  Created by Patrick Lindsay and Chad  on 9/27/11.
//  Copyright 2011 University of North Alabama. All rights reserved.
//

#include "ListArray.h"

//**************************************************//
//Function Name: Default Constructor				//
//Return Type: Templated List						//
//Parameters: Int maxNumber							//
//Purpose: Creates an empty Templated List with		//
//		   maxSize of maxNumber.					//
//**************************************************//
template<typename DataType>
List<DataType>::List (int maxNumber){
	maxSize=maxNumber;
	size=0;
	cursor=0;
	dataItems=new DataType[size];
	for(int i=0; i<size; ++i)
		dataItems[i]=dataItems[NULL];
}

//**************************************************//
//Function Name: Copy Constructor					//
//Return Type: List									//
//Parameters: List& source							//
//Purpose: Creates a copy of List Source			//
//**************************************************//
template<typename DataType>
List<DataType>::List(const List& source){
	maxSize=source.maxSize;
	size=source.size;
	cursor=source.cursor;
	dataItems=new DataType[size];
	for(int i=0; i<size; ++i)
		dataItems[i]=source.dataItems[i];	
}

//**************************************************//
//Function Name: Overloading of Assignment Operator	//
//Return Type: List&								//
//Parameters: List& source							//
//Purpose: Allows programmer to set one list equal	//
//		   to another.								//
//**************************************************//
template<typename DataType>
List<DataType>& List<DataType>::operator=(const List<DataType>& source){
	for(int i=0; i<source.size; ++i)
		dataItems[i]=source.dataItems[i];
	return *this;
}

//**************************************************//
//Function Name: Destructor							//
//Return Type: List									//
//Parameters: [None]								//
//Purpose: Deletes all items in the calling list.	//
//**************************************************//
template<typename DataType>
List<DataType>::~List(){
	delete [] dataItems;
}

//**************************************************//
//Function Name: Insert								//
//Return Type: Void									//
//Parameters: DataType& newDataItem					//
//Purpose: Inserts newDataItem into the calling list//
//		   if the list is not full.
//**************************************************//
template<typename DataType>
void List<DataType>::insert(const DataType& newDataItem)throw(logic_error){
	if(isEmpty()){
		dataItems[cursor]=newDataItem;
		++size;
	}
	else if(isFull())
		throw logic_error("Error, full list.");
	else {
		++size;
		++cursor;
		for(int i=size; i>cursor; --i)
			dataItems[i]=dataItems[i-1];
		dataItems[cursor]=newDataItem;
	}
}

//**************************************************//
//Function Name: Remove								//
//Return Type: Void									//
//Parameters: [None]								//
//Purpose: Removes item at cursor and pushes list	//
//		   towards the beginning of the list.		//
//**************************************************//
template<typename DataType>
void List<DataType>::remove()throw(logic_error){
	if(isEmpty())
		throw(logic_error("Error, empty list."));
	else{
		dataItems[cursor]=dataItems[NULL];
		for(int i=cursor;i<size-1; ++i)
			dataItems[i]=dataItems[i+1];
		if(!gotoNext())
			cursor=0;
		else
			--cursor;
		--size;
	}
}

//**************************************************//
//Function Name: Replace							//
//Return Type: Void									//
//Parameters: DataType& newDataItem					//
//Purpose: Replaces dataItem at Cursor with 		//
//		   newDataItem.								//
//**************************************************//
template<typename DataType>
void List<DataType>::replace(const DataType& newDataItem)throw(logic_error){
	dataItems[cursor]= newDataItem;
}

//**************************************************//
//Function Name: Clear								//
//Return Type: Void									//
//Parameters: [None]								//
//Purpose: Sets all dataItems to NULL.				//
//**************************************************//
template<typename DataType>
void List<DataType>::clear(){
	for(int i=0; i<size; ++i)
		dataItems[i]=dataItems[NULL];
	size=0;
	cursor=0;
}

//**************************************************//
//Function Name: isEmpty							//
//Return Type: Bool									//
//Parameters: [None]								//
//Purpose: Checks to see if list is empty.			//
//**************************************************//
template<typename DataType>
bool List<DataType>::isEmpty()const{
	bool empty=false;
	if(size==0)
			empty=true;
	return empty;
}

//**************************************************//
//Function Name: isFull								//
//Return Type: Bool									//
//Parameters: [None]								//
//Purpose: Checks to see if calling list is full.	//
//**************************************************//
template<typename DataType>
bool List<DataType>::isFull()const{
	bool full=false;
	if(size==maxSize)
		full=true;
	return full;
}

//**************************************************//
//Function Name: goToBeginning						//
//Return Type: Void									//
//Parameters: [None]								//
//Purpose: Sets cursor to the beginning of the list.//
//**************************************************//
template<typename DataType>
void List<DataType>::gotoBeginning()throw(logic_error){
	cursor=0;
}

//**************************************************//
//Function Name: goToEnd							//
//Return Type: Void									//
//Parameters: [None]								//
//Purpose: Sets cursor to the end of the list.		//
//**************************************************//
template<typename DataType>
void List<DataType>::gotoEnd()throw(logic_error){
	cursor=size-1;
}

//**************************************************//
//Function Name: gotoNext							//
//Return Type:	Bool								//
//Parameters: [None]								//
//Purpose: Sets cursor to next item in the list.	//
//		   Returns false if cursor is at the end.	//
//**************************************************//
template<typename DataType>
bool List<DataType>::gotoNext()throw(logic_error){
	if(cursor==size-1)
		return false;
	if(cursor<size-1)
		++cursor;
	return true;
}

//******************************************************//
//Function Name: goToPrior								//
//Return Type: Bool										//
//Parameters: [None]									//
//Purpose: Sets cursor to prior item in the list.		//
//		   Returns false if cursor is at the beginning.	//
//******************************************************//
template<typename DataType>
bool List<DataType>::gotoPrior()throw(logic_error){
	if(cursor==0)
		return false;
	else
		--cursor;
	return true;
}

//**************************************************//
//Function Name: getCursor							//
//Return Type: DataType								//
//Parameters: [None]								//
//Purpose: Returns dataItem at the cursor.			//
//**************************************************//
template<typename DataType>
DataType List<DataType>::getCursor()const throw(logic_error){
	return dataItems[cursor];
}

//**************************************************//
//Function Name: getSize							//
//Return Type: Int									//
//Parameters: [None]								//
//Purpose: Returns the size of the calling list.	//
//**************************************************//
template<typename DataType>
int List<DataType>::getSize(){
	return size;
}

//**************************************************************************//
//Function Name: ShowStructure												//
//Return Type: Void															//
//Parameters: [None]														//
//Purpose: outputs the data items in a list. if the list is empty, outputs	//
// "empty list". this operation is intended for testing/debugging			//
// purposes only.															//
//**************************************************************************//
template <typename DataType>
void List<DataType>:: showStructure () const{
    int j;   // loop counter
	
    if ( size == 0 )
		cout << "empty list" << endl;
	// The Ordered List code blows up below. Since this is just debugging
	// code, we check for whether the OrderedList is defined, and if so,
	// print out the key value. If not, we try printing out the entire item.
	// Note: This assumes that you have used the double-inclusion protection
	// in your OrderedList.cpp file by doing a "#ifndef ORDEREDLIST_CPP", etc.
	// If not, you will need to comment out the code in the section under 
	// the "else", otherwise the compiler will go crazy in lab 4.
	// The alternative is to overload operator<< for all data types used in
	// the ordered list.
    else
    {
		cout << "size = " << size
		<<  "   cursor = " << cursor << endl;
		for ( j = 0 ; j < maxSize ; j++ )
			cout << j << "\t";
		cout << endl;
		for ( j = 0 ; j < size ; j++ ) {
			if( j == cursor ) {
				cout << "[";
				cout << dataItems[j]
#ifdef _ORDEREDLIST_CPP
				.getKey()
#endif
				;
				cout << "]";
				cout << "\t";
			}
			else
				cout << dataItems[j] 
#ifdef _ORDEREDLIST_CPP
				.getKey()
#endif
				<< "\t";
		}
		cout << endl;
    }
}

//**************************************************//
//Function Name: MoveToNth							//
//Return Type: Void									//
//Parameters: Int n									//
//Purpose: Moves cursor to position n.				//
//**************************************************//
template<typename DataType>
void List<DataType>::moveToNth(int n)throw(logic_error){
	DataType temp;
	if(n<0)
		throw logic_error("");
	if(size>=n+1){
		temp=dataItems[cursor];
		if(n>cursor)
			for(int i=cursor; i<n; ++i)
				dataItems[i]=dataItems[i+1];
		else if(n<cursor)
			for(int i=cursor; i>n; --i)
				dataItems[i]=dataItems[i-1];			
		dataItems[n]=temp;
		cursor=n;
	}
	else
		throw logic_error("");
}

//**************************************************//
//Function Name: Find								//
//Return Type: Bool									//
//Parameters: DataType& searchDataItem				//
//Purpose: Searches for dataItem searchDataItem.	//
//		   If found, sets cursor to it and returns	//
//		   true. Otherwise, returns false.			//
//**************************************************//
template<typename DataType>
bool List<DataType>::find(const DataType& searchDataItem)throw(logic_error){
	for(int i=cursor; i<size; ++i){
		cursor=i;
		if(dataItems[i]==searchDataItem)
			return true;
	}
	return false;
}
//#endif