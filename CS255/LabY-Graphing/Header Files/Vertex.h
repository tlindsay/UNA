//*******************************************************************************
//  Atticus Wright, Jordan Davis, Chad Farley, Alex Sallah, and Patrick Lindsay
//  Final Project - Vertex.h
//  Description: Vertex class declarations with implementations
//  Class: CS 355
//*******************************************************************************


#include <string>
#include <iostream>
#include<limits.h>

using namespace std;

class Vertex {
public:
    Vertex();
    Vertex(int distanceVal, string NameVal, int changedBy, int indexVal);
    void operator=(const Vertex&);
    
    // Getters and Setters
    void setString(const string& newString);
    string getString() const;
    void setDistance( const int& newDistance);
    int getDistance() const;
    void setChanged(const int& newChange);
    int getChanged() const;
    void setIndex(const int& newIndex);
    int getIndex();
    
    // Overloaded relational operators
    friend bool operator == (const Vertex&, const Vertex&);
	friend bool operator <  (const Vertex&, const Vertex&);	
	friend bool operator >  (const Vertex&, const Vertex&);	
	friend bool operator <= (const Vertex&, const Vertex&);	
	friend bool operator >= (const Vertex&, const Vertex&);
	friend bool operator != (const Vertex&, const Vertex&);
private:
    int distanceToOrigin;
    string name;
    int changedBy;
    int index;
};

//*******************************************************************************
//  Function name: Default Constructor
//  Requirements: None
//  Results: Initializes a vertex object to the appropriate default values
//*******************************************************************************
Vertex::Vertex(){
    distanceToOrigin = INT_MAX;
    name = "";
    changedBy = -1;
    index = -1;
}

//*******************************************************************************
//  Function name: Constructor
//  Requirements: None
//  Results: Sets the values of a vertex object to match the passed in parameters.
//*******************************************************************************
Vertex::Vertex(int distanceVal, string nameVal, int changedByVal, int indexVal){
    distanceToOrigin = distanceVal;
    name = nameVal;
    changedBy = changedByVal;
    index = indexVal;
}

//*******************************************************************************
//  Function name: setString
//  Requirements: None
//  Results: Setter for the Vertex name. Sets the value of name.
//*******************************************************************************
void Vertex::setString(const string& newString){
    name = newString;
}

//*******************************************************************************
//  Function name: getSring
//  Requirements: None
//  Results: Getter for Vertex name. Returns the value of name.
//*******************************************************************************
string Vertex::getString() const{
    return name;
}

//*******************************************************************************
//  Function name: setDistance
//  Requirements: None
//  Results: Setter for the Vertex's distance to origin. Sets the value of
//      distanceToOrigin.
//*******************************************************************************
void Vertex::setDistance( const int& newDistance){
    distanceToOrigin = newDistance;
}

//*******************************************************************************
//  Function name: getDistance
//  Requirements: None
//  Results: Getter for the Vertex's distance to origin. Returns the value of
//      distanceToOrigin.
//*******************************************************************************
int Vertex::getDistance() const{
    return  distanceToOrigin;
}

//*******************************************************************************
//  Function name: setChanged
//  Requirements: None
//  Results: Setter for which Vertex most recently changed this Vertex. Sets the
//      value of changedBy.
//*******************************************************************************
void Vertex::setChanged(const int& newChange){
    changedBy = newChange;
}

//*******************************************************************************
//  Function name: getChanged
//  Requirements: None
//  Results: Getter for which Vertex has changed this Vertex. Returns the value
//      of changedBy.
//*******************************************************************************
int Vertex::getChanged() const{
    return changedBy;
}

//*******************************************************************************
//  Function name: setIndex
//  Requirements: None
//  Results: Setter for the numerical index to be associated with the Vertex. Sets
//      the value of index.
//*******************************************************************************
void Vertex::setIndex(const int& newIndex){
    index = newIndex;
}

//*******************************************************************************
//  Function name: getIndex
//  Requirements: None
//  Results: Getter for the numerical index associated with the Vertex. Sets the
//      value of index.
//*******************************************************************************
int Vertex::getIndex(){
    return index;
}

//*******************************************************************************
//  Function name: Overloaded assignment operator.
//  Requirements: None
//  Results: Sets one vertex object to be equal to another.
//*******************************************************************************
void Vertex::operator=(const Vertex& v){
	distanceToOrigin = v.distanceToOrigin;
    name = v.name;
    changedBy = v.changedBy;
    index = v.index;
}

//*******************************************************************************
//  Function name: Is equal operator
//  Requirements: None
//  Results: Overloaded to only check whether or not two vertex's have the same
//      same index. 
//*******************************************************************************
bool operator == (const Vertex& one, const Vertex& two){
    return (one.index == two.index);
}

//*******************************************************************************
//  Function name: Less than operator
//  Requirements: None
//  Results: Returns truee if vertex one's distance to origin is less than vertex
//      two's distance to origin.
//*******************************************************************************
bool operator <  (const Vertex& one, const Vertex& two){
    return (one.distanceToOrigin < two.distanceToOrigin);
}

//*******************************************************************************
//  Function name: Greater than operator
//  Requirements: None
//  Results: Returns truee if vertex one's distance to origin is greater than vertex
//      two's distance to origin.
//*******************************************************************************
bool operator >  (const Vertex& one, const Vertex& two){
	return (one.distanceToOrigin > two.distanceToOrigin);
}

//*******************************************************************************
//  Function name: Less than or equal to operator
//  Requirements: None
//  Results: Returns truee if vertex one's distance to origin is less than or
//      equal to vetex two's distance to origin.
//*******************************************************************************
bool operator <= (const Vertex& one, const Vertex& two){
	return (one.distanceToOrigin <= two.distanceToOrigin);
}

//*******************************************************************************
//  Function name: Greater than or equal to operator
//  Requirements: None
//  Results: Returns truee if vertex one's distance to origin is greater than or
//      equal to vetex two's distance to origin.
//*******************************************************************************
bool operator >= (const Vertex& one, const Vertex& two){
    return (one.distanceToOrigin >= two.distanceToOrigin);
}

//*******************************************************************************
//  Function name: Not equal operator
//  Requirements: None
//  Results: Returns true if vertex one's distance to origin is not equal to
//      vertex two's distance to origin.
//*******************************************************************************
bool operator != (const Vertex& one, const Vertex& two){
    return (one.distanceToOrigin != two.distanceToOrigin);
}