/*//
//  Packet.cpp
//  Project 4-OrderedList
//
//  Created by Patrick Lindsay on 10/4/11.
//  Copyright 2011 University of North Alabama. All rights reserved.
//

#include "Packet.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int packet::getKey()const{
	return position;
}

ostream & operator <<(ostream &output, const packet & pack){
	output<<pack.body;
	return output;
}

void packet::print()const{
	for(int i=0; i<6; ++i)
		cout<<body[i];
		cout<<endl;
}

int main(){
	ifstream inFile;
	packet next;
	OrderedList<packet, int> testList(10);
	inFile.open("message.dat");
	if(inFile.fail()){
		cout<<"You messed up your file name.\n";
		exit(1);
	}	
	do{
 #if !LAB3_TEST1
		next.position=inFile.get()-49;
 #endif
 #if LAB3_TEST1
		next.position=inFile.get();
 #endif
		for(int i=0; i<5; ++i)
			next.body[i]=inFile.get();
		inFile.get();
		testList.insert(next);
	}while(!inFile.eof());
	testList.showStructure();		
	for(int i=0; i<testList.size; ++i)
		cout<<testList.dataItems[i];
	cout<<endl;
}*/