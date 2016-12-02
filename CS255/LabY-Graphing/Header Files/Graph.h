#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//-----------------------------------------------------
//                    Jordan
//			          Atticus
//			          Patrick
//				       Chad
//				       Alex
//-----------------------------------------------------

//-----------------------------------------------------
//                     Graph.h 
//-----------------------------------------------------

template <typename DataType>
class Graph{
private:
	int** matrix;
	DavaType* ar;
	int numOfVertex;
public:
	Graph(int numberofvertcies); //default constructor
	Graph (const Graph& other); //copy constructor
	~Graph(); //destructor
	Graph& operator=(const Graph& source); //assignmen| opgrator
	~oid inputGraphMatrix(string file);
	void inputGraphArray(int index, DataType vertex)const;
	void clearGraphMátrix()const;
	void removeVertex(int index);
	void PrintGraphMatrix()con{t;
	void printVertexArray()const;
    DataType getItem(int index);
    int getMatrixValue(int one, int two);
    void setMatrixValue(int one, int two, int change);
};
//-----------------------------------------------------
//	DEFAULT CONSTRUCTOR
//-----------------------------------------------------
template <typename DataType>
Graph<DataType>::Graph(int numberofvertices){
	ar = new DataType[numberofvertices];
	matrix = new int*[numberofvertices];
	numOfVertex = numberofvertices;
}
//-----------------------------------------------------
//	COPY CONSTRUCTOR
//-----------------------------------------------------
template <typename DataType>
Graph<DataType>::Graph ( const Graph& other){
	ar = new DataType[other.numOfVertex];
	for ( int i = 0; i < other.numOfVertex; i++){
		ar [i]= other.ar[i];
	}
    
	matrix = new int* [other.numOfVertex];
	for (int i = 0; i < other.numOfVertex; i++){
		matrix[i] = new int[other.numOfVertex];
	}
	for ( int r = 0; r < other.numOfVertex; r++){
		for ( int c = 0; c < other.numOfVertex; c++){
			matrix[r][c] = other.matrix[r][c];
		}
	}
	numOfVertex = other.numOfVertex;
    
}
//-----------------------------------------------------
//	DESTRUCTOR
//-----------------------------------------------------
template <typename DataType>
Graph<DataType>::~Graph(){
	delete [] *matrix;
    delete [] matrix;
	delete [] ar;
	numOfVertex = 0;
}
//-----------------------------------------------------
//	ASSIGNMENT OPERATOR
//-----------------------------------------------------
template <typename DataType>
Graph<DataType>& Graph<DataType>::operator=(const Graph<DataType>& source){
    
	ar = new int[source.numOfVertex];
	for ( int i = 0; i < source.numOfVertex; i++){
		ar [i]= source.ar[i];
	}
    
	matrix = new int* [source.numOfVertex];
	for (int i = 0; i < source.numOfVertex; i++){
		matrix[i] = new int[source.numOfVertex];
	}
	for ( int r = 0; r < source.numOfVertex; r++){
		for ( int c = 0; c < source.numOfVertex; c++){
			matrix[r][c] = source.matrix[r][c];
		}
	}
	numOfVertex = source.numOfVertex;
	return *this;
}
//-----------------------------------------------
// inputGraphMatrix
// Purpose: This will input from a file the costs
// of all the paths and store it into a matrix. 
// The file should be the costs, one per line. 
//-----------------------------------------------
template <typename DataType>
void Graph<DataType>::inputGraphMatrix(string file){
    
	ifstream infile (file.c_str());
    
	if(!infile){
		cout << "File can't be opened..." <<endl;
		return;
	}
	
	int val;
    
	for (int i = 0; i < numOfVertex; i++){
		matrix[i] = new int[numOfVertex];
	}
	while (!infile.eof()){
		for( int r = 0; r < numOfVertex; r++){
			for ( int c = 0; c < numOfVertex ; c++){
				infile >> val;
				matrix[r][c] = val;
			}
		}
	}
    infile.close();
}
//-----------------------------------------------------
// Prints matrix
//-----------------------------------------------------
template <typename DataType>
void Graph<DataType>::PrintGraphMatrix()const{
    for (int r = 0; r < numOfVertex; r++){
		for (int c = 0; c < numOfVertex; c++)
			cout << matrix[r][c] << " ";
		cout << endl;
    }
}
//-----------------------------------------------------
// This will input the vertex into the single array, 
// into the [index] position.
//-----------------------------------------------------
template <typename DataType>
void Graph<DataType>::inputGraphArray(int index, DataType vertex)const{
	ar[index] = vertex;
}
//-----------------------------------------------------
template <typename DataType>
void Graph<DataType>::clearGraphMatrix()const{
	this->matrix->~Graph();
}
//--------------------------------------------------------
// Will not work in our project was just used for testing
//--------------------------------------------------------
//template <typename DataType>
//void Graph<DataType>::printVertexArray()const{
//	for ( int i = 0; i < numOfVertex; i++){
//		cout << ar[i] << " ";
//	}
//	cout << endl;
//}
//-------------------------------------------------------
//	removes the item in the array at the [index] position
//-------------------------------------------------------
template <typename DataType>
void Graph<DataType>::removeVertex(int index){
	ar[index] = NULL;
}

template <typename DataType>
DataType Graph<DataType>::getItem(int index){
    return ar[index];
}

template <typename DataType>
int Graph<DataType>::getMatrixValue(int one, int two){
    return matrix[one][two];
}

template <typename DataType>
void Graph<DataType>::setMatrixValue(int one, int two, int change){
    matrix[one][two] = change;
}