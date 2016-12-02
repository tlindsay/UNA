//
//  OrderedList.cpp
//  Project 4-OrderedList
//
//  Created by Patrick Lindsay on 10/3/11.
//  Copyright 2011 University of North Alabama. All rights reserved.
//
#ifndef _ORDEREDLIST_CPP
#define _ORDEREDLIST_CPP

#include "OrderedList.h"

//**************************************************//
//Function Name: Default Constructor				//
//Return Type: Templated OrderedList				//
//Parameters: int MaxNumber							//
//Purpose: Creates an empty, templated OrderedList	//
//		   with a maxSize of maxNumber.				//
//**************************************************//
template<typename DataType, typename KeyType>
OrderedList<DataType,KeyType>::OrderedList(int maxNumber):List<DataType>(maxNumber){}

//**************************************************//
//Function Name: Insert								//
//Return Type: Void									//
//Parameters: DataType& newDataItem					//
//Purpose: Inserts an object of type, DataType, by	//
//		   reference, into the list, ordered by the //
//		   item's key.								//
//**************************************************//
template<typename DataType, typename KeyType>
void OrderedList<DataType,KeyType>::insert(DataType const &newDataItem)throw(logic_error){
	if(isFull())
		throw logic_error("List must not be full.");
	else if(isEmpty()){
		dataItems[cursor]=newDataItem;
		++size;
	}//else if empty list)
	else{
		int found=NULL;
		if(binarySearch(newDataItem.getKey(),found)){
			dataItems[found]=newDataItem;
			cursor=found;
		}
		else{
			for(int i=size;i>found;i--)
				dataItems[i]=dataItems[i-1];
			dataItems[found+1]=newDataItem;
			cursor=found+1;
			size++;
		}
	}
}

//**************************************************//
//Function Name: Replace							//
//Return Type: Void									//
//Parameters: DataType& newDataItem					//
//Purpose: Replaces an item at cursor with			//
//		   newDataItem, keeping the list ordered.	//
//**************************************************//
template<typename DataType, typename KeyType>
void OrderedList<DataType,KeyType>::replace(const DataType &newDataItem) throw(logic_error){
	if(isEmpty()==false){
		remove();
		insert(newDataItem);
	}
}

//************************************************************//
//Function Name: Retrieve									  //
//Return Type: Bool											  //
//Parameters: KeyType& searchKey, DataType& searchDataItem	  //
//Purpose: Searches for searchKey. If found, moves cursor	  //
//		   to searchKey and returns true. Else, returns false.//
//************************************************************//
template<typename DataType, typename KeyType>
bool OrderedList<DataType,KeyType>::retrieve(const KeyType& searchKey, DataType &searchDataItem){
	bool success=false;
	for(int i=0; i<size; ++i)
		if(searchKey==dataItems[i].getKey()){
			success=true;
			searchDataItem=dataItems[i];
			cursor=i;
		}
	return success;
}

//**************************************************//
//Function Name: ShowStructure						//
//Return Type: Void									//
//Parameters: [None]								//
//Purpose: Prints List Keys and DataItems. Inherited//
//		   from ListArray Class.					//
//**************************************************//
template<typename DataType, typename KeyType>
void OrderedList<DataType, KeyType>::showStructure()const{
	List<DataType>::showStructure();
}

//**********************************************************************//
//Function Name: BinarySearch											//
//Return Type: Bool														//
//Parameters: KeyType SearchKey, Int& index								//
//Purpose: Binary search routine. Searches a list for the data item with//
// key searchKey. If the data item is found, then returns true with		//
// index returning the array index of the entry containing searchKey.	//
// Otherwise, returns false with index returning the array index of the	//
// entry containing the largest key that is smaller than searchKey		//
// (or -1 if there is no such key).										//
//**********************************************************************//
template < typename DataType, typename KeyType >
bool OrderedList<DataType,KeyType>:: binarySearch ( KeyType searchKey, int &index ){
    int low  = 0,           // Low index of current search range
	high = size - 1;    // High index of current search range
    bool result;            // Result returned
	
    while ( low <= high )
    {
        index = ( low + high ) / 2;               // Compute midpoint
        if ( searchKey < dataItems[index].getKey() )
			high = index - 1;                      // Search lower half
        else if ( searchKey > dataItems[index].getKey() )
			low = index + 1;                       // Search upper half
        else
			break;                                 // searchKey found
    }
	
    if ( low <= high )
		result = true;       // searchKey found
    else
    {
		index = high;        // searchKey not found, adjust index
		result = false;
    }
	
    return result;
}

//**************************************************//
//Function Name: Merge								//
//Return Type: Void									//
//Parameters: OrderedList& other					//
//Purpose: Adds items of one list into another one.	//
//**************************************************//
template<typename DataType, typename KeyType>
void OrderedList<DataType, KeyType>::merge(const OrderedList& other)throw	(logic_error){			
	if((maxSize<size+other.size)||isFull()==true)
		throw logic_error("");
	else{
		bool alreadyThere;
		for(int i=0; i<other.size; ++i){
			alreadyThere=false;
			for(int j=0; j<size; ++j){
				if (other.dataItems[i].getKey()==dataItems[j].getKey())
					alreadyThere=true;
			}
			if(alreadyThere==false)
				insert(other.dataItems[i]);
		}
	}
}

//**************************************************//
//Function Name: isSubset							//
//Return Type: Bool									//
//Parameters: OrderedList& other					//
//Purpose: Checks to see if other is a subset of 	//
//		   calling list.							//
//**************************************************//
template<typename DataType, typename KeyType>
bool OrderedList<DataType, KeyType>::isSubset(const OrderedList &other){
	bool subset=true;
	gotoBeginning();
	if(size>=other.size)
		while(cursor<size){
			if((other.dataItems[cursor].getKey()!=dataItems[cursor].getKey())&&other.dataItems[cursor].getKey()!=NULL)
				subset=false;
			++cursor;
		}
	return subset;
}

#endif
