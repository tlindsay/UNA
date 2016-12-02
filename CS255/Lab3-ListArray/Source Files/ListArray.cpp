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
//Return Type: List									//
//Parameters: int maxNumber							//
//Purpose: Creates an empty list with a maxSize of  //
//		   maxNumber.								//
//**************************************************//
template<typename DataType>
List<DataType>::List (int maxNumber){
	maxSize=maxNumber;
	size=0;
	cursor=0;
	dataItems=new DataType[size];
	for(int i=0; i<size; ++i)
		dataItems[i]=NULL;
}

//**************************************************//
//Function Name: Copy Constructor					//
//Return Type: List									//
//Parameters: List& source							//
//Purpose: Creates of copy of the Source List		//
//**************************************************//
template<typename DataType>
List<DataType>::List(const List& source){
	maxSize=source.maxSize;
	size=source.size;
	cursor=0;
	dataItems=new DataType[size];
	for(int i=0; i<size; ++i)
		dataItems[i]=source.dataItems[i];	
}

//**************************************************//
//Function Name: Operator =							//
//Return Type: List									//
//Parameters: List<DataType>& source				//
//Purpose: Overloads the assignment operator		//
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
//Purpose: Destroys a list							//
//**************************************************//
template<typename DataType>
List<DataType>::~List(){
	delete [] dataItems;
}

//**************************************************//
//Function Name: Insert								//
//Return Type: Void									//
//Parameters: DataType& newDataItem					//
//Purpose: Inserts a new value of type DataType into//
//		   the list.								//
//**************************************************//
template<typename DataType>
void List<DataType>::insert(const DataType& newDataItem)throw(logic_error){
	if(isEmpty()){
		dataItems[cursor]=newDataItem;
		++size;
	}
	else if(isFull())
		throw logic_error("Error in Insert()\n");
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
//Purpose: Removes an item from the list.			//
//**************************************************//
template<typename DataType>
void List<DataType>::remove()throw(logic_error){
	if(isEmpty())
		throw(logic_error("Error in Remove()\n"));
	else{
		dataItems[cursor]=NULL;
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
//Parameters: DataType newDataItem					//
//Purpose: Replaces the item at cursor with newData-//
//		   Item.									//
//**************************************************//
template<typename DataType>
void List<DataType>::replace(const DataType& newDataItem)throw(logic_error){
	dataItems[cursor]= newDataItem;
}

//**************************************************//
//Function Name: Clear								//
//Return Type: Void									//
//Parameters: [None]								//
//Purpose: Clears the list							//
//**************************************************//
template<typename DataType>
void List<DataType>::clear(){
	for(int i=0; i<size; ++i)
		dataItems[i]=NULL;
	size=0;
	cursor=0;
}

//**************************************************//
//Function Name: isEmpty							//
//Return Type: Bool									//
//Parameters: [None]								//
//Purpose: Checks to see if the list is empty.      //
//		   Returns a bool value.					//
//**************************************************//
template<typename DataType>
bool List<DataType>::isEmpty()const{
	bool empty=true;
	for(int i=0; i<maxSize; ++i)
		if(dataItems[i]!=NULL)
			empty=false;
	return empty;
}

//**************************************************//
//Function Name: isFull								//
//Return Type: Bool									//
//Parameters: [None]								//
//Purpose: Checks to see if the list is full.       //
//		   Returns a bool value.					//
//**************************************************//
template<typename DataType>
bool List<DataType>::isFull()const{
	bool full=false;
	if(size==maxSize)
		full=true;
	return full;
}

//**************************************************//
//Function Name: GoToBeginning						//
//Return Type: Void									//
//Parameters: [None]								//
//Purpose: Sets cursor to beginning of the list.	//
//**************************************************//
template<typename DataType>
void List<DataType>::gotoBeginning()throw(logic_error){
	cursor=0;
}

//**************************************************//
//Function Name: GoToEnd							//
//Return Type: Void									//
//Parameters: [None]								//
//Purpose: Sets cursor to the end of the list.		//
//**************************************************//
template<typename DataType>
void List<DataType>::gotoEnd()throw(logic_error){
	cursor=size-1;
}

//**************************************************//
//Function Name: GoToNext							//
//Return Type: Bool									//
//Parameters: [None]								//
//Purpose: Increments the cursor.					//
//**************************************************//
template<typename DataType>
bool List<DataType>::gotoNext()throw(logic_error){
	if(cursor==size-1)
		return false;
	if(cursor+1!=size)
		++cursor;
	return true;
}

//**************************************************//
//Function Name: GoToPrior							//
//Return Type: Bool									//
//Parameters: [None]								//
//Purpose: Decrements the cursor.					//
//**************************************************//
template<typename DataType>
bool List<DataType>::gotoPrior()throw(logic_error){
	if(cursor==0)
		return false;
	else
		--cursor;
	return true;
}

//**************************************************//
//Function Name: GetCursor							//
//Return Type: DataType									//
//Parameters: [None]								//
//Purpose: Returns the cursor.						//
//**************************************************//
template<typename DataType>
DataType List<DataType>::getCursor()const throw(logic_error){
	return dataItems[cursor];
}

//**************************************************//
//Function Name: ShowStructure						//
//Return Type: Void									//
//Parameters: [None]								//
//Purpose: Prints the list.							//
//**************************************************//
template <typename DataType>
void List<DataType>:: showStructure () const

// outputs the data items in a list. if the list is empty, outputs
// "empty list". this operation is intended for testing/debugging
// purposes only.

{
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
#ifdef ORDEREDLIST_CPP
				.getKey()
#endif
				;
				cout << "]";
				cout << "\t";
			}
			else
				cout << dataItems[j] 
#ifdef ORDEREDLIST_CPP
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
//Parameters: int n									//
//Purpose: Lets the user move the cursor directly to//
//		   n.										//
//**************************************************//
template<typename DataType>
void List<DataType>::moveToNth(int n)throw(logic_error){
	DataType temp;
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
//Parameters: DataType searchDataItem				//
//Purpose: Lets the user search the list for a data //
//		   item.									//
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