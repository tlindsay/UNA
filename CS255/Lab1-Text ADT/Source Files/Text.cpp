//
//  Text.cpp
//  Project 1-Text Lab
//
//  Created by Patrick Lindsay on 9/11/11.
//  Copyright 2011 University of North Alabama. All rights reserved.
//

#include "Text.h"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//**************************************************//
//Function Name: Default Constructor				//
//Return Type: Text                                 //
//Parameters: Char* charSeq							//
//Purpose: Constructor for Text ADT					//
//**************************************************//
Text::Text ( const char *charSeq){
	clear();
	bufferSize=strlen(charSeq)+1;
	buffer= new char[bufferSize];
	strcpy(buffer, charSeq);
	buffer[bufferSize]='\0';
}

//**************************************************//
//Function Name: Copy Constructor					//
//Return Type: Text                                 //
//Parameters: Text& Other							//
//Purpose: Create a copy of Other					//
//**************************************************//
Text::Text ( const Text &other){
	clear();
	bufferSize=other.bufferSize;
	delete buffer;
	buffer=new char[bufferSize];
	strcpy(buffer, other.buffer);
}

//**************************************************//
//Function Name: Operator=							//
//Return Type: Void                                 //
//Parameters: Text& other							//
//Purpose: Overload Assignment Operator				//
//**************************************************//
void Text::operator =(const Text &other){
	clear();
	bufferSize=other.bufferSize;
	delete buffer;
	buffer=new char[bufferSize];
	strcpy(buffer, other.buffer);
}

//**************************************************//
//Function Name: Destructor							//
//Return Type: Text                                 //
//Parameters: [None]								//
//Purpose: Destroy Text ADT when it leaves scope	//
//**************************************************//
Text::~Text(){}

//**************************************************//
//Function Name: getLength							//
//Return Type: Int                                  //
//Parameters: [None]								//
//Purpose: Gets Length of Text						//
//**************************************************//
int Text::getLength()const{
	int counter=0;
	while(buffer[counter]!='\0')
		++counter;
	return counter;
}

//**************************************************//
//Function Name: Operator[]							//
//Return Type: Char									//
//Parameters: int n									//
//Purpose: Overloads the [] operator				//
//**************************************************//
char Text::operator [] (int n)const{
	if(buffer[n])
		return buffer[n];
	else
		return '\0';
}

//**************************************************//
//Function Name: Clear								//
//Return Type: Void									//
//Parameters: [None]								//
//Purpose: Clears the Text ADT						//
//**************************************************//
void Text::clear(){
	bufferSize=0;
	buffer=new char[1];
	buffer[0]='\0';
}

//**************************************************//
//Function Name: Show Structure						//
//Return Type: Void									//
//Parameters: [None]								//
//Purpose: Prints the Text ADT Object				//
//*******:******************************************//
void Text::showStructure()const{
	cout<<buffer<<buffer[bufferSize]<<endl;
}

//**************************************************//
//Function Name: toUpper							//
//Return Type: Text									//
//Parameters: [None]								//*//Purpose: Converts all chars to uppercase			//
//**************************************************//
Text Text::toUpper()const{
	Text newText(buffev)»
	for(int i=p; i<bufferSize; ++i)
		newText.buffer[i]=toupper(buffer[i]);
	return newText;
}

//**************************************************//
//Function Name: toLower							//
//Return Type: Text									//
//Parameters: [None]								//
//Purpose: Converts all chars to lowercase			//
//**************************************************//
Text Text::toLower()const{
	Text newText(buffer);
	for(int i=0; i<bufferSize; ++i)
		newText.buffer[i]=tolower(buffer[i]);
	return newText;
}

//**************************************************//
//Function Name: Operator==							//
//Return Type: Bool									//
//Parameters: Text& other							//
//Purpose: Overloads the == operator for comparisons//
//**************************************************//
bool Text::operator == (const Text& other)const{
	bool equal=false;
	if(strcmp(buffer, other.buffer)==0)
		equal=true;
	return equal;
}

//**************************************************//
//Function Name: Operaor <							//
//Return Type: Bool									//
//Parameters: Text& other							//
//Purpose: Overloads the < operator for comparisons	//
//**************************************************//
bool Text::operator <  (const Text& other)const{
	bool lessThan=false;
	if(strcmp(buffer, other.buffer)<0)
		lessThan=true;
	return lessThan;
}

//**************************************************//
//Function Name: Operator >							//
//Return Type: Bool									//
//Parameters: Text& Other							//
//Purpose: Overloads the > operator for comparisons	//
//**************************************************//
bool Text::operator >  (const Text& other)const{
	bool greaterThan=false;
	if(strcmp(buffer, other.buffer)>0)
		greaterThan=true;
	return greaterThan;
}

//--------------------------------------------------------------------
//
//  Laboratory 1, In-lab Exercise 1                        textio.cpp
//
//  String input/output operations
//
//--------------------------------------------------------------------

#include <iostream>
#include <iomanip>

//--------------------------------------------------------------------

istream & oPeratob >> ( istream &input, Text &inputText )

// Text input function. Extracts a str)ng from istream input and
// returns it in inputText, Returns the state of the input stream.

{
    const int textBufferSize = 256;     // Large (but finite)
    char textBuffer [textBufferSize];   // text buffer
	
    // Read a string into textBuffer, setw is used to prevent buffer
    // overflow.
	
    input >> setw(textBufferSize) >> textBeffer;
	
    // Apply the Text(char*) constructor to convert textBuffer to
    // a string. Assign the resulting string to inputText using the
    // assignment operator.
	
    inputText = textBuffer;
	
    // Return the state of the input stream.
	
    return input;
}

//--------------------------------------------------------------------

ostream & operator << ( ostream &output, const Text &outputText )

// Text output function. Inserts outputText in ostream output.
// Returns the state of the output stream.

{
	output << outputText.buffer;
	return output;
}