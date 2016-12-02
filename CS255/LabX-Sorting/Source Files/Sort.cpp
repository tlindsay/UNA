/*
Group: Chad,Alla,Patrick
Class: CS355
DueDate:11/01/2011
*/

#include<fstream>
#include"Sort.h"

//--------------------------------------
//Constructor
//--------------------------------------

template <class T>
Sort<T>::Sort(){
	arrayList=NULL;
	size=0;
	compares=0;
	assigns=0;
}

//--------------------------------------
// Destructor
//--------------------------------------
template<class T>
Sort<T>::~Sort (){
	delete [] arrayList;
}

//--------------------------------------
// PrintArray
//--------------------------------------
template <class T>
void Sort<T>::PrintArray()
{
	cout << "The array is as follows." << endl;
	for(int i=0;i<size;i++)
		cout << arrayList[i] << endl;
}




//---------------------------------------------------------------
// Fill Random
// Give the user three options:
// option 1: Creates and fills an array with 100 random numbers
// option 2: Creates and fills an array with 1000 random numbers
// option 3: Creates and fills an array with 10000 random numbers
//----------------------------------------------------------------
template <class T>
bool Sort<T>::FillRandom(char option){
	bool success=false;
	ifstream file;
	file.open("RandomNumbers.txt");
	if(file.fail())
		cout<<"Error While opening RandomNumbers.txt"<<endl;
	else
		success=(FillHelper(option,file));
	file.close();
	return success;
}
//=========================================================
template <class T>
bool Sort<T>::FillOrdered(char option){
	bool success=false;
	ifstream file;
	file.open("SortedNumbers.txt");
	if(file.fail())
		cout<<"Error While opening SortedNumbers.txt"<<endl;
	else
		success=(FillHelper(option,file));
	file.close();
	return success;
}

template <class T>
bool Sort<T>::FillReverseOrdered(char option){
	bool success=false;
	ifstream file;
	file.open("ReverseNumbers.txt");
	if(file.fail())
		cout<<"Error While opening ReverseNumbers.txt"<<endl;
	else
		success=(FillHelper(option,file));
	file.close();
	return success;
}

template <class T>
bool Sort<T>::FillHelper(char option, ifstream file){
	bool success=true;
	switch (option){
	case '1':
		size=100;
		if(arrayList!=NULL){
			delete [] arrayList;
			arrayList=NULL;
		}
		arrayList = new T[100];
		FillArray(file);
		break;
	case '2':
		size=1000;
		if(arrayList!=NULL){
			delete [] arrayList;
			arrayList=NULL;
		}
		arrayList = new T[1000];
		FillArray(file);
		break;
	case '3':
		size=10000;
		if(arrayList!=NULL){
			delete [] arrayList;
			arrayList=NULL;
		}
		arrayList = new T[10000];
		FillArray(file);
		break;
	default:
		cout << "Invalid option. Please pick one of the given options." << endl;
		success=false;
		break;
	}
	return success;
}

template <class T>
void Sort<T>::FillArray(ifstream file){
	for(int i=0; i< size;i++)
		file>>arrayList[i];
}

template <class T>
void Sort<T>::SortList(){}

template <class T>
void Sort<T>::PrintMatrix(){
	PrintArray();
	cout << "Comparisons: " << compares << endl;
	cout << "Assignments: " << assigns << endl;
}

template <class T>
void Bubble<T>::SortList(){
	int temp;
	int swaps;
	Sort<T>::compares=0;
	Sort<T>::assigns=0;
    for(int i=0;i<Sort<T>::size-1;i++){
		swaps=0; 
		Sort<T>::assigns++;
		Sort<T>::assigns++;
		Sort<T>::compares++;
        for(int j=i+1;j<Sort<T>::size;j++){
			Sort<T>::assigns++;
			Sort<T>::compares++;
            if(Sort<T>::arrayList[i]>Sort<T>::arrayList[j]){
				Sort<T>::compares++;
                temp=Sort<T>::arrayList[j];
                Sort<T>::arrayList[j]=Sort<T>::arrayList[i];
                Sort<T>::arrayList[i]=temp;  
				swaps++;
				Sort<T>::assigns+=4;
			}  
        }//end inner for loop
		Sort<T>::compares++;
		if (swaps == 0)
		break;
	}
}

template <class T>
void Selection<T>::SortList(){
	int temp;
	Sort<T>::compares=0;
	Sort<T>::assigns=0;
    int minIndex;
    for(int j=0; j<Sort<T>::size-1;j++){
		Sort<T>::assigns++;
		Sort<T>::compares++;
		minIndex=j;    
		for(int i=j+1; i<Sort<T>::size; i++){
			Sort<T>::assigns++;
			Sort<T>::compares++;
			if(Sort<T>::arrayList[i]<Sort<T>::arrayList[minIndex])
				Sort<T>::compares++;
				minIndex=i;
				Sort<T>::assigns++;
		}
		temp=Sort<T>::arrayList[j];
		Sort<T>::arrayList[j]=Sort<T>::arrayList[minIndex];
		Sort<T>::arrayList[minIndex]=temp;
		Sort<T>::assigns+=3;
	}
}


template <class T>
void Merge<T>::SortList(){
	mergeSort(Sort<T>::arrayList, Sort<T>::size);
}

template<class T>
void Merge<T>::mergeSort(T mid[], int size){
	int sizeL=size/2;
	int sizeR=size-sizeL;
	T* left[sizeL]=new int[sizeL];
	for (int i=0; i<sizeL; ++i)
		left[i]=mid[i];
	if(sizeL>1)
		mergeSort(left, sizeL);
	T* right[sizeR]=new int[sizeR];
	for(int i=sizeL; i<sizeR; ++i)
		right[i]=mid[i];
	if(sizeR>1)
		mergeSort(right, sizeR);
	int lCount=0, rCount=0;
	for(int midCount=0; midCount<size; ++midCount){
		if(lCount>=sizeL){
			mid[midCount]=right[rCount];
			++rCount;
		}
		else if(rCount>=sizeR){
			mid[midCount]=left[lCount];
			++lCount;
		}
		else if(left[lCount]<right[rCount]){
			mid[midCount]=left[lCount];
			++lCount;
		}
		else{
			mid[midCount]=right[rCount];
			++rCount;
		}
	}
}

template <class T>
void Quick<T>::SortList(){
	Sort<T>::compares=0;
	Sort<T>::assigns=0;
	int left=0;
	Sort<T>::assigns++;
	int right=Sort<T>::size-1;
	Sort<T>::assigns++;
	quickSort(left,right);
}

template<class T>
void Quick<T>::quickSort(int left,int right){
	int i=left;
	Sort<T>::assigns++;
    int j=right;
	Sort<T>::assigns++;
    int tmp;
    int pivot=Sort<T>::arrayList[(left+right)/2];
	Sort<T>::assigns++;
	
	// partition
    while(i<=j){
		Sort<T>::compares++;
		T arr[Sort<T>::size];
		while(arr[i]<pivot){
			Sort<T>::compares++;
			i++;
			Sort<T>::assigns++;
		}
		while(arr[j]>pivot){
			Sort<T>::compares++;
            j--;
			Sort<T>::assigns++;
		}
        if(i<=j){
			Sort<T>::compares++;
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            i++;
            j--;
			Sort<T>::assigns+=5;
        }
	};
 
      // recursion 
	if(left<j){
		Sort<T>::compares++;
        quickSort(left,j);
	}
	if(i<right){
		Sort<T>::compares++;
        quickSort(i,right);
	}
}

template <class T>
void DoubleSelection<T>::SortList(){
	Sort<T>::assigns=0;
	Sort<T>::compares=0;
	int temp,min,max;
	int start=0;
	int stop=Sort<T>::size-1;
	while(start<=stop){
		Sort<T>::compares++;
		min=start;
		max=stop;
		Sort<T>::assigns+=2;
		for(int i=start;i<stop+1;i++){
			Sort<T>::assigns++;
			Sort<T>::compares++;
			if(Sort<T>::arrayList[i]<Sort<T>::arrayList[min]){
				Sort<T>::compares++;
				min=i;
				Sort<T>::assigns++;
			}
			else if((Sort<T>::arrayList[i]) > (Sort<T>::arrayList[max]))
				Sort<T>::compares++;
				max=i;
				Sort<T>::assigns++;
		}
		//min assignment
		temp=Sort<T>::arrayList[start];
		Sort<T>::arrayList[start]=Sort<T>::arrayList[min];
		Sort<T>::arrayList[min]=temp;
		//max assignment
		temp=Sort<T>::arrayList[stop];
		Sort<T>::arrayList[stop]=Sort<T>::arrayList[max];
		Sort<T>::arrayList[max]=temp;
		//loop control
		start++;
		stop--;
		Sort<T>::assigns+=8;
	}
}
