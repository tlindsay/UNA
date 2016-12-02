//**********************************************************************//
//HashTable.cpp															//
//Due Date= 10-18-2011													//
//Class: CS 355															//
//Name: Chad,Patrick,and Alla											//
//																		//
//**********************************************************************//
using namespace std;
#include "BSTree.h"
#include "HashTable.h"
#include <cmath>

//********************************************************
//NOTE: This file uses a Binary Search Tree class created
// for Lab 9. See Lab 9 for documentation of said class.
//********************************************************

//class Identifier{
//	string ident;
//public:
//	void setKey(string newIdent)
//	{ident=newIdent;}
//	string getKey()const{
//		return ident;
//	}
//	static unsigned int hash(const string& key){
//		char first;
//		first=key[0];
//		return first;
//	}
//};

//**********************************************************************//
//Function Name: Default Constructor									//
//Return Type: HashTable												//
//Parameters: Int tempSize												//
//Purpose: Creates an empty Hash Table with size of tempSize.			//
//**********************************************************************//
template<typename DataType, typename KeyType>
HashTable <DataType, KeyType>:: HashTable(int tempSize){

	dataTable= new BSTree <DataType,KeyType> [tempSize];
	tableSize= tempSize;

}

//**********************************************************************//
//Function Name: Copy Constructor										//
//Return Type: HashTable												//
//Parameters: HashTable& other											//
//Purpose: Creates a new HashTable that is a copy of Other.				//
//**********************************************************************//
template<typename DataType, typename KeyType>
HashTable <DataType, KeyType>:: HashTable(const HashTable& other){
	
	tableSize= other.tableSize;
	dataTable= new BSTree <DataType, KeyType> [tableSize];

	for(int i=0; i < tableSize; i++)
		dataTable[i]= *other.dataTable[i];

	return  *this;

}

//**********************************************************************//
//Function Name: Overloaded Assignment Operator (Operator =)			//
//Return Type: HashTable&												//
//Parameters: HashTable& other											//
//Purpose: Sets calling HashTable equal to Other.						//
//**********************************************************************//
template<typename DataType, typename KeyType>
HashTable <DataType,KeyType>& HashTable <DataType,KeyType>::operator=(const HashTable& other){

	if (this == &other)
		return *this;
	else
	{
		tableSize= other.tableSize;
		delete [] dataTable;//deletes existing data
		dataTable= new BSTree <DataType, KeyType> [tableSize];

		for(int i=0; i < tableSize; i++)
			dataTable[i]= *other.dataTable[i];
		return  *this;
	}




	return *this;
}

//**********************************************************************//
//Function Name: Destructor												//
//Return Type: HashTable												//
//Parameters: [None]													//
//Purpose: Deletes all items in the table.								//
//**********************************************************************//
template<typename DataType, typename KeyType>
HashTable <DataType, KeyType>:: ~HashTable () { delete [] dataTable; }


//**********************************************************************//
//Function Name: Insert													//
//Return Type: Void														//
//Parameters: //
//Purpose: //
//**********************************************************************//
template<typename DataType, typename KeyType>
void HashTable <DataType, KeyType>::insert(const DataType& newDataItem){

	int HashSpot;

	HashSpot= newDataItem.hash( newDataItem.getKey() );

	HashSpot= HashSpot % tableSize;

	dataTable[HashSpot].insert(newDataItem);

}





//**********************************************************************//
//Function Name: Remove													//
//Return Type:	Bool													//
//Parameters: KeyType& deleteKey										//
//Purpose: Searches the hash table for the dataItem with key deleteKey. //
//		   If found, deletes item and returns true. Else, returns false.//
//**********************************************************************//
template<typename DataType, typename KeyType>
bool HashTable <DataType, KeyType>::remove(const KeyType& deleteKey){
	bool result= false;
	for( int i=0; i<tableSize; i++)
	{
		if(dataTable[i].remove(deleteKey))
			result= true;
	}
	return result;
}


//**************************************************************************//
//Function Name: Retrieve													//
//Return Type: Bool															//
//Parameters: KeyType& searchKey, DataType& returnItem						//
//Purpose: Searches the table for dataItem with key searchKey. If found,    //
//		   passes back via returnItem and returns true. Else, returns false.//
//**************************************************************************//
template<typename DataType, typename KeyType>
bool HashTable <DataType, KeyType>::retrieve(const KeyType& searchKey, DataType& returnItem) const{
	int hashValue;
	hashValue= returnItem.hash(searchKey); //this will help make retrieve O(1)
	hashValue= hashValue % tableSize;
	
	if (! dataTable[hashValue].isEmpty() )
	{
		if ( dataTable[hashValue].retrieve(searchKey, returnItem) )
			return true;
		else
			return false;
	}
	else // dataTable[i] is EMPTY
		return false;
	
}

//**********************************************************************//
//Function Name: Clear													//
//Return Type: Void														//
//Parameters: [None]													//
//Purpose: Clears the calling Table.									//
//**********************************************************************//
template<typename DataType, typename KeyType>
void HashTable <DataType, KeyType>::clear(){
	for( int i=0; i < tableSize; i++)
		dataTable[i].clear();
}


//**********************************************************************//
//Function Name: isEmpty												//
//Return Type: Bool														//
//Parameters: [None]													//
//Purpose: Checks to see if Table is empty.								//
//**********************************************************************//
template<typename DataType, typename KeyType>
bool HashTable <DataType, KeyType>::isEmpty() const{

	for (int i=0; i < tableSize; i++)
	{
		if (! dataTable[i].isEmpty() )
			return false;
	}
	return true;


}

//**********************************************************************//
//Function Name: PerfectHash											//
//Return Type: Void														//
//Parameters: Identifier newDataItem									//
//Purpose: Perfect Hashing insert (O(1)) for Programming Ex. 2. To be   //
//		   used with Perfect.cpp										//
//**********************************************************************//
template<typename DataType, typename KeyType>
void HashTable <DataType, KeyType>::perfectHash(const Identifier newDataItem){
	int HashSpot=newDataItem.hash(newDataItem.getKey());
	HashSpot= HashSpot % tableSize;
	dataTable[HashSpot].insert(newDataItem);
}

//**********************************************************************//
//Function Name: ShowStructure											//
//Return Type: Void														//
//Parameters: [None]													//
//Purpose: Prints the table graphically. For testing purposes only.     //
//**********************************************************************//
template<typename DataType, typename KeyType>
void HashTable<DataType, KeyType>::showStructure() const {
    for (int i = 0; i < tableSize; ++i)
	{
		cout << i << ": ";
		dataTable[i].writeKeys();
    }
}

//**********************************************************************//
//Function Name: Standard Deviation										//
//Return Type: Double													//
//Parameters: [None]													//
//Purpose: Calculates the Standard Deviation of the HashTable.			//
//**********************************************************************//
template<typename DataType, typename KeyType>
double HashTable<DataType, KeyType>::standardDeviation() const{
	double standDev=0; //standard Deviation of HashTable
	double slotCount[tableSize]; //number of data items per table entry
	double slotCompare[tableSize]; //(number of items - average number of items)^2 per table entry (used for final calculation)
	double averageKeys=0; //average number of keys chained off each table location
	double	totalDataItems=0; //total number of keys
	double sigma=0; //sum of all slots in slotCompare[]

	//Step One
	//Calculate and save the average -or mean- number of data items per table entry.

	for(int i=0; i<tableSize; i++){
		slotCount[i]=dataTable[i].getCount();
		totalDataItems+=slotCount[i];
	}
	averageKeys=totalDataItems/tableSize;
	
	//Step Two
	//For each table entry, calculate and save (number of items - mean number of items)^2.

	for(int i=0; i<tableSize; i++){
		slotCompare[i]=(slotCount[i]-averageKeys);
		slotCompare[i]*=slotCompare[i];
	}
	
	//Step Three
	//Compute the sum of all the values colculated in Step 2.

	for(int i=0; i<tableSize; i++)
		sigma+=slotCompare[i];
	
	//Step Four
	//Divide the result from Step 3 by n-1, where n is the number of hash table entries.

	standDev=sigma/(totalDataItems-1);

	//Step Five
	//Calculate the square root of the result obtained in Step 4. This is the standard deviation.

	standDev= sqrt(standDev); //sqrt=square root function as defined in cmath
	return standDev;
}
