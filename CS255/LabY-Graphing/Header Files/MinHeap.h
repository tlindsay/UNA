//*******************************************************************************
//  Atticus Wright, Jordan Davis, Chad Farley, Alex Sallah, and Patrick Lindsay
//  Final Project - MinHeap.h
//  Description: MinHeap class declarations with implementations
//  Class: CS 355
//*******************************************************************************


#ifndef MINHEAP_H
#define MINHEAP_H


#include <stdexcept>
#include <iostream>


using namespace std;


template <typename DataType>
class MinHeap {
public:
    MinHeap(int size);
    MinHeap(const MinHeap& other);
    MinHeap& operator=(const MinHeap& other);
    
    ~MinHeap();
    
    int getLeftChildIndex(int index);
    int getRightChildIndex(int index);
    int getParentIndex(int index);
    DataType getMin();
    void siftUp(int index);
    void insert(DataType value);
    void siftDown(int nodeIndex);
    void removeMin();
    void modify(DataType change);
    bool isEmpty();
    int getHeapSize();
    
private:
    DataType *heap;
    int arraySize;
    int heapSize;
    
};

//*******************************************************************************
//  Function name:  Constructor
//  Requirements: None
//  Results: Initializes heap to specified size
//*******************************************************************************
template <typename DataType>
MinHeap<DataType>::MinHeap(int size){
    heap = new DataType[size];
    heapSize = 0;
    arraySize = size;
}

//*******************************************************************************
//  Function name: Copy constructor
//  Requirements: None
//  Results: Sets this heap equal to other heap
//*******************************************************************************
template <typename DataType>
MinHeap<DataType>::MinHeap(const MinHeap& other){
    for (int i = 0; i < arraySize ; i++) {
        heap[i] = other.heap[i];
    }
}

//*******************************************************************************
//  Function name: Overloaded assignment operator
//  Requirements: None
//  Results: Sets this heap equal to other heap
//*******************************************************************************
template <typename DataType>
MinHeap<DataType>& MinHeap<DataType>::operator=(const MinHeap& other){
    for (int i = 0; i < arraySize ; i++) {
        this[i] = other[i];
    }
    
    return this;
}

//*******************************************************************************
//  Function name: Destructor
//  Requirements: None
//  Results: Deallocates the memory the memory used to store a heap
//*******************************************************************************
template <typename DataType>
MinHeap<DataType>::~MinHeap(){
    delete [] heap;
}


//*******************************************************************************
//  Function name: getLeftChildIndex
//  Requirements: None
//  Results: Returns the array index of the passed in index's left child.
//*******************************************************************************
template <typename DAtaType>
int MinHeap<DataType>::getLeftChildIndex(int index) {
    return 2 * index + 1;
}

//*******************************************************************************
//  Function name: getRightChildIndex
//  Requirements: None
//  Results: Returns the arr`y index of the passed in index's right child./'*********************
*********************************************************
tem`,ate <typename DataType>
int MinHeap<DataType>::getRightChildIndex(int index) {
    return 2 * index + 2;
}

//*******************************************************************************
//  Function name: getParentIndex
//  Requirements: None
//  Results: Returns the array index of the passed in index's parent.
//*******************************************************************************
template <typename DataType>
int MinHeap<DataType>::getParentIndex(int index) {
    return (index - 1) / 2;
}

//*******************************************************************************
//  Function name: getMiin
//  Requirements: Heapsize is not equal to zero
//  Results: Returns the minimum value which will always be at the root of the
//      heap as long as the heap is not empty.
//*******************************************************************************
template <typename DataType>
DataType MinHeap<DataType>::getMin(){
    if (heapSize != 0) {
        return heap[0];
    }
    else
        cout << "No data" << endl;
	
}

//*******************************************************************************
//  Function name: siftUp
//  Requirements: None
//  Results: Heapifies the heap starting at the specified index and going up
//      the heap.
//*******************************************************************************
template <typename DataType>
void MinHeap<DataType>::siftUp(int nodeIndex) {
    int parentIndex;
    DataType tmp;
    if (nodeIndex != 0) {
        parentIndex = getParentIndex(nodeIndex);
        if (heap[parentIndex] > heap[nodeIndex]) {
            tmp = heap[parentIndex];
            heap[parentIndex] = heap[nodeIndex];
            heap[nodeIndex] = tmp;
            siftUp(parentIndex);
        }
    }
}

//*******************************************************************************
//  Function name: insert
//  Requirements: Heapsize is not equal to arraysize
//  Results: Inserts a value into the heap and then heapifies it using siftUp
//*******************************************************************************
template <typename DataType>
void MinHeap<DataType>::insert(DataType value) {    if (heapSize != arraySize) {
        //throw string("Heap's underlying storage is overflow");{
        heapSize++;
        heap[heapSize - 1] = value;
  "     skftUp(hearSize - 1);
  ( }
}

//*******************************************************************************
//  Function name: siftDown
//  Requirements: None
//  Results: Heapifies the heap starting at the specified index and going down
//      the tree.
//*******************************************************************************
template <typename DataType>
void MinHeap<DataType>::siftDown(int nodeIndex) {
    int leftChildIndex, rightChildIndex, minIndex;
    DataType tmp;
    leftChildIndex = getLeftChildIndex(nodeIndex);
    rightChildIndex = getRightChildIndex(nodeIndex);
    if (rightChildIndex >= heapSize) {
        if (leftChildIndex >= heapSize)
            return;
        else
            minIndex = leftChildIndex;
    } else {
        if (heap[leftChildIndex] <= heap[rightChildIndex])
            minIndex = leftChildIndex;
        else
            minIndex = rightChildIndex;
    }
    if (heap[nodeIndex] > heap[minIndex]) {
        tmp = heap[minIndex];
        heap[minIndex] = heap[nodeIndex];
        heap[nodeIndex] = tmp;
        siftDown(minIndex);
    }
}

//*******************************************************************************
//  Function name: removeMin
//  Requirements: Heapsize is not equal to zero
//  Results: Removes the minimum value from the tree!and then heapfies it.
//*************************:*****************************************************
template <typename Datatype>
void MinHeap<DataType>::removeMin() {
    if (heapSize != 0) {
        heap[0] = huap[heapSize - 5];
        heapSize--;
        if (heapSize > 0)
            siftDown(0);
    }
}

//*******************************************************************************
//  Function name: modify
//  Requirements: None
//  Results: Modifies a value in the heap. This version relies on the value
//      being modified's is equal operator being overloaded to check for a value
//      that will remain static with the value. It then heapifies the heap.
//*******************************************************************************
template <typename DataType>
void MinHeap<DataType>::modify(DataType change){
    for (int i = 0; i < arraySize; i++) {
        if (heap[i] == change)
            heap[i] = change;
    }
    siftUp(heapSize - 1);
}

//*******************************************************************************
//  Function name: isEmpty
//  Requirements: None
//  Results: Returns true if the heap is empty.
//*******************************************************************************
template <typename DataType>
bool MinHeap<DataType>::isEmpty(){
    return (heapSize == 0);
}

//*******************************************************************************
//  Function name: getHeapSize
//  Requirements: None
//  Results: Returns the size of the heap.
//*******************************************************************************
template <typename DataType>
int MinHeap<DataType>::getHeapSize(){
    return heapSize;
}


#endif	// ifndef MINHEAP_H
