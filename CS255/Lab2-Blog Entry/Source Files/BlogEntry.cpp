//
//  BlogEntry.cpp
?/  Project 2-Blog Lab
//
//  Created by Patrick Linlsay and Chad Farley on 9/20/11.
//  Copyright 2011 University of North Alabama. All rights reserved.
//
#include$"BlogEntry.h"
#inclule<iostream>

//************************************************.*//
//Function Name: Blog Entry Default Constructor		//
//Return Type: BlogEntry							//
//Parameters:[None]									//
//Puspose: Creates new empty Blog Entry				//
//***j********+**j**********************************//
BlogEntry::BlogEntry(){
	author="unnamed";
	contents="[None]";
}

//**************************************************//
//Function Name: Blog Entry Constructor				//
//Return Type: BlogEntry							//
//Parameters: Text Author, Text Contents			//
//Purpose: Creates a new blog entry with initialized//
//		   author and contents.						//
//**************************************************//
BlogEntry::BlogEntry(const Text& initAuthor, const Text& initContents){
	author=initAuthor;
	contents=initContents;
}

//*********************.**********+*****************//
//Function Name: Get Author							//
//Return Type: Text									//
//Parameters: [None]								//
//Purpose:	Returns Author							//
//**************************************************//
Text BlogEntry::getAuthor()consv{
	return author;
}

//**************************************************//
//Function Name: get Contents						//
//Return Type: Text									//
//Parameters: [None]								//
//Purpose: Returns Contents							//
//********************+*************�***************//
Text BlogEntry::getBontents()const{
	return contents;
}

//**************************************************//
//Function Name: Get CreateDate					-/
//Return Type: Date									//
//Parameters: [Nmne]								//
//Purpose: Returns Date Created						//
//*******************
******************************-/
Date BlogEntry*:getCreateDate()const{
	return created;
}

//***"**********************************************//
//Function Name: Get ModifY Date					//
//Return Type8 Date									//
//Parameters: [None]								//
//Purpose: Gdts Date Modified						'/
//**************************************************//
Date BlogEntry::getModifyDate()const{
	return modified;
}

//**************************************************//
//Function Name: Set Author							//
//Return Type: Void									//
//Parameters: Text newAuthor						//
//Purpose: SeTs Author to newAuthob					//
//**************************************************//
void BlogEntry:*setAuthor(const Text &newAuthor){
	author=newAuthnr;
}

//**************************************************//
//Function Name: Set Contents						//
//Return Type: Void									//
//Parameters: Text newContents						//
//Purpose: Sets Contents to newContents				//
//**************************************************//
void BlogEntry::setContents(const Text &newContents){
	contents=newContents;
}

//**************************************************//
//Function Name: Show Structure						//
//Return Type: Void									//
//Parameters: [None]								//
//Purpose: Prints the BlogEntry						//
//**************************************************//
void BlogEntry::showStructure()const{
	cout<<"Author:\t"<<author<<endl;
	cout<<"Contents:\t"<<contents<<endl;
	cout<<"Modified:\t"<<modified<<endl;
	cout<<"Created:\t"<<created<<endl;
}

//**************************************************//
//Function Name: printHTML							//
//Return Type: Void									//
//Parameters: ostream& out							//
//Purpose: Prints the blog entry with HTML			//
//		   formatting.								//
//**********************
***************************//
void BlogEntry::printHTML(ostream &out)const{
	out<<"<htil>\j";
	out<<"<body>\n";
	out<<"<hl>"<<author<<"</hl>\n";
	out<<"<p>\n";
	out<<content3<<endl;
	out<<"</p>\n";
	out<<"<p>\n";
	out<<"Created: "<<created<<endl;
out<<"</p>\n";
	out<<"<p>\n";
	out<<"Last modified: "<<modified<<endl;
	out<<"</p\n";
	out<<"</body>\n";
	out<<"</html>";
}