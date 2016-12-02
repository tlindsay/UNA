// HashTable.h

#ifndef HASHTABLE_H
#define HASHTABLE_H


#include <stdexcept>
#include <iostream>

using namespace std;

#include "BSTree.cpp"

class Identifier{
	string ident;
public:
	void setKey(string newIdent)
	{ident=newIdent;}
	string getKey()const{
		return ident;
	}
	static unsigned int hash(const string& key){
		return key[0]+key[key.length()-1];
	}
};

template <typename DataType, typename KeyType>

class HashTable {
  public:
    HashTable(int initTableSize);
    HashTable(const HashTable& other);
    HashTable& operator=(const HashTable& other);

    ~HashTable();

    void insert(const DataType& newDataItem);
    bool remove(const KeyType& deleteKey);
    bool retrieve(const KeyType& searchKey, DataType& returnItem) const;
    void clear();

    bool isEmpty() const;

    void showStructure() const;

    double standardDeviation() const;
	
	void perfectHash(const Identifier);

  private:
    void copyTable(const HashTable& source);

    int tableSize;
    BSTree<DataType, KeyType>  *dataTable;
};

#endif	// ifndef HASHTABLE_H
