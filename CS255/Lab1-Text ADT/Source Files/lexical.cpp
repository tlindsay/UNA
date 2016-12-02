//
//  lexical.cpp
//  Project 1-Text Lab
//
//  Created by Patrick Lindsay on 9/14/11.
//  Copyright 2011 University of North Alabama. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Text.h"
using namespace std;

int main(){
	ifstream inFile;
	inFile.open("progsamp.dat");
	int counter=1;
	Text fileText;
	while(!inFile.eof()){
		inFile>>fileText;
		cout<<counter<<" : "<<fileText<<endl;
		++counter;
	}
	return 0;
}
