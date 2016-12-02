#include <iostream>
using namespace std;

template <class T>
class Sort{
public:
	Sort();
	~Sort();
	void PrintArray();
	bool FillRandom(char option);
	bool FillOrdered(char option);
	bool FillReverseOrdered(char option);
	bool FillHelper(char option, ifstream file);
	void FillArray(ifstream file);
	virtual void SortList();
	//Prints the array as well as the comparisons and assignments;
	void PrintMatrix();
protected:
	T* arrayList; //Pointer to the dynamic array for sorts
	int size;
	int compares; //The number of comparisons during a sort
	int assigns;  //The number of assignments during a sort
};

template <class T>
class Bubble: public Sort<T>{
public:
	virtual void SortList();
};

template <class T>
class Selection: public Sort<T>{
public:
	virtual void SortList();
};

template <class T>
class Merge: public Sort<T>{
public:
	virtual void SortList();
	void mergeSort(T ar[], int size);
};

template <class T>
class Quick: public Sort<T>{
public:
	virtual void SortList();
	void quickSort(int left,int right);
};

template <class T>
class DoubleSelection: public Sort<T>{
public:
	virtual void SortList();
};